# Using Electronic Color Sensors for Spectroscopy with the NHAS

This repository contains the software behind the modular spectrometer!

The goal of this project is to explore how far we can use electronic color sensors to perform color spectroscopy. This could allow for very portable and affordable spectrometers for field work as well as making spectroscopy more accesible to the public.

## Tour of the repo

for future me so i don't forget!

1. (1 RGB LED w/ RGB Sensor) Prints out the sensor readings and drives another RGB LED with those readings. You can change the color of the RGB LED by typing `r`, `g`,or `b` into the Serial monitor.
2. ( N/A ) Testing trying to connect Arduino with Python.
3. (RGB Sensor) Python prints the sensor readings and displays a window with that color.
4. ( N/A ) Finding the peaks of the LED emission spectra and center lamda
5. ( 1 RGB LED w/ RGB Sensor ) Experiment 2, testing the linearity of the sensor by altering the PWM of the LED
6. ( 1 RGB LED w/ RGB Sensor ) Side exploration into a color detection feedback loop
7. ( 1 RGB LED w/ RGB Sensor ) Using classical calibration to predict input of RGB LED.
8. ( 8 RGB LED w/ RGB Sensor ) -unfinished- Trying to drive 8 LEDs with an Arduino Mega board
9. ( 8 RGB LEDs w/ RGB Sensor ) -not started- Using a linear regression machine learning model to calibrate the sensor and predict input of RGB LED.

## Acknoldgements

- Dr. Markus Testorf
- Zoe Hill
- Matthew Adner
- Dr. Alyson Michael
- Dr. Kelly Salmon
- Dr. Peter Faletra
- everyone at the NHAS :)
