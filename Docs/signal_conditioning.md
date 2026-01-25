# Signal Conditioning

## Introduction
Signal conditioning is a critical part of any biomedical measurement system.
Physiological signals such as EEG, ECG, and EMG are inherently low in amplitude
and highly susceptible to noise and interference. Without proper conditioning,
these signals cannot be reliably digitized or analyzed.

This project focuses on practical signal conditioning techniques required for
real-world biosignal acquisition rather than ideal or theoretical signals.

## Nature of Biomedical Signals
Most biomedical signals exhibit the following characteristics:
- Very low amplitude (microvolt to millivolt range)
- Low frequency content
- High sensitivity to noise and motion artifacts
- Presence of common-mode interference (especially power-line noise)

Due to these characteristics, direct connection of sensors to digital systems
is not feasible.

## Amplification
Instrumentation amplifiers are used as the first stage of signal conditioning.
They are preferred because of their:
- High input impedance
- High common-mode rejection ratio (CMRR)
- Low noise performance

The gain of the amplifier is selected based on the expected signal amplitude of
each sensor. Excessive gain is avoided to prevent saturation and distortion.

## Filtering
Filtering is applied to remove unwanted frequency components while preserving
the useful signal.

Typical filtering stages include:
- High-pass filtering to remove baseline drift
- Low-pass filtering to suppress high-frequency noise
- Notch filtering to reduce power-line interference (50 Hz)

Filter cutoff frequencies are chosen according to the specific signal being
measured.

## Noise Sources and Mitigation
Common noise sources in biomedical measurements include:
- Power-line interference
- Motion artifacts
- Electrode-skin impedance variations
- Electromagnetic interference from nearby electronics

Noise mitigation techniques used in this project include:
- Differential signal measurement
- Proper grounding and shielding
- Short and secure electrode leads
- Analog filtering before digitization

## Importance of Proper Conditioning
Effective signal conditioning improves:
- Signal-to-noise ratio
- Measurement reliability
- Repeatability of results
- Safety of the overall system

A well-designed signal conditioning stage is essential for accurate and stable
biomedical signal acquisition.
