// Define some global variables and constants
const byte LEDPIN = LED_BUILTIN;    //using the built in LED
const byte NUMBEROFBLINKS = 4;
const byte BLINKDURATIONMS = 200;
const int PERIODMS = 2000;  //the value is a number of milliseconds

unsigned long startMillis;  
unsigned long currentMillis; 

// Setup
void setup()
{
  Serial.begin(9600);  //start Serial in case we need to print debugging info
  pinMode(LEDPIN, OUTPUT);
  startMillis = millis();  //initial start time
  currentMillis = startMillis;
}

// Loop
void loop()
{
  Serial.println("Start of the loop");
  // Do a for loop for the number of blinks, use the new function at the bottom
  for (int i=0; i< NUMBEROFBLINKS; i++){
    BlinkOnce(BLINKDURATIONMS);
  }

  // Now kill the time until exactly PERIODMS milliseconds has passed since the start of the loop
  // Use a 'while' loop  and use the 'millis()' function
  while (currentMillis - startMillis < PERIODMS){
    currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  } 
  Serial.println("End of Loop");
  startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
 
}

// Custom function
void BlinkOnce(byte tms) {
  Serial.print("Blink ");
  digitalWrite(LEDPIN, true);
  delay(tms);
  digitalWrite(LEDPIN, false);
  delay(tms);
}