from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Conv2D, Flatten


def build_model(input_shape, action_size):
    model = Sequential()
    model.add(Conv2D(64, kernel_size=3, activation='relu', input_shape=input_shape))
    model.add(Flatten())
    model.add(Dense(512, activation='relu'))
    model.add(Dense(action_size, activation='linear'))
    model.compile(optimizer='adam', loss='mse')
    return model


