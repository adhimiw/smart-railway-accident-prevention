/*
 * Smart Railway Station Accident Prevention System
 * 
 * This Arduino code controls an accident prevention system using:
 * - Ultrasonic sensor (HC-SR04) for distance detection
 * - Servo motor (SG90) for barrier control
 * 
 * Author: Adhithan Dev
 * Date: March 22, 2023
 * 
 * Hardware Connections:
 * - Ultrasonic Sensor HC-SR04:
 *   VCC -> 5V
 *   GND -> GND
 *   Trig -> Digital Pin 7
 *   Echo -> Digital Pin 6
 * 
 * - Servo Motor SG90:
 *   VCC -> 5V
 *   GND -> GND
 *   Signal -> Digital Pin 9
 */

#include <Servo.h>

// Pin definitions
const int trigPin = 7;      // Ultrasonic sensor trigger pin
const int echoPin = 6;      // Ultrasonic sensor echo pin
const int servoPin = 9;     // Servo motor signal pin
const int buzzerPin = 8;    // Buzzer pin (optional)
const int ledPin = 13;      // LED indicator pin

// Create servo object
Servo barrierServo;

// System parameters
const int DANGER_DISTANCE = 30;    // Distance in cm to trigger safety protocol
const int SAFE_DISTANCE = 50;      // Distance in cm to consider area safe
const int BARRIER_CLOSED = 90;     // Servo angle for closed barrier
const int BARRIER_OPEN = 0;        // Servo angle for open barrier

// System variables
long duration;
int distance;
bool barrierState = false;  // false = open, true = closed
bool systemActive = true;
unsigned long lastDetectionTime = 0;
const unsigned long DETECTION_DELAY = 1000; // 1 second delay between detections

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Smart Railway Accident Prevention System");
  Serial.println("Initializing...");
  
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // Initialize servo
  barrierServo.attach(servoPin);
  barrierServo.write(BARRIER_OPEN);  // Start with barrier open
  
  // System startup indication
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  
  Serial.println("System Ready!");
  Serial.println("Monitoring area for safety...");
  Serial.println("----------------------------");
}

void loop() {
  if (systemActive) {
    // Read distance from ultrasonic sensor
    distance = getDistance();
    
    // Check if enough time has passed since last detection
    if (millis() - lastDetectionTime > DETECTION_DELAY) {
      
      // Analyze distance and take appropriate action
      if (distance > 0 && distance <= DANGER_DISTANCE) {
        // Danger detected - activate safety protocol
        activateSafetyProtocol();
        lastDetectionTime = millis();
      }
      else if (distance > SAFE_DISTANCE && barrierState) {
        // Area is safe - deactivate safety protocol
        deactivateSafetyProtocol();
        lastDetectionTime = millis();
      }
    }
    
    // Print status every 2 seconds
    static unsigned long lastPrintTime = 0;
    if (millis() - lastPrintTime > 2000) {
      printSystemStatus();
      lastPrintTime = millis();
    }
  }
  
  delay(100); // Small delay for system stability
}

// Function to measure distance using ultrasonic sensor
int getDistance() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in centimeters
  int calculatedDistance = duration * 0.034 / 2;
  
  // Return valid distance (filter out invalid readings)
  if (calculatedDistance > 0 && calculatedDistance < 400) {
    return calculatedDistance;
  }
  return -1; // Invalid reading
}

// Function to activate safety protocol
void activateSafetyProtocol() {
  if (!barrierState) {
    Serial.println("⚠️  DANGER DETECTED! ⚠️");
    Serial.print("Object detected at distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("Activating safety barrier...");
    
    // Close the barrier
    barrierServo.write(BARRIER_CLOSED);
    barrierState = true;
    
    // Activate warning indicators
    activateAlarm();
    
    Serial.println("✅ Safety barrier activated!");
  }
}

// Function to deactivate safety protocol
void deactivateSafetyProtocol() {
  if (barrierState) {
    Serial.println("✅ Area clear - deactivating safety protocol");
    
    // Open the barrier
    barrierServo.write(BARRIER_OPEN);
    barrierState = false;
    
    // Deactivate warning indicators
    deactivateAlarm();
    
    Serial.println("🔓 Safety barrier opened - normal operation resumed");
  }
}

// Function to activate alarm (buzzer and LED)
void activateAlarm() {
  // Flash LED and sound buzzer
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}

// Function to deactivate alarm
void deactivateAlarm() {
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

// Function to print system status
void printSystemStatus() {
  Serial.print("Distance: ");
  if (distance > 0) {
    Serial.print(distance);
    Serial.print(" cm");
  } else {
    Serial.print("No reading");
  }
  
  Serial.print(" | Barrier: ");
  Serial.print(barrierState ? "CLOSED" : "OPEN");
  
  Serial.print(" | Status: ");
  if (distance > 0 && distance <= DANGER_DISTANCE) {
    Serial.println("⚠️  DANGER ZONE");
  } else if (distance > SAFE_DISTANCE || distance == -1) {
    Serial.println("✅ SAFE");
  } else {
    Serial.println("🔍 MONITORING");
  }
}

// Function to handle emergency stop (can be triggered by external input)
void emergencyStop() {
  systemActive = false;
  barrierServo.write(BARRIER_CLOSED);
  barrierState = true;
  
  Serial.println("🚨 EMERGENCY STOP ACTIVATED 🚨");
  Serial.println("System halted - manual intervention required");
  
  // Continuous alarm
  while (!systemActive) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
}

// Function to reset system (can be called to restart normal operation)
void resetSystem() {
  systemActive = true;
  barrierServo.write(BARRIER_OPEN);
  barrierState = false;
  deactivateAlarm();
  
  Serial.println("🔄 System reset - resuming normal operation");
}
