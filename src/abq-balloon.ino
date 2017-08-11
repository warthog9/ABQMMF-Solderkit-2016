int leftBaloonLEDPin = 0;
int rightBaloonLEDPin = 1;

int abqTouchPin = 2;
int faireTouchPin = 4;

int maxBrightness = 128;

void setup()
{
  pinMode(leftBaloonLEDPin, OUTPUT);
  pinMode(rightBaloonLEDPin, OUTPUT);
  
  digitalWrite(leftBaloonLEDPin, HIGH);   // sets the LED on
  delay(1000);                  // waits for a second
  digitalWrite(leftBaloonLEDPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second
  
  digitalWrite(rightBaloonLEDPin, LOW);   // sets the LED on
  delay(1000);                  // waits for a second
  digitalWrite(rightBaloonLEDPin, HIGH);    // sets the LED off
  delay(1000);                  // waits for a second
  
  // Left pin low is off
  digitalWrite(leftBaloonLEDPin, LOW);
  // right pin, high should be off
  digitalWrite(rightBaloonLEDPin, HIGH);
}

void loop()
{
  int state = random(0,2);
  
  if( state == 0 || state == 1){
    
    // Run one LED
    
    int whichLED = 0;
    
    if( state == 0 ){
       // Run the left LED
       whichLED = leftBaloonLEDPin;
    } else if( state == 1 ){
      // Run the right LED
      whichLED = rightBaloonLEDPin;
    }

    // fade the LED on thisPin from off to brightest:
    for (int brightness = 0; brightness < maxBrightness; brightness++) {
      int useBright = brightness;
      if( state == 1 ){
        // right led
        useBright = 255 - brightness;
      }
      analogWrite(whichLED, useBright);
      delay(5);
    }
  
    // Flicker at the "top" of the brightness, like a balloon
    int totalHighTime = random(250,1500);
  
    for (int highTime = 0; highTime <= totalHighTime; highTime = highTime + 5) {
      int randBright = random(maxBrightness - 50,maxBrightness);
      int useBright = randBright;
      
      if( state == 1 ){
        // right led
        useBright = 255 - randBright;
      }
      
      analogWrite(whichLED, useBright);
      delay(5);
    }
    // end "top" flicker
  
    // fade the LED on thisPin from brithstest to off:
    for (int brightness = maxBrightness; brightness >= 0; brightness--) {
      int useBright = brightness;
      
      if( state == 1 ){
        // right led
        useBright = 255 - brightness;
      }
      
      analogWrite(whichLED, useBright);
      delay(2);
    }
  
    int totalLowTime = random(250,1500);
  
    for (int lowTime = 0; lowTime <= totalLowTime; lowTime = lowTime + 5) {
      int useBright = random(0,12);
      
      if( state == 1 ){
        // right led
        useBright = 255 - useBright;
      }
      analogWrite(whichLED, useBright);
      delay(5);
    }
    
    if( state == 0 ){
      analogWrite(whichLED, 0);
    } else if( state == 1 ){
      analogWrite(whichLED, 255);
    }
  
    // Pulse
    if( random() % 2 == 0 ){
      for (int brightness = 0; brightness < maxBrightness; brightness++) {
         int useBright = brightness;
      
         if( state == 1 ){
           // right led
           useBright = 255 - brightness;
         }        
         
         analogWrite(whichLED, useBright);
         delay(5);
      }
      for(int x = 0; x < random(1,5); x++){
        for (int brightness = maxBrightness; brightness >= 0; brightness--) {
          int useBright = brightness;
      
          if( state == 1 ){
            // right led
            useBright = 255 - brightness;
          }        
         
          analogWrite(whichLED, useBright);
          delay(5);
        }      
      }
    }
  } else if( state == 2 ){
    // Run both LEDs
  } // end if statement
  
  delay(random(2500,15000));
}

