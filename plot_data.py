import matplotlib.pyplot as plt
from scipy.io import loadmat
import numpy as np
import pickle
import os

def load_agent_data(filename):
    """
    Load data from the agent and extract relevant data
    """
    data = loadmat(filename)
    rt_t = data['rt_t'].flatten()
    rt_theta = data['rt_theta'].flatten()
    theta_d = data['rt_theta_d'].flatten()
    return rt_t, rt_theta, theta_d

def plot_iteration(iteration_number):
    # Check if 'plots' directory exists
    if not os.path.exists('plots'):
        os.makedirs('plots')

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
    rewards = []
    for i in range(1, iteration_number + 1):
        # Assuming rewards are saved after each iteration
        reward = np.load(f'rewards_{i}.npy')[-1]  # Get the last reward in each file
        rewards.append(reward)
    iterations = np.arange(1, len(rewards) + 1)
    
    # Plot reward over iterations
    plt.figure()
    plt.plot(iterations, rewards, label='Reward')
    plt.xlabel('Iteration')
    plt.ylabel('Reward')
    plt.title('Reward over Iterations')
    plt.legend()
    plt.savefig(f'plots/reward_plot_iteration_{iteration_number}.png')
    plt.close()

# Example usage
if __name__ == "__main__":
    iteration_to_plot = int(input("Enter iteration number to plot: "))
    plot_iteration(iteration_to_plot)
    print(f"Plots for iteration {iteration_to_plot} have been saved in the 'plots' directory.")
