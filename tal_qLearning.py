import random
from tal_net import build_model
from collections import deque
from tal import env
import numpy as np


class DQNAgent:
    def __init__(self, state_shape, action_size):
        self.state_shape = state_shape
        self.action_size = action_size
        self.memory = deque(maxlen=2000)
        self.gamma = 0.95
        self.epsilon = 1.0
        self.epsilon_decay = 0.995
        self.epsilon_min = 0.01
        self.model = build_model(state_shape, action_size)
    
    def memorize(self, state, action, reward, next_state, done):
        self.memory.append((state, action, reward, next_state, done))
    
    def act(self, state):
        if np.random.rand() <= self.epsilon:
            return random.choice(range(self.action_size))
        action_values = self.model.predict(state)
        return np.argmax(action_values)
    
    def reply(self, batch_size):
        minibatch = random.sample(self.memorize, batch_size)
        for state, action, reward, next_state, done in minibatch:
            target = reward 
            if not done:
                target += self.gamma * np.amax(self.model.predict(next_state)[0])
            target_f = self.model.predict(state)
            target_f[0][action] = target
            self.model.fit(state, target_f, epochs=1, verbose=0)
        if self.epsilon > self.epsilon_min:
            self.epsilon *= self.epsilon_decay
    


if __name__ == "__main__":
    EPISODES = 1000
    state_shape = (8, 8, 1)
    action_size = 4672
    agent = DQNAgent(state_shape, action_size)
    batch_size = 32


    for e in range(EPISODES):
        state =  env.reset()
        state = np.reshape(state, [1] + list(state_shape))
        for time in range(500):
            action = agent.act(state)
            next_state, reward, done, _ = env.step(action)
            next_state = np.reshape(next_state, [1] +  list(state_shape))
            agent.memorize(state, action, reward, next_state, done)
            state = next_state
            if done:
                print(f"episode: {e}/{EPISODES}, score: {time}, e: {agent.epsilon:.2}")
                break
            if len(agent.memory) > batch_size:
                agent.reply(batch_size)

            