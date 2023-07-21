
#define USE_USBCON
#ifdef SERIAL_PORT_HARDWARE_OPEN
#define jrkSerial SERIAL_PORT_HARDWARE_OPEN
#else
#include <SoftwareSerial.h>
SoftwareSerial jrkSerial(10, 11);
#endif

#include <JrkG2.h>
#include <SoftwareSerial.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

JrkG2Serial jrk(jrkSerial);

ros::NodeHandle  nh;
std_msgs::UInt16 verin_confirmation_msg = jrk.getScaledFeedback();
ros::Publisher verin_confirmation_pub("verin_confirmation", &verin_confirmation_msg);



void valeur( const std_msgs::UInt16 cmd_msg){
  jrk.setTarget(cmd_msg.data);
  verin_confirmation_msg.data=cmd_msg.data;
  verin_confirmation_pub.publish(&verin_confirmation_msg);
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<std_msgs::UInt16> sub("commande_verin", &valeur);

void setup(){
  Serial.begin(9600);
  nh.getHardware()->setBaud(9600);
  jrkSerial.begin(9600);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(verin_confirmation_pub);
  
}

void loop(){
  nh.spinOnce();
  delay(1);
}
