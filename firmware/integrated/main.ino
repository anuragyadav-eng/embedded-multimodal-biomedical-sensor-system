/*
  Embedded Multimodal Biomechanical Sensor System
  Author: Anurag Yadav

  Description:
  This firmware performs real-time acquisition of multiple
  biomechanical and biomedical signals using analog inputs.
  The acquired data is streamed over serial communication
  in CSV format for visualization and analysis.

  Note:
  All biosignals (EEG, ECG, EMG, EOG, EDA) are assumed to be
  pre-conditioned using appropriate analog front-end circuitry
  (instrumentation amplifiers and filters) before ADC input.
*/

// ---------------- Pin Configuration ----------------
#define EEG_PIN     A0
#define ECG_PIN     A1
#define EMG_PIN     A2
#define EOG_PIN     A3
#define EDA_PIN     A4
#define FORCE_PIN   A5

// ---------------- Sampling Parameters ----------------
#define SAMPLE_DELAY_MS 5      // ~200 Hz sampling rate
#define AVG_WINDOW      4      // Moving average window size

// ---------------- Variables ----------------
int eeg_buf[AVG_WINDOW], ecg_buf[AVG_WINDOW], emg_buf[AVG_WINDOW];
int eog_buf[AVG_WINDOW], eda_buf[AVG_WINDOW], force_buf[AVG_WINDOW];
int idx = 0;

// ---------------- Function Prototypes ----------------
int movingAverage(int *buffer);

// ---------------- Setup ----------------
void setup() {
  Serial.begin(115200);
  analogReference(DEFAULT);

  // CSV Header for data logging
  Serial.println("EEG,ECG,EMG,EOG,EDA,FORCE");

  // Initialize buffers
  for (int i = 0; i < AVG_WINDOW; i++) {
    eeg_buf[i] = ecg_buf[i] = emg_buf[i] = 0;
    eog_buf[i] = eda_buf[i] = force_buf[i] = 0;
  }
}

// ---------------- Main Loop ----------------
void loop() {

  // Read analog signals
  eeg_buf[idx]   = analogRead(EEG_PIN);
  ecg_buf[idx]   = analogRead(ECG_PIN);
  emg_buf[idx]   = analogRead(EMG_PIN);
  eog_buf[idx]   = analogRead(EOG_PIN);
  eda_buf[idx]   = analogRead(EDA_PIN);
  force_buf[idx] = analogRead(FORCE_PIN);

  // Increment buffer index
  idx = (idx + 1) % AVG_WINDOW;

  // Compute averaged values
  int eeg   = movingAverage(eeg_buf);
  int ecg   = movingAverage(ecg_buf);
  int emg   = movingAverage(emg_buf);
  int eog   = movingAverage(eog_buf);
  int eda   = movingAverage(eda_buf);
  int force = movingAverage(force_buf);

  // Transmit data (CSV format)
  Serial.print(eeg);   Serial.print(",");
  Serial.print(ecg);   Serial.print(",");
  Serial.print(emg);   Serial.print(",");
  Serial.print(eog);   Serial.print(",");
  Serial.print(eda);   Serial.print(",");
  Serial.println(force);

  delay(SAMPLE_DELAY_MS);
}

// ---------------- Moving Average Filter ----------------
int movingAverage(int *buffer) {
  long sum = 0;
  for (int i = 0; i < AVG_WINDOW; i++) {
    sum += buffer[i];
  }
  return sum / AVG_WINDOW;
}
