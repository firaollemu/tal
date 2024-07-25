import chess
import chess.engine
import gym
import numpy as np



class ChessEnv(gym.Env):
    def __init__(self):
        super(ChessEnv, self).__init__()
        self.board = chess.Board() # get the chess board from the python-chess library
    
    def reset(self):
        self.board.reset()
        return self._get_obs()

    def step(self, action):
        move = chess.Move.from_uci(action)
        self.board.push(move)
        reward = self._get_reward()
        done = self.board.is_game_over()
        return self._get_obs(), reward, done, {}
    
    def _get_obs(self):
        return self.board.fen() # return the FEN notation of the current board
    
    def _get_reward(self):
        if self.board.is_checkmate():
            return 1 if self.board.turn == chess.WHITE else -1
        return 0


env = ChessEnv()
