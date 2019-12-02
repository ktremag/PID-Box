#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);	//I2C address of the lcd backpack
int potPin = 3; //potentiometer
int moPin = 9;  //motor
int pintPin1 = 2;  //photo interrupter pin 1
int pintPin2 = 3;

unsigned long int rpm; //rotations per minute
unsigned long time; //time per revolution
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
  	//pinMode(pintPin1, INPUT_PULLUP);
    	pinMode(pintPin2, INPUT_PULLUP);
  	
  	//Interrupts for photoint
  	attachInterrupt(digitalPinToInterrupt(pintPin2), on, RISING);
  } 
  
void on (){
	count ++;
}

int calcRPM(){
	rpm = (count/2)*300;
	count = 0; 
	prev = curr;  
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
	time = curr-prev; 

	//LCD
	lcd.setCursor(0, 0);
	lcd.print("setting" + t);

	//after 5 interrupts, calculate rpm
	if (time >= 200){
		int R = calcRPM();
		Serial.println(R);
		lcd.print("rpm:" + R)
	}
	

} 