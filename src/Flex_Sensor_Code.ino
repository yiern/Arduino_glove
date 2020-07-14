/**************************
Create a voltage divider circuit combining a flex sensor with a 10k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 3.3V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.
**************************/
#include <SoftwareSerial.h>
#include <Arduino.h>
SoftwareSerial BT(2, 3);

const int FLEX_PIN0 = A0; //Pin connected to voltage divider output (1418)
const int FLEX_PIN1 = A1; //Pin connected to volatge divider output (0918)
const int FLEX_PIN4 = A4;
const int FLEX_PIN5 = A3;
const int FLEX_PIN6 = A2;

//Measure the voltage at 5V and the actual resistance of your
//10k resistor, and enter them below:

const float VCC = 5.03; //Measured voltage of Ardunio 5V line
const float R_DIV0 = 9800.0; //Measured resistance of 10k resistor for PIN0
const float R_DIV1 = 9800.0; //Measured resistance of 10k resistor for PIN1

//Upload the code, then try to adjust these values to more
//accurately calculate bend degree.
const float STRAIGHT_RESISTANCE0 = 11350.0 ; //resistance when straight for PIN0
const float BEND_RESISTANCE0 = 39400.0; //resistance at 90 deg for PIN0
const float STRAIGHT_RESISTANCE1 = 18000.0 ; //resistance when straight for PIN1
const float BEND_RESISTANCE1 = 52400.0; //resistance at 90 deg for PIN1
const float STRAIGHT_RESISTANCE4 = 9800.0 ; //resistance when straight for PIN4
const float BEND_RESISTANCE4 = 19400.0; //resistance at 90 deg for PIN4
const float STRAIGHT_RESISTANCE5 = 94000.0 ; //resistance when straight for PIN4
const float BEND_RESISTANCE5 = 145000.0; //resistance at 90 deg for PIN4
const float STRAIGHT_RESISTANCE6 = 11170.0 ; //resistance when straight for PIN6
const float BEND_RESISTANCE6 = 22000.0; //resistance at 90 deg for PIN6



void setup() 
{
  pinMode(FLEX_PIN0, INPUT);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN4, INPUT);
  pinMode(FLEX_PIN5, INPUT);
  pinMode(FLEX_PIN6, INPUT);
  Serial.begin(9600);
  BT.begin(9600);
  
}

void loop() 
{
  //Read the ADC, and calculate voltage and resistance from it for PIN0
  int flexADC0 = analogRead(FLEX_PIN0);
  float flexV0 = flexADC0 * VCC / 1023.0;
  float flexR0 = R_DIV0 * (VCC / flexV0 - 1.0);


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float angle0 = map(flexR0, STRAIGHT_RESISTANCE0, BEND_RESISTANCE0, 0, 90.0);

  //Serial.println("index " + String(angle0));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //Read the ADC, and calculate voltage and resistance from it for PIN1
  int flexADC1 = analogRead(FLEX_PIN1);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV1 * (VCC / flexV1 - 1.0);
  


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE1, BEND_RESISTANCE1, 0, 90.0);

   //Serial.println("middle " + String(angle1));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //Read the ADC, and calculate voltage and resistance from it for PIN4
  int flexADC4 = analogRead(FLEX_PIN4);
  float flexV4 = flexADC4 * VCC / 1023.0;
  float flexR4 = R_DIV0 * (VCC / flexV4 - 1.0);



  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float angle4 = map(flexR4, STRAIGHT_RESISTANCE4, BEND_RESISTANCE4, 0, 90.0);

  //Serial.println("ring " + String(angle4));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Read the ADC, and calculate voltage and resistance from it for PIN5
  int flexADC5 = analogRead(FLEX_PIN5);
  float flexV5 = flexADC5 * VCC / 1023.0;
  float flexR5 = R_DIV0 * (VCC / flexV5 - 1.0);
  


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float angle5 = map(flexR5, STRAIGHT_RESISTANCE5, BEND_RESISTANCE5, 0, 90.0);

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  int flexADC6 = analogRead(FLEX_PIN5);
  float flexV6 = flexADC5 * VCC / 1023.0;
  float flexR6 = R_DIV0 * (VCC / flexV6 - 1.0);
  


  //Use the calculated resistance to estimate the sensor's
  //bend angle:
  float angle6 = map(flexR6, STRAIGHT_RESISTANCE6, BEND_RESISTANCE6, 0, 90.0);

 Serial.println(String(angle0) + ","  + String(angle1) +  "," + String(angle4)+ "," + String(angle5)+ "," + String(angle6));
  
  BT.println(String(angle0) + "," + String(angle6) + "," + String(angle1) + "," + String("0")+ "," + String(angle4)+ "," + String(angle5));
  
  delay(500); //delay 5 sec before sending sensor 2 data
  //added mk.1
}
