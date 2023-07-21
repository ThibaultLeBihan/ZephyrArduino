// This example shows how to control the Jrk G2 over serial by
// sending Set Target commands.
//
// The Jrk's input mode must be set to "Serial/I2C/USB".  The
// serial mode must be set to "UART, fixed baud rate", and the
// baud rate must be set to "9600".  CRC should not be enabled.
// This example uses the Compact Protocol, so the Jrk's device
// number is not used, and can be set to anything.
//
// Please see https://github.com/pololu/jrk-g2-arduino for
// details on how to make the connections between the Arduino and
// the Jrk G2.

#include <JrkG2.h>

// On boards with a hardware serial port available for use, use
// that port to communicate with the Jrk. For other boards,
// create a SoftwareSerial object using pin 10 to receive (RX)
// and pin 11 to transmit (TX).
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);  //RX=2, TX=3

JrkG2Serial jrk(mySerial);

void setup()
{
  // Set the baud rate.
  mySerial.begin(9600);
  mySerial.listen();
}

void loop()
{
  delay(3000);
  jrk.setTarget(2348);
  Serial.print(SERIAL_PORT_HARDWARE_OPEN);


  
  delay(3000);
  jrk.setTarget(1748);
}
