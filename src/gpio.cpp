#include "gpio.h"

//GPIO_Type * Gpio::GpioBase [5] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE};
uint32_t * Gpio::PortBase [3] = {(uint32_t*)PORT0_, (uint32_t*)PORT1_, (uint32_t*)PORT2_};


Gpio::Gpio ()
{
  
}

Gpio::Gpio (Port p)
{
  LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 16;
  nPort = static_cast <uint8_t>(p);
  prt = PortBase[nPort];
  
  //*prt = 3;
 //*((uint32_t*)0x40044000) = 3;
}


Gpio::Gpio (uint8_t p)
{
  nPort = p;
  prt = PortBase[nPort];
}

void Gpio::setPort (Port p)
{
  LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 6;
  nPort = static_cast <uint8_t>(p);
  prt = PortBase[nPort];
}

