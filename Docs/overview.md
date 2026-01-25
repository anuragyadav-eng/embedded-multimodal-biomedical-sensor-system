# Project Overview

## Introduction
This project focuses on the design and development of a multimodal biomedical
sensor system intended for educational and experimental purposes. The system
is designed to acquire, condition, and observe multiple physiological and
biomechanical signals from the human body using a common embedded platform.

Biomedical signals are generally low in amplitude, highly sensitive to noise,
and require careful analog front-end design. This project emphasizes practical
understanding of these challenges rather than clinical accuracy.

## Sensors Included
The system integrates the following sensors:

- **Electroencephalography (EEG)** – Brain electrical activity  
- **Electrocardiography (ECG)** – Heart electrical activity  
- **Electromyography (EMG)** – Muscle electrical activity  
- **Electrooculography (EOG)** – Eye movement signals  
- **Electrodermal Activity (EDA)** – Skin conductance variations  
- **Force / Pressure Sensor** – Mechanical force and pressure measurement  

Each sensor module is treated as an independent subsystem while sharing common
signal conditioning and data acquisition concepts.

## System-Level Working
Physiological signals are captured using electrodes or dedicated sensors placed
on the human body. These signals are typically weak and contaminated by noise
such as power-line interference, motion artifacts, and electrode impedance
variations.

An analog front-end circuit is used to amplify and condition the signals.
Filtering is applied to retain the frequency range of interest while suppressing
unwanted noise. The conditioned analog signal is then digitized using an
Analog-to-Digital Converter (ADC) and handled by an embedded system for further
observation, visualization, or storage.

## Project Scope and Intent
The primary goal of this project is to develop a clear understanding of:

- Biomedical signal characteristics
- Analog signal conditioning techniques
- Noise sources and mitigation
- System-level integration of multiple sensors
- Practical limitations of real-world biosignal acquisition

This project is **not intended to be a medical-grade or diagnostic system**.

## Current Development Status
- **ECG Module**: Completed and tested  
- **EMG Module**: Completed and tested  
- **Force / Pressure Sensor**: Completed and calibrated  
- **EEG Module**: Under experimental development  
- **EOG Module**: Under experimental development  
- **EDA Module**: Under experimental development  

## Applications
- Academic and laboratory learning
- Embedded systems experimentation
- Biomedical signal acquisition studies
- Human–machine interface research (non-clinical)

## Disclaimer
This project is developed strictly for educational and research purposes.
It is not a certified medical device and must not be used for diagnosis,
treatment, or clinical decision-making.
