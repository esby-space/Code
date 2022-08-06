import pandas as pd
import numpy as np


def main():
    data = pd.read_csv("LED Spectrometer Readings.csv")
    print(f"reading LED data:\n{data}")

    # Iterate over all columns
    for (column_name, _) in data.iteritems():
        (wavelength, peak) = get_peak(str(column_name), data)
        print(column_name)
        print(f"Peak: {peak} at Lamda {wavelength}\n")


def get_peak(name: str, data: pd.DataFrame) -> tuple[float, float]:
    return (data["Wavelength"][data[name].idxmax()], data[name].max())


def get_width(name: str, data: pd.DataFrame) -> float:
    return 0.0


if __name__ == "__main__":
    main()
