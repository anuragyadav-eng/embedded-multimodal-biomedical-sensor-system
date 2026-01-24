+--------------------+
|  Human Body Input  |
+--------------------+
          |
          v
+--------------------+
|   Sensors Layer    |
| EEG | ECG | EMG    |
| EOG | EDA | Force  |
+--------------------+
          |
          v
+----------------------------+
| Analog Front-End Circuits  |
| - Instrumentation Amp     |
| - Gain Control            |
| - Noise Reduction         |
+----------------------------+
          |
          v
+----------------------------+
|   Signal Conditioning     |
| - Band-pass Filtering     |
| - Notch Filter (50 Hz)    |
+----------------------------+
          |
          v
+----------------------------+
|  Analog-to-Digital        |
|  Conversion (ADC)         |
+----------------------------+
          |
          v
+----------------------------+
| Embedded System / MCU     |
| - Sampling Control        |
| - Data Handling           |
+----------------------------+
          |
          v
+----------------------------+
| Data Output & Analysis    |
| - Visualization           |
| - Storage / Processing    |
+----------------------------+
