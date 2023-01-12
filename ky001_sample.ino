// Required libraries will be imported
#include <OneWire.h>
#include <DallasTemperature.h>

// temp sensor data pin
#define KY001_Signal_PIN 4

// library configurations
OneWire oneWire(KY001_Signal_PIN);

DallasTemperature sensors(&oneWire);

// rgb color pins
int led_red = 10;
int led_green = 11;
int led_blue = 12;

void setup() {
  // initialize serial output
  Serial.begin(9600);
  Serial.println("KY-001 temperature measurement");

  // initialize pins for rgb led as output
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);

  // sensor initialization
  sensors.begin();
}

void loop() {
  // start temperature measurement
  sensors.requestTemperatures();

  // output sensor data
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" °C");

  // change color depending on temperature
  if (sensors.getTempCByIndex(0) > 50) {
    // color: red
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, LOW);
  } else if (sensors.getTempCByIndex(0) < 50 && sensors.getTempCByIndex(0) > 40) {
    // color:  green
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_blue, LOW);
  } else if (sensors.getTempCByIndex(0) < 40) {
    // color:  blue
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, HIGH);
  }

  // wait 1 second
  delay(1000);
}