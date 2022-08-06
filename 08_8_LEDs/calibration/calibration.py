import numpy as np
import matplotlib.pyplot as plt

def main():
    pass


def gaussian_spectrum(wavelength: float, brightness: float, center_wavelength: float, width: float):
    return brightness * np.exp(-(wavelength - center_wavelength) ** 2 / width **2)


if __name__ == "__main__":
    main()
