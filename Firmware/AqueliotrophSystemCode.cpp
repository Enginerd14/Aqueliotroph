#include <LiquidCrystal.h>
#include <Servo.h>

//Pins

LiquidCrystal lcd(11,10,5,4,3,2);

Servo myservo;
const int ServoPin = 9;

//Sensors
const int ldrPin = A0;
const int moisturePin = A1;

//Limti Switches
const int LlimitPin = A2;
const int RlimitPin = A3;

//Pulley motor
const int motorIN1 = 8;
const int motorIN2 = 7;
const int motorEN = 6;

//Pump
const int motorIN3 = 12;
const int motorIN4 = 13;

//Settings
const int moistureThreshold = 700;
const int lightChangeLimit = 50;

//Pos Settings
const int moveTime = 800; // time in ms betwwen positions

int currentPos = 1;
int bestPos = 1;
int prevLight = 0;

unsigned long lastSearch = 0;
unsigned long searchInterval = 300000; // 300000ms = 5 mins

void setup() {
    Serial.begin(9600);

    lcd.begin(16,2);
    lcd.print("Aqueliotroph system starting...");
    delay(2000);
    lcd.clear();

    pinMode(LlimitPin, INPUT_PULLUP);
    pinMode(RlimitPin, INPUT_PULLUP);

    pinMode(motorIN1, OUTPUT);
    pinMode(motorIN2, OUTPUT);
    pinMode(motorEN, OUTPUT);

    pinMode(motorIN3, OUTPUT);
    pinMode(motorIN4, OUTPUT);

    stopCarriageMotor();
    stopPump();

    Calibrate();

    prevLight = analogRead(ldrPin);

    SunScan();
}

void loop() {
    int light = analogRead(ldrPin);

    if(abs(light - prevLight) > lightChangeLimit) {
        SunScan();
        prevLight = light;
    }

    if (millis() - lastSearch > searchInterval) {
        SunScan();
        lastSearch = millis();
        prevLight = analogRead(ldrPin);
    }

    checkMoisture();
    displayInfo();
    delay(500);
}

// Scanning for Sun

void SunScan() {
    lcd.clear();
    lcd.print("Scanning for best light...");

    int bestLight = 0;
    bestPos = 1;

    for (int pos =1; pos <=5; pos++) {
        moveToPosition(pos);

        delay(500);

        int light = analogRead(ldrPin);

        Serial.print("Position ");
        Serial.print(pos);
        Serial.print(" = ");
        Serial.println(light);

        if (light > bestLight) {
            bestLight = light;
            bestPos = pos;

        }
    }

    moveToPosition(bestPos);

    lcd.clear();
    lcd.print("Best Position:");
    lcd.setCursor(0,1);
    lcd.print(bestPos);

    delay(2000);
}

//Positioning

void moveToPosition(int targetPosition) {
    while (currentPos < targetPosition) {
        moveOneRight();
        currentPos++;
    }
    while (currentPos > targetPosition) {
        moveOneLeft();
        currentPos--;
    }
}

void moveOneRight() {
    if (digitalRead(RlimitPin) == LOW) {
        stopCarriageMotor();
        return;
    }

    digitalWrite(motorIN1, HIGH);
    digitalWrite(motorIN2, LOW);
    analogWrite(motorEN, 180);

    delay(moveTime);

    stopCarriageMotor();

    delay(300);
}

void moveOneLeft() {
    if (digitalRead(LlimitPin) == LOW) {
        stopCarriageMotor();
        return;
    }

    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, HIGH);
    analogWrite(motorEN, 180);

    delay(moveTime);

    stopCarriageMotor();

    delay(300);
}

void stopCarriageMotor() {
    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, LOW);
    analogWrite(motorEN, 0);
}

//Calibrate

void Calibrate() {
    lcd.clear();
    lcd.print("Calibrating...");

    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, HIGH);
    analogWrite(motorEN, 180);

    while (digitalRead(LlimitPin) == HIGH) {
        delay(10);
    }

    stopCarriageMotor();

    currentPos = 1;

    lcd.clear();
    lcd.print("Found Home");
    delay(1000);
}

// Watering

void checkMoisture() {
    int moisture = analogRead(moisturePin);

    if (moisture > moistureThreshold){
        waterPlant();
    }
}

void waterPlant() {
    lcd.clear();
    lcd.print("Watering...");

    Serial.println("Pump is on");

    digitalWrite(motorIN3, HIGH);
    digitalWrite(motorIN4, LOW);

    delay(3000);

    stopPump();

    Serial.println("Pump is off");

    delay(1000);
}

void stopPump() {
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, LOW);    
}

// Display on LCD

void displayInfo() {
    int light = analogRead(ldrPin);
    int moisture = analogRead(moisturePin);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Light:");
    lcd.print(light);
    Serial.print("Light: ");
    Serial.print(light);

    lcd.setCursor(9, 0);
    lcd.print("Pos:");
    lcd.print(currentPos);
    Serial.print(" Position: ");
    Serial.println(currentPos);

    lcd.setCursor(0, 1);
    lcd.print("Moisture:");
    lcd.print(moisture);
    Serial.print(" Moisture: ");
    Serial.print(moisture);
}