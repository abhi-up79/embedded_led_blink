/*
 * Interfacing and Controlling LEDs
 * 
 * This is a Program Code for Iterfacing and controlling LEDs.
 * Here 4 LEDs are interfaced with Adruino Uno at Digital PIns - 4,7,8.
 * The Leds can be turned on by entering numbers 1,2,3 and the blinking speed can be
 * increased and reduced by entering "+" and "-" from the Keyboard.
 * The Leds can be turned off by again entering numbers 1,2,3 from the Keyboard.
 * Owner - Abhishek Sharma
 * Email - sharma.abhishek208@gmail.com
 */

//Variable Declaration for controlling individual LEDs
int a = 0;
int b = 0;
int c = 0;

//Variables for blinking operation
int x = 0;
int y = 0;
int z = 0;

//Constants for assigning output pins
const int led1 = 4;
const int led2 = 7;
const int led3 = 8;

//Variables for States of the LEDs
int led1State = LOW;
int led2State = LOW;
int led3State = LOW;

// will store last time LED was updated
unsigned long previousMillis = 0;
 
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

void setup(){

  // Assigning Output Pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  //initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  while (!Serial);
}

// the loop routine runs over and over again forever:
void loop() {

  //Save the current Time
  unsigned long currentMillis = millis();

  //Check the input at Serial
  if (Serial.available()){
    String state = Serial.readString();

    //Changing State of LED1
    if(a == 0){
      if (state == "1"){
        digitalWrite(led1, HIGH);
        led1State = HIGH;
        a = 1;
        x = 1;
      }
    }
    else if(a == 1){
      if (state == "1"){
        digitalWrite(led1, LOW);
        led1State = LOW;
        //Serial.println("Command completed LED turned OFF");
        a = 0;
        x = 0;
      }  
    }

    //Changing State of LED2
    if(b == 0){
      if (state == "2"){
        digitalWrite(led2, HIGH);
        led2State = HIGH;
        b = 1;
        y = 1;
      }
    }
    else if(b == 1){
      if (state == "2"){
        digitalWrite(led2, LOW);
        led2State = LOW;
        b = 0;
        y = 0;
      }  
    }

    //Changing State of LED3
    if(c == 0){
      if (state == "3"){
      digitalWrite(led3, HIGH);
      led3State = HIGH;
      //Serial.println("Command completed LED turned ON");
      c = 1;
      z = 1;
      }
    }
    else if(c == 1){
      if (state == "3"){
        digitalWrite(led3, LOW);
        led3State = LOW;
        c = 0;
        z = 0;
      }  
    }

    //For increasing speed of Blinking
    if(state == "+"){
      interval = interval - 250;
    }

    //For decreasing speed of Blinking
    if(state == "-"){
      interval = interval + 250;
    }
  }
//---------------------------------------------------------------------------

  //Check for reqired interval
  if(currentMillis - previousMillis >= interval) {
    
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    
   if(x == 1){
    // if the LED is off turn it on and vice-versa:
      if(led1State == LOW){
      led1State = HIGH;
      }
      else{
        led1State = LOW;
      }
      // set the LED with the ledState of the variable:
      digitalWrite(led1, led1State);
   }
 
   if(y == 1){
    // if the LED is off turn it on and vice-versa:
      if(led2State == LOW){
        led2State = HIGH;
      }
      else{
        led2State = LOW;
      }
      // set the LED with the ledState of the variable:
      digitalWrite(led2, led2State);
   }
 
   if(z == 1){
    // if the LED is off turn it on and vice-versa:
      if(led3State == LOW){
        led3State = HIGH;
      }
      else{
        led3State = LOW;
      }
      // set the LED with the ledState of the variable:
      digitalWrite(led3, led3State);
   }
  }
}
