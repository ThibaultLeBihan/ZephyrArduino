
#define USE_USBCON
#ifdef SERIAL_PORT_HARDWARE_OPEN
#define jrkSerial SERIAL_PORT_HARDWARE_OPEN
#else
#include <SoftwareSerial.h>
SoftwareSerial jrkSerial(10, 11);
#endif

#include <JrkG2.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

/// Define input channel pins
static const int CH_VERIN_1 = 9;
static const int CH_SWITCH_MODE = 10;  
//...
static const int NUM_CHANNELS = 2;



/// Create the arrays
float channel[NUM_CHANNELS];

int chId[NUM_CHANNELS] = 
  { CH_VERIN_1
  , CH_SWITCH_MODE
  };

  

JrkG2Serial jrk(jrkSerial);

ros::NodeHandle  nh;
std_msgs::UInt16 verin_confirmation_msg;
ros::Publisher verin_confirmation_pub("verin_confirmation", &verin_confirmation_msg);



void valeur( const std_msgs::UInt16 cmd_msg){
  jrk.setTarget(cmd_msg.data);

  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<std_msgs::UInt16> sub("commande_verin", &valeur);

void setup(){
   /// Define pins as INPUT
  for(int i = 0; i < NUM_CHANNELS; i++)
  {
    pinMode(chId[i], INPUT);
  }
  Serial.begin(9600);
  nh.getHardware()->setBaud(9600);
  jrkSerial.begin(9600);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(verin_confirmation_pub);
  // Set the baud rate.
  jrkSerial.begin(9600);

}

void loop(){
  nh.spinOnce();
  delay(1);

  //verin_confirmation_msg.data=feedback;  //cmd_msg.data pour avoir la consigne
  //verin_confirmation_pub.publish(&verin_confirmation_msg);
  

  channel[0] = pulseIn(chId[0], HIGH);
  channel[0] = map(channel[0], 1089, 1913 ,0 ,4095);

  channel[1] = pulseIn(chId[1], HIGH);
  channel[1] = map(channel[1], 1089, 1913 ,0 ,4095);
  
  verin_confirmation_msg.data=jrk.getScaledFeedback();  //cmd_msg.data pour avoir la consigne
  verin_confirmation_pub.publish(&verin_confirmation_msg);
  
  if(channel[1]>=4000){  //Passage en mode manuel
  if (channel[0] >= 4000){
    jrk.setTarget(4095);
  }
  else if (channel[0] <=100){
    jrk.setTarget(0);
  }
  else {
    jrk.setTarget(jrk.getScaledFeedback());
  }


  }
}
