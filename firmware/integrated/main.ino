/*
  Embedded Multimodal Biomechanical Sensor System
  Author: Anurag Yadav

  This firmware performs basic real-time acquisition of
  multiple biosignals using analog inputs and streams
  the data over serial communication.
*/

// Analog input pins
#define ECG_PIN A0
#define EMG_PIN A1
#define EOG_PIN A2
#define EDA_PIN A3
#define FORCE_PIN A4

void setup() {
  Serial.begin(115200);        // Initialize serial communication
  analogReference(DEFAULT);    // Default ADC reference
}

void loop() {
  int ecg   = analogRead(ECG_PIN);
  int emg   = analogRead(EMG_PIN);
  int eog   = analogRead(EOG_PIN);
  int eda   = analogRead(EDA_PIN);
  int force = analogRead(FORCE_PIN);

  // Transmit data in CSV format
  Serial.print(ecg);
  Serial.print(",");
  Serial.print(emg);
  Serial.print(",");
  Serial.print(eog);
  Serial.print(",");
  Serial.print(eda);
  Serial.print(",");
  Serial.println(force);

  delay(5);   // Sampling delay (~200 Hz)
}
