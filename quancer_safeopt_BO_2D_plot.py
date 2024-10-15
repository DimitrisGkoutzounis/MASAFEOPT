import subprocess
import time
import shutil
import matplotlib.pyplot as plt
from scipy.io import loadmat
import numpy as np
import os  # For directory operations
import pickle  # For saving agent objects

import safeopt
import GPy

################ PHASE 1 ################

def sent_command(target_uri, modelName, gain_arg, std_args):
    """
    Send command to the target.
    """
    sys_run = f'quarc_run -l -t {target_uri} {modelName}.rt-linux_rt_armv7{gain_arg} {std_args}'
    subprocess.call(sys_run, shell=True)
    

def retrieve_data(target_uri, modelName, gain_arg, std_args, agent, iteration):
    """
    Retrieve data from the target.
    """
    sys_get = f'quarc_run -u -t {target_uri} {modelName}.rt-linux_rt_armv7{gain_arg}{std_args}'
    print(sys_get)
    subprocess.call(sys_get, shell=True)
    shutil.copyfile('servoPDF.mat', f'servoPDF-{agent}_{iteration}.mat')


    
def load_agent_data(filename):
    """
    Load data from the agent and extract relevant data
    
    Returns:
    rt_t: Time
    rt_theta: Theta
    theta_d
    """
    data = loadmat(filename)
    rt_t = data['rt_t'].flatten()
    rt_theta = data['rt_theta'].flatten()
    theta_d = data['rt_theta_d'].flatten()
    return rt_t, rt_theta, theta_d

    
def compute_reward(theta_d, rt_theta1, rt_theta2, rt_t1, rt_t2):
    """
    Computes the total reward for the agents
    
    Reward = integral{abs(theta_d - rt_theta)}dt
    
    Returns:
    total_error: Total reward
    os1: Overshoot error for agent 1
    os2: Overshoot error for agent 2
    
    """
    # Overshoot error
    os1 = np.abs(theta_d - rt_theta1)
    os2 = np.abs(theta_d - rt_theta2)
    # Compute error between the two agents
    error12 = np.abs(rt_theta1 - rt_theta2)

    # Compute integral of errors
    integral_os1 = np.trapz(os1, rt_t1)
    integral_os2 = np.trapz(os2, rt_t2)
    total_os = 0.5*integral_os1 + 0.5*integral_os2
    integral_error12 = np.trapz(error12, rt_t1)
    total_error = total_os + 3* integral_error12
    total_error = 1 / total_error 
    
    os1 = 1 / integral_os1
    os2 = 1 / integral_os2
    
    return total_error,os1,os2
       
def plot_data(rt_t1, rt_theta1, os1, rt_t2, rt_theta2, os2):
    """
    Plot the data from the agents
    """
    plt.figure(1)
    plt.subplot(1,2,1)
    plt.plot(rt_t1, rt_theta1, label='Agent-1')
    plt.plot(rt_t2, rt_theta2, label='Agent-2')
    plt.grid(True)
    plt.xlabel('t (s)')
    plt.ylabel('theta')
    plt.title("Theta over time")
    
    plt.subplot(1,2,2)
    plt.plot(rt_t1[:4000], os1[:4000], label='Agent-1 OS')
    plt.plot(rt_t2[:4000], os2[:4000], label='Agent-2 OS')
    plt.grid(True)
    plt.xlabel('t (s)')
    plt.ylabel('theta')
    plt.title("Error over time")
    plt.legend()
    plt.show()


# Create a directory to save plots
if not os.path.exists('plots'):
    os.makedirs('plots')

modelName = 'servoPDF'

target_uri_1 = 'tcpip://172.22.11.2:17000?keep_alive=1'
target_uri_2 = 'tcpip://172.22.11.10:17000?keep_alive=1'

std_args = ' -d ./tmp -uri tcpip://linux-dev:17001'

#Download model to target
sys1dl = f'quarc_run -D -t {target_uri_1} {modelName}.rt-linux_rt_armv7{std_args}'
sys2dl = f'quarc_run -D -t {target_uri_2} {modelName}.rt-linux_rt_armv7{std_args}'

# Run the system commands
subprocess.call(sys1dl, shell=True)
subprocess.call(sys2dl, shell=True)

# Initial safepoint values.


kp1_0 = 5
kd1_0 = 0.2

kp2_0 = 4
kd2_0 = 0.5

x0_1 = (kp1_0,kd1_0)
x0_2 = (kp2_0,kd2_0)

#delay difference between the two agents
td1 = 0.045

# create gain arguments
gain_arg1 = f' -Kp {kp1_0} -Kd {kd1_0}'
gain_arg2 = f' -Kp {kp2_0} -Kd {kd2_0}'

print(f'Initial gain arguments for Agent 1: {gain_arg1}')
print(f'Initial gain arguments for Agent 2: {gain_arg2}')

# create system commnand for gain arguments
sys1run = f'quarc_run -l -t {target_uri_1} {modelName}.rt-linux_rt_armv7{gain_arg1} -td {td1:.5f} {std_args}'
sys2run = f'quarc_run -l -t {target_uri_2} {modelName}.rt-linux_rt_armv7{gain_arg2}{std_args}'

# Run the system commands

subprocess.call(sys1run, shell=True)
subprocess.call(sys2run, shell=True)

sent_command(target_uri_1, modelName, gain_arg1, std_args)
sent_command(target_uri_2, modelName, gain_arg2, std_args)

# wait for the experiment to finish
# this should be replaced with a more robust method, where the script waits for the experiment to finish
# Possibly by checking the port for incoming data
time.sleep(7)

#retrieve data from Agents
retrieve_data(target_uri_1, modelName, gain_arg1, std_args,1,0)
retrieve_data(target_uri_2, modelName, gain_arg2, std_args,2,0)

# Load data from Agents
rt_t1, rt_theta1,theta_d = load_agent_data('servoPDF-1_0.mat')
rt_t2, rt_theta2, _ = load_agent_data('servoPDF-2_0.mat')

#compute initial safe reward
reward_0, os1_0 , os2_0 = compute_reward(theta_d,rt_theta1,rt_theta2,rt_t1,rt_t2)

print(f'Initial reward: {reward_0}')
print(f"Initial error1: ",os1_0)
print(f"Initial error2: ",os2_0)

wait = input("Press Enter to start Bayesian Optimization...")

# plot_data(rt_t1, rt_theta1, os1_0, rt_t2, rt_theta2, os2_0)
# exit(0)

# =================== Bayesian Optimization ===================

# Define the Agent class for Bayesian Optimization
class Agent:
    def __init__(self, id, bounds, safe_point,initial_reward):
        self.id = id
        self.bounds = bounds
        self.safe_point = safe_point

        self.x0 = np.asarray([safe_point])
        self.y0 = np.asarray([[initial_reward]]) 

        self.kernel = GPy.kern.RBF(input_dim=len(bounds),ARD=True)
        self.gp = GPy.models.GPRegression(self.x0, self.y0, self.kernel, noise_var=0.05**2)

        self.parameter_set = safeopt.linearly_spaced_combinations(self.bounds, 100)
        self.opt = safeopt.SafeOpt(self.gp, self.parameter_set, 0.1, beta=4,threshold=0.05)

        self.kp_values = []
        self.rewards = []

    def optimize(self):
        x_next = self.opt.optimize()
        return x_next

    def update(self, x_next, y_meas):
        self.opt.add_new_data_point(x_next, y_meas)
        
        self.kp_values.append(x_next)
        self.rewards.append(y_meas)

# Kp bounds
K_bounds = [(0.01, 10), (0.01, 1)]

agent1 = Agent(1, K_bounds, x0_1,reward_0)
agent2 = Agent(2, K_bounds, x0_2,reward_0)

# Quancer Experiment
def run_experiment(kp1,kd1,kp2,kd2, iteration):
    
    # set gain arguments
    gain_arg1 = f' -Kp {kp1} -Kd {kd1}'
    gain_arg2 = f' -Kp {kp2} -Kd {kd2}'

    sent_command(target_uri_1, modelName, gain_arg1, std_args)
    sent_command(target_uri_2, modelName, gain_arg2, std_args)

    # await experiment completion
    time.sleep(7)

    retrieve_data(target_uri_1, modelName, gain_arg1, std_args,1, iteration)
    retrieve_data(target_uri_2, modelName, gain_arg2, std_args,2, iteration)

    rt_t1, rt_theta1,theta_d = load_agent_data(f'servoPDF-1_{iteration}.mat')
    rt_t2, rt_theta2, _ = load_agent_data(f'servoPDF-2_{iteration}.mat')
    
    reward, os1 , os2 = compute_reward(theta_d,rt_theta1,rt_theta2,rt_t1,rt_t2)

    return reward,os1, os2


N = 3  # Number of iterations

# Bayesian Optimization
for iteration in range(1, N+1):
    
    # Get next Kp values from agents
    K1_next = agent1.optimize()
    K2_next = agent2.optimize()

    print(f"Iteration {iteration}, Agent 1:  -Kp {K1_next[0]} -Kd {K1_next[1]}, Agent 2: -Kp: {K2_next[0]} -Kd {K2_next[1]}")

    # Run the experiment with kp1_next and kp2_next
    y,os1,os2 = run_experiment(K1_next[0],K1_next[1],K2_next[0],K2_next[1], iteration)

    print(f"Reward: {y}")
    
    # Update agents with observations
    
    agent1.update(K1_next, y)
    agent2.update(K2_next, y)
    
    # Save agent's data
    np.save(f'agent1_x_{iteration}.npy', agent1.opt.x)
    np.save(f'agent1_y_{iteration}.npy', agent1.opt.y)
    np.save(f'agent2_x_{iteration}.npy', agent2.opt.x)
    np.save(f'agent2_y_{iteration}.npy', agent2.opt.y)

    # Save rewards
    np.save(f'rewards_{iteration}.npy', agent1.rewards)  # Rewards are the same for both agents

    # Get current maximum
    x_max_1, y_max_1 = agent1.opt.get_maximum()
    x_max_2, y_max_2 = agent2.opt.get_maximum()

    # Plot and save agent1
    plt.figure()
    agent1.opt.plot(100)
    plt.scatter(x_max_1[0], x_max_1[1], marker='*', color='red', s=100, label='Current Maximum')
    plt.title(f'Agent 1 - Iteration {iteration}')
    plt.xlabel('Kp1')
    plt.ylabel('Kd1')
    plt.legend()
    plt.savefig(f'plots/agent1_iteration_{iteration}.png')
    plt.close()

    # Plot and save agent2
    plt.figure()
    agent2.opt.plot(100)
    plt.scatter(x_max_2[0], x_max_2[1], marker='*', color='red', s=100, label='Current Maximum')
    plt.title(f'Agent 2 - Iteration {iteration}')
    plt.xlabel('Kp2')
    plt.ylabel('Kd2')
    plt.legend()
    plt.savefig(f'plots/agent2_iteration_{iteration}.png')
    plt.close()

    # Save agent's opt object using pickle
    with open(f'agent1_opt_{iteration}.pkl', 'wb') as f:
        pickle.dump(agent1.opt, f)
    with open(f'agent2_opt_{iteration}.pkl', 'wb') as f:
        pickle.dump(agent2.opt, f)
    
print("========= EXPERIMENT COMPLETE =========")

# Plot Kp values over iterations
iterations = np.arange(0, N+1)

plt.figure(2)
plt.plot(iterations[1:].flatten(), [reward for reward in agent1.rewards], label='Agent 1 Reward')
plt.plot(iterations[1:].flatten(), [reward for reward in agent2.rewards], label='Agent 2 Reward')
plt.xlabel('Iteration')
plt.ylabel('Reward') 
plt.legend()
plt.title('Reward over iterations')
plt.grid(True)
plt.savefig('plots/reward_over_iterations.png')
plt.show()

# Final plots for agents
agent1.opt.plot(100)
x_max_1, y_max_1 = agent1.opt.get_maximum()
plt.scatter(x_max_1[0], x_max_1[1], marker='*', color='red', s=100, label='Current Maximum')
plt.title('Agent 1')
plt.xlabel('Kp1')
plt.ylabel('Kd1')
plt.legend()
plt.show()

agent2.opt.plot(100)
x_max_2, y_max_2 = agent2.opt.get_maximum()
plt.scatter(x_max_2[0], x_max_2[1], marker='*', color='red', s=100, label='Current Maximum')
plt.title('Agent 2')
plt.xlabel('Kp2')
plt.ylabel('Kd2')
plt.legend()
plt.show()

# Function to plot data for a specific iteration
def plot_iteration(iteration_number):
    # Load data
    rt_t1, rt_theta1, theta_d = load_agent_data(f'servoPDF-1_{iteration_number}.mat')
    rt_t2, rt_theta2, _ = load_agent_data(f'servoPDF-2_{iteration_number}.mat')
    
    # Plot state response
    plt.figure()
    plt.plot(rt_t1, rt_theta1, label='Agent-1')
    plt.plot(rt_t2, rt_theta2, label='Agent-2')
    plt.plot(rt_t1, theta_d, label='Desired Theta', linestyle='--')
    plt.grid(True)
    plt.xlabel('t (s)')
    plt.ylabel('theta')
    plt.title(f"Theta over time - Iteration {iteration_number}")
    plt.legend()
    plt.savefig(f'plots/state_response_iteration_{iteration_number}.png')
    plt.close()
    
    # Load agent opt objects
    with open(f'agent1_opt_{iteration_number}.pkl', 'rb') as f:
        agent1_opt = pickle.load(f)
    with open(f'agent2_opt_{iteration_number}.pkl', 'rb') as f:
        agent2_opt = pickle.load(f)
    
    # Get current maximum
    x_max_1, y_max_1 = agent1_opt.get_maximum()
    x_max_2, y_max_2 = agent2_opt.get_maximum()
    
    # Plot agent1
    plt.figure()
    agent1_opt.plot(100)
    plt.scatter(x_max_1[0], x_max_1[1], marker='*', color='red', s=100, label='Current Maximum')
    plt.title(f'Agent 1 - Iteration {iteration_number}')
    plt.xlabel('Kp1')
    plt.ylabel('Kd1')
    plt.legend()
    plt.savefig(f'plots/agent1_plot_iteration_{iteration_number}.png')
    plt.close()
    
    # Plot agent2
    plt.figure()
    agent2_opt.plot(100)
    plt.scatter(x_max_2[0], x_max_2[1], marker='*', color='red', s=100, label='Current Maximum')
    plt.title(f'Agent 2 - Iteration {iteration_number}')
    plt.xlabel('Kp2')
    plt.ylabel('Kd2')
    plt.legend()
    plt.savefig(f'plots/agent2_plot_iteration_{iteration_number}.png')
    plt.close()
    
    # Load rewards
    rewards = np.load(f'rewards_{iteration_number}.npy')
    iterations = np.arange(1, len(rewards)+1)
    
    # Plot reward over iterations
    plt.figure()
    plt.plot(iterations, rewards, label='Reward')
    plt.xlabel('Iteration')
    plt.ylabel('Reward')
    plt.title('Reward over Iterations')
    plt.legend()
    plt.savefig(f'plots/reward_plot_iteration_{iteration_number}.png')
    plt.close()

# Example usage of plot_iteration function
iteration_to_plot = 3  # Specify the iteration number you want to plot
plot_iteration(iteration_to_plot)
