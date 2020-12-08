



// Example_1 - blink LED (classic method - no use of SchedTask Task Scheduler yet)
/*		Use of delay() in loop()

	 For the complete series of tutorials see
	 https://www.youtube.com/watch?v=nZHBbSkVUSo&list=PL69rZyCQYu-SrPAZUc2Lj_zsjPLxtI9fv

	 For this example see
	 see https://www.youtube.com/watch?v=nZHBbSkVUSo&t=7s

/*
Change Log

	4/16/2020 11:57AM Initial Release
	05/17/2020 20:54 moved ExampleConstants.h
	09/16/2020 16:25 remove SoftwareSerial.h
*/

const char CAPTION[] = "Example 1 Blink LED classic method";

#include <ExampleConstants.h>
#include <LiquidCrystal.h> 
#include <dht.h>					
#define LED_PIN1 13
#define LED_PIN2 12
#define LED_PIN3 11
#define Sensor_pin A0
#define Sensor_pin1 A1
int Read_Voltage  = A0;
int Read_Current  = A0;
int sensorValue;
int sensorPin;
const int rs = 3, en = 4, d4 = 8, d5 = 9, d6 = 10, d7 = 11; //Mention the pin number for LCD connection
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT; 
// contains various constants used to control the sketch behavior

/********************  Setup() **************************/
void setup() {
  lcd.begin(16, 2); //Initialise 16*2 LCD

  lcd.print(" Arduino Wattmeter"); //Intro Message line 1
  lcd.setCursor(0, 1);
  lcd.print("  With Arduino  "); //Intro Message line 2

  delay(2000);
  lcd.clear();
	Serial.begin(UART_SPEED);										// init the Monitor window
	Serial << "\n*** SchedTask " << CAPTION << " ***\n";	// Welcome message to monitor

	pinMode(LED_PIN1, OUTPUT);	
	pinMode(LED_PIN2, OUTPUT);  
	pinMode(LED_PIN3, OUTPUT);
	pinMode(Sensor_pin, OUTPUT);
	pinMode(Sensor_pin1, OUTPUT);// initialize the hardware pin
}

/******************* Loop() ********************************/

void loop() {

	turnOnLED1();														// turn on the LED
	delay (1000);														// leave it on for 1 sec
	turnOffLED1();														// turn off the LED
	delay (2000);	
  turnOnLED2();                            // turn on the LED
  delay (1000);                           // leave it on for 1 sec
  turnOffLED2();                           // turn off the LED
  delay (2000); 
  turnOnLED3();                            // turn on the LED
  delay (1000);                           // leave it on for 1 sec
  turnOffLED3();                           // turn off the LED
  delay (2000);
  turnOnSensor();                            // turn on the LED
  delay (1000);                           // leave it on for 1 sec
  turnOffSensor();                           // turn off the LED
  delay (2000); 
  turnOnSensor1();                            // turn on the LED
  delay (1000);                           // leave it on for 1 sec
  turnOffSensor1();                           // turn off the LED
  delay (2000); 
// leave it off for 2 sec
   float Voltage_Value = analogRead(Read_Voltage);
 float Current_Value = analogRead(Read_Current);

 Voltage_Value = Voltage_Value;
 Current_Value = Current_Value;

 lcd.setCursor(0, 0);
 lcd.print("V="); lcd.print(Voltage_Value); 
 lcd.print("  "); 
 lcd.print("I=");lcd.print(Current_Value); 

 float Power_Value = Voltage_Value * Current_Value;

 lcd.setCursor(0, 1);
 lcd.print("Power="); lcd.print(Power_Value); 

 
delay(200);
}

/********************* Functions ************************************/

// turn the LED on

void turnOnLED1() {

	digitalWrite(LED_PIN1, ON);										// turn on the LED
	if (OUTPUT_ENABLED) Serial << "\n\n" << millis() << " On";
}

// turn the LED off

void turnOffLED1() {

	digitalWrite(LED_PIN1, OFF);									// turn off the LED
	if (OUTPUT_ENABLED) Serial << "\n" << millis() << " Off";
}

void turnOnLED2() {

  digitalWrite(LED_PIN2, ON);                    // turn on the LED
  if (OUTPUT_ENABLED) Serial << "\n\n" << millis() << " On";
}

// turn the LED off

void turnOffLED2() {

  digitalWrite(LED_PIN2, OFF);                 // turn off the LED
  if (OUTPUT_ENABLED) Serial << "\n" << millis() << " Off";
}

void turnOnLED3() {

  digitalWrite(LED_PIN3, ON);                    // turn on the LED
  if (OUTPUT_ENABLED) Serial << "\n\n" << millis() << " On";
}

// turn the LED off

void turnOffLED3() {

  digitalWrite(LED_PIN3, OFF);                 // turn off the LED
  if (OUTPUT_ENABLED) Serial << "\n" << millis() << " Off";
}

void turnOnSensor() {

  digitalWrite(Sensor_pin, ON);                   // turn on the LED
  if (OUTPUT_ENABLED) Serial << "\n\n" << millis() << " On";
}

// turn the LED off

void turnOffSensor() {

  digitalWrite(Sensor_pin, OFF); 
   
   sensorValue = analogRead(sensorPin); 
   lcd.println(" Analog Value : ");
   lcd.println(sensorValue);// turn off the LED
  if (OUTPUT_ENABLED) Serial << "\n" << millis() << " Off";
}
// turn the LED off

void turnOnSensor1() {

  digitalWrite(Sensor_pin1, ON); 
   lcd.print(" Current humidity = ");
    lcd.print(DHT.humidity);
    lcd.print("%  ");
    lcd.print("temperature =  ");
    lcd.print(DHT.temperature); 
    lcd.println("C  ");// turn on the LED
  if (OUTPUT_ENABLED) Serial << "\n\n" << millis() << " On";
}

// turn the LED off

void turnOffSensor1() {

  digitalWrite(Sensor_pin1, OFF);                  // turn off the LED
  if (OUTPUT_ENABLED) Serial << "\n" << millis() << " Off";
}
