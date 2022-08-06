import numpy as np


def main():
    calibration = np.genfromtxt("./save.txt")
    print(f"reading calibration matrix:\n{calibration}]\n")

    reading = np.array(ask_readings())
    prediction = np.dot(calibration, reading)
    print(f"\nprediction:\n{prediction}\n")


def ask_readings() -> list[float]:
    r = float(input("red sensor reading: "))
    g = float(input("green sensor reading: "))
    b = float(input("blue sensor reading: "))
    return [r, g, b]


if __name__ == "__main__":
    main()
