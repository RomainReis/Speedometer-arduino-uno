#include <LiquidCrystal.h>          //the liquid crystal libarry contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   /
const int trigPin = 5;
const int echoPin = 6;


long duration;
int FirstDistance=0;
int SecondDistance=0;
double speed=0;
int distance=1;
float Time = 0.5;
float delayedtime = 1000*Time;

void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
lcd.clear();                      //clear the display
Serial.begin(9600); 
}


void loop()
{
GetSpeed();
lcd.setCursor(0,0);               
lcd.print("Speed in cm/s");       

}

float GetDistance()
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

return distance;

}
void GetSpeed(){
 
   FirstDistance = GetDistance(); //get the first distance
   
   delay(delayedtime); 
   
   SecondDistance = GetDistance(); //gets the second distance
   
   speed = ((FirstDistance - SecondDistance)/Time);  
   
 
//printing the speed on the serial monitor
//Serial.print("the speed (kM/H) is  :  ");
  Serial.println(speed);
  
lcd.setCursor(0,1);               //movee the cursor to the first space of the bottom row
lcd.print(speed);         //print speed

}
