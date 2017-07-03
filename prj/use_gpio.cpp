#include "device.h"                   // Device header
#include "gpio.h"
#include "pin.h"
/*#include "port.h"
#include "tact.h"
#include "delay.h"
                   // Device header

Tact frq;
const char ledPin = 16;*/


int main ()
{
 LPC_SYSCON->SYSAHBCLKCTRL |= 0x30;
 LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 16;
 uint16_t i=0;
 ++i;
 Gpio port0 (Gpio::Port::port0);
 Pin led (Gpio::Port::port1, 2);
 led.set ();
 led.clear ();
 


	while (1)
	{
		/*led.togle();
		delay_ms(1000);*/
	}
}
