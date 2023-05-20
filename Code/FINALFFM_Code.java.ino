/*
Creator: Wilson Dhalwani
Date Started: 1/29/2022
Date Ended: 2/14/2022
Version: 1.0
Help Cited: Wilson Dhalwani & Mr. Carlos Nodarse
*/

// preproccesor for digital gas sensor
#define MQ2pin (0)
float sensorValue;

//-------------------------------------

// Pin announcment for analog temp sensor
int sensorPin = A1;

void setup()
{

  // gas sensor
  Serial.begin(9600);                       // sets the serial port to 9600
  Serial.println("Gas sensor warming up!"); // warmup message

  //-----------------------------------

  // temp sensor sensor
  Serial.begin(9600);
  Serial.println("Temp sensor warming up!"); // warmup message

  //-----------------------------------

  delay(3000); // allows the sensors to warm up
}

void loop()
{

  // gas sensor MQ2 CODE
  sensorValue = analogRead(MQ2pin); // read analog input pin 0

  Serial.print("Gas Sensor Value: ");
  Serial.print(sensorValue); // prints gas sensor value

  if (sensorValue > 700) // increased tolerance
  {
    Serial.print(" | Possible Smoke detected!"); // prints warning based off of sensor values
  }

  Serial.println("");
  // delay(2000); // wait 2s for next reading

  //--------------------------------------

  // TEMP SENSOR Analog
  int reading = analogRead(sensorPin); // reads data from sensor to analog pin
  float voltz = reading * 5.0;
  voltz /= 1024.0;

  // Serial.print(voltage); Serial.print(" volts");  //for testing purposes

  float temperatureC = (voltz - 0.5) * 100; // converts voltz value to celsius

  // Serial.print(temperatureC); Serial.print(" degrees C"); //for testing purposes

  float temperatureF = (temperatureC * 9.0 / 55.0) + 32.0; // converts celsius to farenhiet

  Serial.print(temperatureF);
  Serial.print(" degrees F"); // prints farenhit values from sensor

  Serial.println(""); // formatting

  delay(2000); // wait two seconds
}
