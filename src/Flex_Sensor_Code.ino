/**************************
Create a voltage divider circuit combining a flex sensor with a 10k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 3.3V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.
**************************/
#include <SoftwareSerial.h>
#include <Arduino.h>
SoftwareSerial BT(2, 3); // rx,tx

const int THUMB = A0; //thumb
const int INDEX = A1; //index
const int PINKY = A4; //pinky
const int RING = A3; //ring
const int MIDDLE = A2; //middle

//Measure the voltage at 5V and the actual resistance of your
//10k resistor, and enter them below:

const float VCC = 5.03; //Measured voltage of Ardunio 5V line
const float R_DIV0 = 9800.0; //Measured resistance of 10k resistor for PIN0
const float R_DIV1 = 9800.0; //Measured resistance of 10k resistor for PIN1

//Upload the code, then try to adjust these values to more
//accurately calculate bend degree.
const float Thumb_StraightResistance      = 94000.0; //resistance when straight for PIN0
const float Thumb_BendResistance          = 113000.0; //resistance at 90 deg for PIN0
const float Index_StraightResistance      = 13590.0; //resistance when straight for PIN1
const float Index_BendResistance          = 32000.0; //resistance at 90 deg for PIN1
const float Pinky_StraightResistance      = 12000.0 ; //resistance when straight for PIN4
const float Pinky_BendResistance          = 30000.0; //resistance at 90 deg for PIN4
const float Ring_StraightResistance       = 23500.0 ; //resistance when straight for PIN4
const float Ring_BendResistance           = 73500.0; //resistance at 90 deg for PIN4
const float Middle_StraightResistance     = 11070.0 ; //resistance when straight for PIN6
const float Middle_BendResistance         = 23000.0; //resistance at 90 deg for PIN6
 


void setup() 
{
  pinMode(THUMB, INPUT);
  pinMode(INDEX, INPUT);
  pinMode(PINKY, INPUT);
  pinMode(RING, INPUT);
  pinMode(MIDDLE, INPUT);
  Serial.begin(9600);
  BT.begin(9600);
  
}

void loop() 
{
  //Read the ADC, and calculate voltage and resistance from it for PIN0
  int flexADC0 = analogRead (THUMB);
  float flexV0 = flexADC0 * VCC / 1023.0;
  float flexR0 = R_DIV0 * (VCC / flexV0 - 1.0);


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float Thumb_Angle = map(flexR0, Thumb_StraightResistance, Thumb_BendResistance, 0, 90.0);

  //Serial.println("index " + String(Thumb_Angle));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //Read the ADC, and calculate voltage and resistance from it for PIN1
  int flexADC1 = analogRead(INDEX);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV1 * (VCC / flexV1 - 1.0);
  


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float Index_Angle = map(flexR1, Index_StraightResistance, Index_BendResistance, 0, 90.0);

   //Serial.println("middle " + String(Index_Angle));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //Read the ADC, and calculate voltage and resistance from it for PIN4
  int flexADC4 = analogRead(PINKY);
  float flexV4 = flexADC4 * VCC / 1023.0;
  float flexR4 = R_DIV0 * (VCC / flexV4 - 1.0);



  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float Pinky_Angle = map(flexR4, Pinky_StraightResistance, Pinky_BendResistance, 0, 90.0);

  //Serial.println("ring " + String(Pinky_Angle));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Read the ADC, and calculate voltage and resistance from it for PIN5
  int flexADC5 = analogRead(RING);
  float flexV5 = flexADC5 * VCC / 1023.0;
  float flexR5 = R_DIV0 * (VCC / flexV5 - 1.0);
  


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float Ring_Angle = map(flexR5, Ring_StraightResistance, Ring_BendResistance, 0, 90.0);

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  int flexADC6 = analogRead(MIDDLE);
  float flexV6 = flexADC6 * VCC / 1023.0;
  float flexR6 = R_DIV0 * (VCC / flexV6 - 1.0);
  


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float Middle_Angle = map(flexR6, Middle_StraightResistance, Middle_BendResistance, 0, 90.0);

//Serial.println("Thumb Reading: " + String(Thumb_Angle) + ", Index Reading: "  + String(Index_Angle) +  ", Middle Reading: " + String(Middle_Angle)+ ", Ring Reading: " + String(Ring_Angle)+ ", Pinky reading: " + String(Pinky_Angle));
  
BT.println(String(Thumb_Angle) + "," + String(Index_Angle) + "," + String(Middle_Angle) + "," + String(Ring_Angle)+ "," + String(Pinky_Angle));

  
  
  delay(500); //delay 1/2 sec before sending sensor 2 data
}
