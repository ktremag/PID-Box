#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);	//I2C address of the lcd backpack
int potPin = 3; //potentiometer
int moPin = 9;  //motor
int pintPin1 = 2;  //photo interrupter pin 1
int pintPin2 = 3;

unsigned long int rpm; //rotations per minute
unsigned long timeRev; //time per revolution
unsigned long prev, curr; //previous & current times 
int t = 0;
int count =0;
int calcu = 0;


void setup()
{
  	Serial.begin(9600);

  	//LCD Stuff
	lcd.init();
	lcd.backlight();

	//variables
	rpm = 0;
	time = 0;
	prev = 0; 
  	//PinModes etc.
  	pinMode(potPin, INPUT); //potentiometer = input
  	pinMode(moPin, OUTPUT); //motor = output
  	pinMode(pintPin1, INPUT_PULLUP);
    pinMode(pintPin2, INPUT_PULLUP);
  	
  	//Interrupts for photoint
  	attachInterrupt(digitalPinToInterrupt(pintPin2), on, RISING);
  } 
  
void on (){
	count ++;
}

int calcRPM(){
	rpm = 30*1000/count*(millis()-timeRev);
	timeRev = millis();
	count = 0; 
	prev = curr; 
	delay(500);

	return rpm; 
}
void loop()
{

	//motor control
	t = (analogRead(potPin))/4;
	analogWrite(moPin, t);  
	delay(200);
	//Serial.println(t);

	//timing & RPM
	curr = millis();
	long idle = curr-prev; 

	//LCD
	lcd.setCursor(0, 0);
		lcd.print("setting" + t);

	//after 5 interrupts, calculate rpm
	if (count >= 5){
		int R = calcRPM();
		Serial.println(R);
		lcd.print("rpm:" + R)
	}
	

} 

