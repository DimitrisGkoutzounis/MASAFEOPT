import subprocess
import time
import shutil
import matplotlib.pyplot as plt
from scipy.io import loadmat
import numpy as np

import safeopt
import GPy

################ PHASE 1 ################

def retrieve_data(target_uri, modelName, gain_arg, std_args):
    sys_get = f'quarc_run -u -t {target_uri} {modelName}.rt-linux_rt_armv7{gain_arg}{std_args}'
    subprocess.call(sys_get, shell=True)
    shutil.copyfile('servoPDF.mat', 'servoPDF.mat')
    
    
def compute_reward(theta_d, rt_theta1, rt_theta2, rt_t1, rt_t2):
    # Overshoot error
    os1 = theta_d - rt_theta1
    os2 = theta_d - rt_theta2

    # Compute error between the two agents
    error12 = rt_theta1 - rt_theta2

    # Compute integral of errors
    integral_os1 = np.trapz(os1, rt_t1)
    integral_os2 = np.trapz(os2, rt_t2)
    total_os = integral_error1 + integral_error2
    integral_error12 = np.trapz(error12, rt_t1)
    total_error = integral_error12 + total_os
    
    return total_error,os1,os2
        


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


kp1 = 0.11
kd1 = 0.05

kp2 = 0.09
kd2 = 0.05


#delay difference between the two agents
td1 = 0.045

# create gain arguments
gain_arg1 = f' -Kp {kp1:.4f} -Kd {kd1:.4f}'
gain_arg2 = f' -Kp {kp2:.4f} -Kd {kd2:.4f}'

print(f'Initial gain arguments for Agent 1: {gain_arg1}')
print(f'Initial gain arguments for Agent 2: {gain_arg2}')

# create system commnand for gain arguments
sys1run = f'quarc_run -l -t {target_uri_1} {modelName}.rt-linux_rt_armv7{gain_arg1} -td {td1:.5f} {std_args}'
sys2run = f'quarc_run -l -t {target_uri_2} {modelName}.rt-linux_rt_armv7{gain_arg2}{std_args}'

# Run the system commands

subprocess.call(sys1run, shell=True)
subprocess.call(sys2run, shell=True)

# wait for the experiment to finish
# this should be replaced with a more robust method, where the script waits for the experiment to finish
# Possibly by checking the port for incoming data
time.sleep(6)

# Retrieve data from board
sys1get = f'quarc_run -u -t {target_uri_1} {modelName}.rt-linux_rt_armv7{gain_arg1}{std_args}'
sys2get = f'quarc_run -u -t {target_uri_2} {modelName}.rt-linux_rt_armv7{gain_arg2}{std_args}'


#retrieve data from Agent 1
# retrieve_data(target_uri_1, modelName, gain_arg1, std_args)
# Retrieve data from Agent 1
subprocess.call(sys1get, shell=True)

# store data in a new file
shutil.copyfile('servoPDF.mat', 'servoPDF-1.mat')

#retrieve data from Agent 2
subprocess.call(sys2get, shell=True)
#store data in a new file
shutil.copyfile('servoPDF.mat', 'servoPDF-2.mat')

#load data for agent 1
data1 = loadmat('servoPDF-1.mat')
rt_t1 = data1['rt_t'].flatten()
rt_theta1 = data1['rt_theta'].flatten()

#load data for agent 2
data2 = loadmat('servoPDF-2.mat')
rt_t2 = data2['rt_t'].flatten()
rt_theta2 = data2['rt_theta'].flatten()

# load desired theta
theta_d = data1['rt_theta_d'].flatten()

reward_0, _ , _ = compute_reward(theta_d,rt_theta1,rt_theta2,rt_t1,rt_t2)

print(f'Initial reward: {reward_0}')
exit(0)
dsadasd

# =================== Bayesian Optimization ===================

# Define the Agent class for Bayesian Optimization
class Agent:
    def __init__(self, id, bounds, safe_point):
        self.id = id
        self.bounds = [bounds]
        self.safe_point = safe_point

        self.z0 = np.array([[safe_point]])
        self.y0 = np.array([[0.0]])  # Initial observation (reward)

        self.kernel = GPy.kern.RBF(1)
        self.gp = GPy.models.GPRegression(self.z0, self.y0, self.kernel, noise_var=0.05**2)

        self.parameter_set = safeopt.linearly_spaced_combinations(self.bounds, 100)
        self.opt = safeopt.SafeOpt(self.gp, self.parameter_set, fmin=0.0)

        self.kp_values = [safe_point]
        self.rewards = [0.0]

    def optimize(self):
        z_next = self.opt.optimize()
        return z_next

    def update(self, z_next, y_meas):
        self.opt.add_new_data_point(z_next, y_meas)
        self.kp_values.append(z_next[0])
        self.rewards.append(y_meas)

# Initialize agents with safe initial Kp values
kp_bounds = (0.1, 10.0)
safe_kp1 = 4.0  # Same as initial kp1
safe_kp2 = 4.0  # Same as initial kp2
Kd = 0.05       # Keep Kd constant as per your instructions

agent1 = Agent(1, kp_bounds, safe_kp1)
agent2 = Agent(2, kp_bounds, safe_kp2)

# Define function to run the experiment and compute the error
def run_experiment(kp1, kp2):
    # Build the commands using kp1 and kp2
    kp1_value = kp1[0]  # Extract value from array
    kp2_value = kp2[0]

    gain_arg1 = f' -Kp {kp1_value:.4f} -Kd {Kd:.4f}'
    gain_arg2 = f' -Kp {kp2_value:.4f} -Kd {Kd:.4f}'

    sys1run = f'quarc_run -l -t {target_uri_1} {modelName}.rt-linux_rt_armv7{gain_arg1} {std_args}'
    sys2run = f'quarc_run -l -t {target_uri_2} {modelName}.rt-linux_rt_armv7{gain_arg2} {std_args}'

    # Run the commands
    subprocess.call(sys1run, shell=True)
    subprocess.call(sys2run, shell=True)

    time.sleep(6)

    # Retrieve data
    sys1get = f'quarc_run -u -t {target_uri_1} {modelName}.rt-linux_rt_armv7{gain_arg1} {std_args}'
    sys2get = f'quarc_run -u -t {target_uri_2} {modelName}.rt-linux_rt_armv7{gain_arg2} {std_args}'

    subprocess.call(sys1get, shell=True)
    shutil.copyfile('servoPDF.mat', 'servoPDF-1.mat')

    subprocess.call(sys2get, shell=True)
    shutil.copyfile('servoPDF.mat', 'servoPDF-2.mat')

    # Load data
    data1 = loadmat('servoPDF-1.mat')
    rt_t1 = data1['rt_t'].flatten()
    rt_theta1 = data1['rt_theta'].flatten()

    data2 = loadmat('servoPDF-2.mat')
    rt_t2 = data2['rt_t'].flatten()
    rt_theta2 = data2['rt_theta'].flatten()

    theta_d = data1['rt_theta_d'].flatten()

    # Compute overshoot error
    os1 = theta_d - rt_theta1
    os2 = theta_d - rt_theta2

    # Compute integral of the errors
    integral_error1 = np.trapz(np.abs(os1), rt_t1)
    integral_error2 = np.trapz(np.abs(os2), rt_t2)

    return integral_error1, integral_error2

# Run Bayesian Optimization
N = 10  # Number of iterations

for iteration in range(N):
    # Get next Kp values from agents
    kp1_next = agent1.optimize()
    kp2_next = agent2.optimize()

    print(f"Iteration {iteration+1}, Agent 1 Kp: {kp1_next[0]:.4f}, Agent 2 Kp: {kp2_next[0]:.4f}")

    # Run the experiment with kp1_next and kp2_next
    integral_error1, integral_error2 = run_experiment(kp1_next, kp2_next)

    # Use negative of the integral error as reward (since we want to minimize error)
    reward1 = -integral_error1
    reward2 = -integral_error2

    print(f"Agent 1 reward: {reward1}, Agent 2 reward: {reward2}")

    # Update agents with observations
    agent1.update(kp1_next, reward1)
    agent2.update(kp2_next, reward2)

# Plot Kp values over iterations
iterations = range(len(agent1.kp_values))

plt.figure()
plt.plot(iterations, agent1.kp_values, label='Agent 1 Kp')
plt.plot(iterations, agent2.kp_values, label='Agent 2 Kp')
plt.xlabel('Iteration')
plt.ylabel('Kp')
plt.legend()
plt.title('Kp values over iterations')
plt.grid(True)
plt.show()

# Plot rewards over iterations
plt.figure()
plt.plot(iterations, agent1.rewards, label='Agent 1 Reward')
plt.plot(iterations, agent2.rewards, label='Agent 2 Reward')
plt.xlabel('Iteration')
plt.ylabel('Reward')
plt.legend()
plt.title('Rewards over iterations')
plt.grid(True)
plt.show()
