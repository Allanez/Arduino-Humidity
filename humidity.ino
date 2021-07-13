#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,20,4);  

dht DHT;

//pin definitions
#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);

  // initialize the LCD
  lcd.begin();

  // Print a message to the LCD.
  lcd.backlight();
}

void loop(){
  // Read data from sensor
  int chk = DHT.read11(DHT11_PIN);
  
  //Show temp data on line 1
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223); // ° symbol
  lcd.print("C");
  
  //Show humidity data on line 2
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  //Sleep
  delay(1000);
}
