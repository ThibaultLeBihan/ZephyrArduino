#include <JrkG2.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);  //RX=2, TX=3

JrkG2Serial jrk(mySerial);

/// Define input channel pins
static const int CH_THROTTLE_IN = 9;
static const int CH_STEERING_IN = 10;
static const int NUM_CHANNELS = 2;
static const int PWM_DISCONNECT = 700;

/// Create the arrays
float channel[NUM_CHANNELS];

int chId[NUM_CHANNELS] = 
  { CH_THROTTLE_IN
  , CH_STEERING_IN
  };
 
void setup() {
  /// Define pins as INPUT
  for(int i = 0; i < NUM_CHANNELS; i++)
  {
    pinMode(chId[i], INPUT);
  }
  Serial.begin(9600);
  // Set the baud rate.
  mySerial.begin(9600);
  mySerial.listen();
}
 
void loop() {
  /// Use the function pulseIn and returns the timinng in us between two highs
  /// see: https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/
  int tmpIsDisconnected = 0;
  for(int i = 0; i < NUM_CHANNELS; i++)
  {
    channel[i] = pulseIn(chId[i], HIGH);
    
    if(channel[i] < PWM_DISCONNECT)
    {
      tmpIsDisconnected = 1;
    }
    channel[i] = map(channel[i], 1080, 1930 ,0 ,4095);
    Serial.print(chId[i]); 
    Serial.print(": ");  
    Serial.print(channel[i]);
    Serial.print(" - "); 
    jrk.setTarget(channel[i]); 
  }
  Serial.print(" disconnection: ");
  Serial.println(tmpIsDisconnected);
}
