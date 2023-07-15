/*
Created by Niles and Christopher, ft. William
NOTE TO ASSEMBLER: Relay must be connected to an external source
NOTE TO 
*/

// Various libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <arduino-timer.h>
#include <spi.h>
#include <wire.h>
#include <Filter.h>

const float max_voltage = 5.0; //set maximum capacitor capacity
const float min_total = 2.0;  //set minimum capacitor total

//Filters for voltage readers
ExponentialFilter<long> Filter0(10, 0);
ExponentialFilter<long> Filter1(10, 0);
ExponentialFilter<long> Filter2(10, 0);
ExponentialFilter<long> Filter3(10, 0);
ExponentialFilter<long> Filter4(10, 0);
ExponentialFilter<long> Filter5(10, 0);
float temp0 = 0.0;
float temp1 = 0.0;
float temp2 = 0.0;
float temp3 = 0.0;
float temp4 = 0.0; 
float temp5 = 0.0; 

// Relay pins
const int relay1 = 4;
const int relay2 = 2;

const int divisor = 4.6753;

int signal_pin = 0;

// Voltage reader pins
#define ANALOG_IN_PIN0 A0
#define ANALOG_IN_PIN1 A1
#define ANALOG_IN_PIN2 A2
#define ANALOG_IN_PIN3 A3
#define ANALOG_IN_PIN4 A4
#define ANALOG_IN_PIN5 A5


// Voltage reader offset
const float offset = -0.35;

// Timer for voltage readings
Timer<1> timer; // single timer in miliseconds

// Floats for ADC voltage & CAP voltage
float cap_voltage0 = 0.0;
float cap_voltage1 = 0.0;
float cap_voltage2 = 0.0;
float cap_voltage3 = 0.0;
float cap_voltage4 = 0.0;
float cap_voltage5 = 0.0;

float cap_totvoltage = 0;

// Floats for resistor values in voltage divider (in ohms)

// Function for reading capacitor voltages (timer dep)
void readCapacitors() {  
  delay(500);
  Serial.println(" ");

  Filter0.Filter(analogRead(0));
  cap_voltage0 = Filter0.Current();
  temp0=cap_voltage0/divisor;
  cap_voltage0 =(temp0/10.0) + offset;
  Serial.print("Capacitor 1 Input Voltage = ");
  Serial.println(cap_voltage0);

  Filter1.Filter(analogRead(1));
  cap_voltage1 = Filter1.Current();
  temp1=cap_voltage1/divisor;
  cap_voltage1 =(temp1/10.0) + offset;
  Serial.print("Capacitor 2 Input Voltage = ");
  Serial.println(cap_voltage1);

  Filter2.Filter(analogRead(2));
  cap_voltage2 = Filter2.Current();
  temp2=cap_voltage2/divisor;
  cap_voltage2 =(temp2/10.0) + offset;
  Serial.print("Capacitor 3 Input Voltage = ");
  Serial.println(cap_voltage2);

  Filter3.Filter(analogRead(3));
  cap_voltage3 = Filter3.Current();
  temp3=cap_voltage3/divisor;
  cap_voltage3 =(temp3/10.0) + offset;
  Serial.print("Capacitor 4 Input Voltage = ");
  Serial.println(cap_voltage3);

  Filter4.Filter(analogRead(4));
  cap_voltage4 = Filter4.Current();
  temp4=cap_voltage4/divisor;
  cap_voltage4 =(temp4/10.0) + offset;
  Serial.print("Capacitor 5 Input Voltage = ");
  Serial.println(cap_voltage4);

  Filter5.Filter(analogRead(5));
  cap_voltage5 = Filter5.Current();
  temp5=cap_voltage5/divisor;
  cap_voltage5 =(temp5/10.0) + offset;
  Serial.print("Capacitor 6 Input Voltage = ");
  Serial.println(cap_voltage5);
  
}


  void setup() 
  {
  // Initializing components
  Serial.begin(9600);      // Serial Monitor
  pinMode(relay1, OUTPUT); // charge relay
  pinMode(relay2, OUTPUT); // discharge relay

  // Voltage readings on Serial Monitor
  Serial.println("Calibrating voltage filter");
  Filter0.Filter(analogRead(0));
  delay(100); 
  Filter0.Filter(analogRead(0));
  Serial.println(".");
  delay(100);
  Filter0.Filter(analogRead(0));
  Serial.println(".");
  delay(100);
  Filter0.Filter(analogRead(0));
  Serial.println(".");
  delay(100);
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  Filter0.Filter(analogRead(0));
  delay(1000);


}

// cycle state flags

bool allow_charge = false;
bool allow_discharge = false;

//******************************************************************************************************************************
void loop() 
{ 
  
  // Begin timer
  timer.tick();

   // Read voltage values

  Filter0.Filter(analogRead(0));
  cap_voltage0 = Filter0.Current();
  temp0=cap_voltage0/divisor;
  cap_voltage0 =(temp0/10.0) + offset;

  Filter1.Filter(analogRead(1));
  cap_voltage1 = Filter1.Current();
  temp1=cap_voltage1/divisor;
  cap_voltage1 =(temp1/10.0) + offset;

  Filter2.Filter(analogRead(2));
  cap_voltage2 = Filter2.Current();
  temp2=cap_voltage2/divisor;
  cap_voltage2 =(temp2/10.0) + offset;

  Filter3.Filter(analogRead(3));
  cap_voltage3 = Filter3.Current();
  temp3=cap_voltage3/divisor;
  cap_voltage3 =(temp3/10.0) + offset;
  
  Filter4.Filter(analogRead(4));
  cap_voltage4 = Filter4.Current();
  temp4=cap_voltage4/divisor;
  cap_voltage4 =(temp4/10.0) + offset;

  Filter5.Filter(analogRead(5));
  cap_voltage5 = Filter5.Current();
  temp5=cap_voltage5/divisor;
  cap_voltage5 =(temp5/10) + offset;

  cap_totvoltage = cap_voltage0; 
  //cap_totvoltage = cap_voltage0 + cap_voltage1 + cap_voltage2 + cap_voltage3 + cap_voltage4 + cap_voltage5;

  //filter section 

  
  // Whenever cap is not full but above threshold
  if (cap_voltage0 < max_voltage || cap_voltage1 < max_voltage ||
      cap_voltage2 < max_voltage || cap_voltage3 < max_voltage ||
      cap_voltage4 < max_voltage || cap_voltage5 < max_voltage && cap_totvoltage > min_total)
      
  {
    Serial.print("Went into first if statement");
    // When the caps are summoned
    while (signal_pin == 1 && (cap_voltage0 < max_voltage || cap_voltage1 < max_voltage ||
      cap_voltage2 < max_voltage || cap_voltage3 < max_voltage ||
      cap_voltage4 < max_voltage || cap_voltage5 < max_voltage && cap_totvoltage > min_total))
    {
      Serial.print("Went into first while loop under if statement");
      digitalWrite(relay1, LOW); // stop charging
      delay(100);
      digitalWrite(relay2, HIGH); // start discharging
      signal_pin = digitalRead(7);
      readCapacitors();

      Filter0.Filter(analogRead(0));
      cap_voltage0 = Filter0.Current();
      temp0=cap_voltage0/divisor;
      cap_voltage0 =(temp0/10.0) + offset;

      Filter1.Filter(analogRead(1));
      cap_voltage1 = Filter1.Current();
      temp1=cap_voltage1/divisor;
      cap_voltage1 =(temp1/10.0) + offset;

      Filter2.Filter(analogRead(2));
      cap_voltage2 = Filter2.Current();
      temp2=cap_voltage2/divisor;
      cap_voltage2 =(temp2/10.0) + offset;

      Filter3.Filter(analogRead(3));
      cap_voltage3 = Filter3.Current();
      temp3=cap_voltage3/divisor;
      cap_voltage3 =(temp3/10.0) + offset;
      
      Filter4.Filter(analogRead(4));
      cap_voltage4 = Filter4.Current();
      temp4=cap_voltage4/divisor;
      cap_voltage4 =(temp4/10.0) + offset;

      Filter5.Filter(analogRead(5));
      cap_voltage5 = Filter5.Current();
      temp5=cap_voltage5/divisor;
      cap_voltage5 =(temp5/10.0) + offset;

      cap_totvoltage = cap_voltage0; 
      //cap_totvoltage = cap_voltage0 + cap_voltage1 + cap_voltage2 + cap_voltage3 + cap_voltage4 + cap_voltage5;
      
    }
    // When the caps are idle
    while (signal_pin == 0 && (cap_voltage0 < max_voltage || cap_voltage1 < max_voltage ||
      cap_voltage2 < max_voltage || cap_voltage3 < max_voltage ||
      cap_voltage4 < max_voltage || cap_voltage5 < max_voltage && cap_totvoltage > min_total)) 
    {
      Serial.print("Went into second while loop under if statement");
      digitalWrite(relay2, LOW); // stop discharging
      delay(100);
      digitalWrite(relay1, HIGH); // start charging
      signal_pin = digitalRead(7);
      readCapacitors();
      
      Filter0.Filter(analogRead(0));
      cap_voltage0 = Filter0.Current();
      temp0=cap_voltage0/divisor;
      cap_voltage0 =(temp0/10.0) + offset;

      Filter1.Filter(analogRead(1));
      cap_voltage1 = Filter1.Current();
      temp1=cap_voltage1/divisor;
      cap_voltage1 =(temp1/10.0) + offset;

      Filter2.Filter(analogRead(2));
      cap_voltage2 = Filter2.Current() + offset;
      temp2=cap_voltage2/divisor;
      cap_voltage2 =(temp2/10.0) + offset;

      Filter3.Filter(analogRead(3));
      cap_voltage3 = Filter3.Current() + offset;
      temp3=cap_voltage3/divisor;
      cap_voltage3 =(temp3/10.0) + offset;
      
      Filter4.Filter(analogRead(4));
      cap_voltage4 = Filter4.Current();
      temp4=cap_voltage4/divisor;
      cap_voltage4 =(temp4/10.0) + offset;

      Filter5.Filter(analogRead(5));
      cap_voltage5 = Filter5.Current();
      temp5=cap_voltage5/divisor;
      cap_voltage5 =(temp5/10.0) + offset;

      cap_totvoltage = cap_voltage0; 
      //cap_totvoltage = cap_voltage0 + cap_voltage1 + cap_voltage2 + cap_voltage3 + cap_voltage4 + cap_voltage5;
   
      
    }
  }
    
  // Whenever one cap is full
else if (cap_voltage0 >= max_voltage || cap_voltage1 >= max_voltage || 
           cap_voltage2 >= max_voltage || cap_voltage3 >= max_voltage || 
           cap_voltage4 >= max_voltage || cap_voltage5 >= max_voltage)
        
  {
    Serial.print("Went into ekse if statement");
    digitalWrite(relay1, LOW); // stop charging (kinda extra)
    // When the caps are summoned
    while (signal_pin == 1 && ((cap_voltage0 >= max_voltage || cap_voltage1 >= max_voltage || 
           cap_voltage2 >= max_voltage || cap_voltage3 >= max_voltage || 
           cap_voltage4 >= max_voltage || cap_voltage5 >= max_voltage)))
    {
      Serial.print("Went into first while loop under else if statement");
      digitalWrite(relay1, LOW); // stop charging
      delay(100);
      digitalWrite(relay2, HIGH); // start discharging
      signal_pin = digitalRead(7);
      readCapacitors();
      
      Filter0.Filter(analogRead(0));
      cap_voltage0 = Filter0.Current();
      temp0=cap_voltage0/divisor;
      cap_voltage0 =(temp0/10.0) + offset;

      Filter1.Filter(analogRead(1));
      cap_voltage1 = Filter1.Current();
      temp1=cap_voltage1/divisor;
      cap_voltage1 =(temp1/10.0) + offset;

      Filter2.Filter(analogRead(2));
      cap_voltage2 = Filter2.Current();
      temp2=cap_voltage2/divisor;
      cap_voltage2 =(temp2/10.0) + offset;

      Filter3.Filter(analogRead(3));
      cap_voltage3 = Filter3.Current();
      temp3=cap_voltage3/divisor;
      cap_voltage3 =(temp3/10.0) + offset;
      
      Filter4.Filter(analogRead(4));
      cap_voltage4 = Filter4.Current();
      temp4=cap_voltage4/divisor;
      cap_voltage4 =(temp4/10.0) + offset;

      Filter5.Filter(analogRead(5));
      cap_voltage5 = Filter5.Current();
      temp5=cap_voltage5/divisor;
      cap_voltage5 =(temp5/10.0) + offset;

      cap_totvoltage = cap_voltage0; 
      //cap_totvoltage = cap_voltage0 + cap_voltage1 + cap_voltage2 + cap_voltage3 + cap_voltage4 + cap_voltage5;
  
    }
    // When the caps are idle
    while (signal_pin = 0 && ((cap_voltage0 >= max_voltage || cap_voltage1 >= max_voltage || 
           cap_voltage2 >= max_voltage || cap_voltage3 >= max_voltage || 
           cap_voltage4 >= max_voltage || cap_voltage5 >= max_voltage))) 
    {
      Serial.print("Went into second while loop under else if statement");
      digitalWrite(relay1, LOW); // stop charging
      delay(100);
      digitalWrite(relay2, LOW); // stop discharging
      signal_pin = digitalRead(7);
      readCapacitors();
     
      Filter0.Filter(analogRead(0));
      cap_voltage0 = Filter0.Current();
      temp0=cap_voltage0/divisor;
      cap_voltage0 =(temp0/10.0) + offset;

      Filter1.Filter(analogRead(1));
      cap_voltage1 = Filter1.Current();
      temp1=cap_voltage1/divisor;
      cap_voltage1 =(temp1/10.0) + offset;

      Filter2.Filter(analogRead(2));
      cap_voltage2 = Filter2.Current();
      temp2=cap_voltage2/divisor;
      cap_voltage2 =(temp2/10.0) + offset;

      Filter3.Filter(analogRead(3));
      cap_voltage3 = Filter3.Current();
      temp3=cap_voltage3/divisor;
      cap_voltage3 =(temp3/10.0) + offset;
      
      Filter4.Filter(analogRead(4));
      cap_voltage4 = Filter4.Current();
      temp4=cap_voltage4/divisor;
      cap_voltage4 =(temp4/10.0) + offset;

      Filter5.Filter(analogRead(5));
      cap_voltage5 = Filter5.Current();
      temp5=cap_voltage5/divisor;
      cap_voltage5 =(temp5/10.0) + offset;

      cap_totvoltage = cap_voltage0; 
      //cap_totvoltage = cap_voltage0 + cap_voltage1 + cap_voltage2 + cap_voltage3 + cap_voltage4 + cap_voltage5;
     
    }
  }

  // Whenever the caps are EXHAUSTED
  while (cap_totvoltage < min_total)
  {
  Serial.print("Went into standalone while loop");
  digitalWrite(relay2, LOW);
  delay(100);
  digitalWrite(relay1, HIGH);
  readCapacitors();
  
  Filter0.Filter(analogRead(0));
  cap_voltage0 = Filter0.Current();
  temp0=cap_voltage0/divisor;
  cap_voltage0 =(temp0/10.0) + offset;

  Filter1.Filter(analogRead(1));
  cap_voltage1 = Filter1.Current();
  temp1=cap_voltage1/divisor;
  cap_voltage1 =(temp1/10.0) + offset;

  Filter2.Filter(analogRead(2));
  cap_voltage2 = Filter2.Current();
  temp2=cap_voltage2/divisor;
  cap_voltage2 =(temp2/10.0) + offset;

  Filter3.Filter(analogRead(3));
  cap_voltage3 = Filter3.Current();
  temp3=cap_voltage3/divisor;
  cap_voltage3 =(temp3/10.0) + offset;
  
  Filter4.Filter(analogRead(4));
  cap_voltage4 = Filter4.Current();
  temp4=cap_voltage4/divisor;
  cap_voltage4 =(temp4/10.0) + offset;

  Filter5.Filter(analogRead(5));
  cap_voltage5 = Filter5.Current();
  temp5=cap_voltage5/divisor;
  cap_voltage5 =(temp5/10.0) + offset;

  cap_totvoltage = cap_voltage0; 
  //cap_totvoltage = cap_voltage0 + cap_voltage1 + cap_voltage2 + cap_voltage3 + cap_voltage4 + cap_voltage5;

  }
  // Delay for displaying voltage readings
  readCapacitors();

}