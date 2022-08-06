import random
import numpy as np
import pandas as pd


def main():
    # read data matrix
    data = pd.read_csv("spectrometer_readings.csv")

    input_matrix = np.zeros((3, len(data)))
    output_matrix = np.zeros((3, len(data)))

    for i in range(len(data)):
        # generate three random numbers for our initial guess
        sr = np.array([])


if __name__ == "__main__":
    main()
