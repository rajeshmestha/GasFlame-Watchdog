#include <Wire.h>                 // For I2C communication
#include <Adafruit_GFX.h>        // For OLED graphics
#include <Adafruit_SSD1306.h>    // For OLED display

// Sensor and output pin definitions
const int gasSensorPin = A0;
const int flameSensorPin = A1;
const int buzzerPin = 6;
const int ledPin = 7;
const int fanPin = 8;

// Detection thresholds
int gasThreshold = 500;     // Gas detection threshold
int flameThreshold = 500;   // Flame detection threshold

// OLED display configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Custom tone function for alarm
void playAlertTone() {
  tone(buzzerPin, 600); delay(150);
  tone(buzzerPin, 800); delay(150);
  tone(buzzerPin, 1000); delay(150);
  delay(100);
  tone(buzzerPin, 1200); delay(120);
  tone(buzzerPin, 1400); delay(100);
  delay(100);
  tone(buzzerPin, 1000); delay(300);
  noTone(buzzerPin); // Stop sound after melody
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);  // Start Serial Monitor

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Stop if display fails
  }

  display.display();      // Show splash screen
  delay(2000);            // Wait 2 seconds
  display.clearDisplay(); // Clear screen
}

void loop() {
  int gasValue = analogRead(gasSensorPin);
  int flameValue = analogRead(flameSensorPin);

  Serial.print("Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Flame: ");
  Serial.println(flameValue);

  bool gasDetected = (gasValue > gasThreshold);
  bool flameDetected = (flameValue < flameThreshold);

  display.clearDisplay();  // Clear OLED for new message

  if (gasDetected && flameDetected) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(fanPin, HIGH);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("ALERT: GAS & FLAME");
    Serial.println("Gas and Flame Detected!");
    playAlertTone();
  } 
  else if (gasDetected) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(fanPin, HIGH);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("ALERT: GAS Detected");
    Serial.println("Gas Detected!");
    playAlertTone();
  } 
  else if (flameDetected) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(fanPin, LOW);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("ALERT: Flame Detected");
    Serial.println("Flame Detected!");
    playAlertTone();
  } 
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(fanPin, LOW);
    noTone(buzzerPin);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("Status: All Safe");
    Serial.println("All Safe");
  }

  display.display(); // Update OLED
  delay(200);        // Prevent spam
}
