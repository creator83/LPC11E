#include "device.h"              // Device header


#ifndef GPIO_H
#define GPIO_H

const uint32_t PORT0_ = 0x40044000;
const uint32_t PORT1_ = 0x40044060;
const uint32_t PORT2_ = 0x400440F0;

class Gpio
{
//variables
public:
  enum class Port {port0, port1 , port2};
  enum class mux {func0, func1, func2, func3, func4, func5};
  enum class mode {Input, Output};
  enum class PP {PullDown, PullUp};
  enum class state {Off, On};
 
protected:
  static uint32_t * PortBase [3];
  //static GPIO_Type * GpioBase [5];
  uint32_t * prt;
  uint8_t nPort;
private:

//functions
public:
  Gpio ();
  Gpio(Port p );
  Gpio(uint8_t p );
  void setPort (Port p);

};

#endif



