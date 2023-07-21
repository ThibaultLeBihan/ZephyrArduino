#ifndef _ROS_plymouth_internship_2019_KeyboardServoCommand_h
#define _ROS_plymouth_internship_2019_KeyboardServoCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace plymouth_internship_2019
{

  class KeyboardServoCommand : public ros::Msg
  {
    public:
      typedef int64_t _servo_command_1_type;
      _servo_command_1_type servo_command_1;
      typedef int64_t _servo_command_2_type;
      _servo_command_2_type servo_command_2;

    KeyboardServoCommand():
      servo_command_1(0),
      servo_command_2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_servo_command_1;
      u_servo_command_1.real = this->servo_command_1;
      *(outbuffer + offset + 0) = (u_servo_command_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo_command_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_servo_command_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_servo_command_1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_servo_command_1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_servo_command_1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_servo_command_1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_servo_command_1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->servo_command_1);
      union {
        int64_t real;
        uint64_t base;
      } u_servo_command_2;
      u_servo_command_2.real = this->servo_command_2;
      *(outbuffer + offset + 0) = (u_servo_command_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo_command_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_servo_command_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_servo_command_2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_servo_command_2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_servo_command_2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_servo_command_2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_servo_command_2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->servo_command_2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_servo_command_1;
      u_servo_command_1.base = 0;
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_servo_command_1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->servo_command_1 = u_servo_command_1.real;
      offset += sizeof(this->servo_command_1);
      union {
        int64_t real;
        uint64_t base;
      } u_servo_command_2;
      u_servo_command_2.base = 0;
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_servo_command_2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->servo_command_2 = u_servo_command_2.real;
      offset += sizeof(this->servo_command_2);
     return offset;
    }

    virtual const char * getType() override { return "plymouth_internship_2019/KeyboardServoCommand"; };
    virtual const char * getMD5() override { return "9dbce863de6b75635fc5625ec0af5414"; };

  };

}
#endif
