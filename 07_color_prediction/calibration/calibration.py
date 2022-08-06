# Calibration of a RGB Sensor against RGB LED

import numpy as np


def main():
    coeffecients = np.array(ask_coeffecients())
    print(f"\ncurrent coeffecients:\n {coeffecients}")

    calibration = np.linalg.inv(coeffecients)
    print(f"\ncalibration matrix:\n {calibration}")

    np.savetxt("./save.txt", calibration)


def ask_coeffecients() -> list[list[float]]:
    # variable naming: red_blue -> how the red LED affects the blue sensor
    # red calibration
    print("calibrating RED LED -> turn on RED LED and turn off GREED and BLUE LEDs")
    red_red = int(input("RGB sensor red reading: ")) / 255
    red_green = int(input("RGB sensor green reading: ")) / 255
    red_blue = int(input("RGB sensor blue reading: ")) / 255

    # green calibration
    print("\ncalibrating GREEN LED -> turn on GREEN LED and turn off RED and BLUE LEDs")
    green_red = int(input("RGB sensor red reading: ")) / 255
    green_green = int(input("RGB sensor green reading: ")) / 255
    green_blue = int(input("RGB sensor blue reading: ")) / 255

    # blue calibration
    print("\ncalibrating BLUE LED -> turn on BLUE LED and turn off RED and GREEN LEDs")
    blue_red = int(input("RGB sensor red reading: ")) / 255
    blue_green = int(input("RGB sensor greed reading: ")) / 255
    blue_blue = int(input("RGB sensor blue reading: ")) / 255

    return [
        [red_red, green_red, blue_red],
        [red_green, green_green, blue_green],
        [red_blue, green_blue, blue_blue],
    ]


if __name__ == "__main__":
    main()
