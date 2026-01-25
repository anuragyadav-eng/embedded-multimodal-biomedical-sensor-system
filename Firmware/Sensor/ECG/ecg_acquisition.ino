#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ECG sensor pin
const int ECG_PIN = A0;

// BPM calculation variables
int threshold = 520;          // Adjust based on ECG signal peak
bool lastState = false;
unsigned long lastBeat = 0;
int bpm = 0;

void setup() {
  Serial.begin(115200);       // Serial Plotter baud rate

  // OLED initialization
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
      while (1); // Stop if OLED not detected
    }
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ECG MONITOR");
  display.display();
  delay(1000);
}

void loop() {
  int ecgValue = analogRead(ECG_PIN);
  unsigned long currentTime = millis();

  // Peak detection
  bool currentState = (ecgValue > threshold);

  if (currentState && !lastState) {
    unsigned long timeDiff = currentTime - lastBeat;

    if (timeDiff > 300 && timeDiff < 2000) {   // Valid BPM range
      bpm = 60000 / timeDiff;
    }

    lastBeat = currentTime;
  }

  lastState = currentState;

  // Send ECG + BPM to Serial Plotter
  Serial.print(ecgValue);
  Serial.print('\t');
  Serial.println(bpm);

  // OLED display
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Heart Rate");

  display.setTextSize(2);
  display.setCursor(0, 12);
  display.print(bpm);
  display.print(" BPM");

  display.display();

  delay(4);   // ~250 Hz sampling
}
