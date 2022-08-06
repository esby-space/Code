import numpy as np


NOISE = 0.05


def main():
    pass


# implementing a physical model simulation
def gaussian_spectrum(
    wavelength: np.ndarray, brightness: float, center_wavelength: float, width: float
):
    """implementation of gaussian function"""
    return brightness * np.exp(-((wavelength - center_wavelength) ** 2) / width**2)


def led_detector_response(
    led_brightness: float,
    led_center_wavelength: float,
    led_width: float,
    detector_sensitivity: float,
    detector_wavelength: float,
    detector_width: float,
):
    """simulates the response of one led to one channel of a sensor"""
    lambda_axis = np.arange(0, 2000)  # range of wavelength in nm
    source_spectrum = gaussian_spectrum(
        lambda_axis, led_brightness, led_center_wavelength, led_width
    )
    detector_spectrum = gaussian_spectrum(
        lambda_axis, detector_sensitivity, detector_wavelength, detector_width
    )

    # normal random distribution
    return (
        np.sum(source_spectrum * detector_spectrum)
        + np.random.normal(loc=0, scale=NOISE, size=(1))[0]
    )


def rgb_detector_response(calibration: np.ndarray):
    # center wavelengths
    cr = 600
    cg = 500
    cb = 450

    # width of gaussian spectrums
    wr = 50
    wg = 20
    wb = 20

    # sensitivity of detectors
    d0r = 1.0
    d0g = 0.5
    d0b = 0.25

    # center wavelengths of sensor
    dcr = 630
    dcg = 530
    dcb = 410

    # width of detector channels
    dwr = 100
    dwg = 150
    dwb = 120

    # dr = s[0, 0] * led_detector_response(1.0, cr, wr, d0r, )
    pass


if __name__ == "__main__":
    main()
