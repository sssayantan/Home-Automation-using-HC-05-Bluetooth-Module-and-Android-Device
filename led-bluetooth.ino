#include <SoftwareSerial.h>

#include <Servo.h>

Servo myservo;

int bluetoothTx = 10;

int bluetoothRx = 11;
char junk;
String inputString="";
int sensorPin1 = A0; // select the input pin for the LDR
int sensorValue1 = 0; // variable to store the value coming from the sensor
int led1 = 3;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup1()                    // run once, when the sketch starts
{pinMode(led1, OUTPUT);

 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(13, OUTPUT);
 
}
void setup2()

{

myservo.attach(9);


Serial.begin(9600);


bluetooth.begin(9600);

}
void loop1()
{
Serial.println("hi");
sensorValue1 = analogRead(sensorPin1);
Serial.println(sensorValue1);
if (sensorValue1 < 100)
{
Serial.println("LED light on");
digitalWrite(led1,HIGH);
delay(1000);
}
digitalWrite(led1,LOW);
delay(sensorValue1);
  
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    if(inputString == "a"){         //in case of 'a' turn the LED on
      digitalWrite(13, HIGH);  
    }else if(inputString == "b"){   //incase of 'b' turn the LED off
      digitalWrite(13, LOW);
    }
    inputString = "";
  }
}

int sensorPin2 = A0; // select the input pin for the LDR
int sensorValue2 = 0; // variable to store the value coming from the sensor
int led2 = 3;
void setup3() { // declare the ledPin as an OUTPUT:
pinMode(led2, OUTPUT);
Serial.begin(9600); }
void loop2()
{
Serial.println("Welcome to TechPonder LDR Tutorial");
sensorValue2 = analogRead(sensorPin2);
Serial.println(sensorValue2);
if (sensorValue2 < 100)
{
Serial.println("LED light on");
digitalWrite(led2,HIGH);
delay(1000);
}
digitalWrite(led2,LOW);
delay(sensorValue2);
}

void loop3()

{


if(bluetooth.available()> 0 )

{

int servopos = bluetooth.read();

Serial.println(servopos);

myservo.write(servopos);

}

}