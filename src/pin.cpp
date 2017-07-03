#include "pin.h"

Pin::Pin (Gpio::Port prt_, uint8_t p , mux mx)
:Gpio(prt_)
{
	pin_ = p;
	*(prt+pin_) |= (uint8_t)mx << 0;
}

Pin::Pin (uint8_t prt_, uint8_t p , mux mx)
:Gpio(prt_)
{
	pin_ = p;
	*(prt+pin_) |= (uint8_t)mx << 0;
}

Pin::Pin (Port prt_, uint8_t p )
:Gpio(prt_)
{
	pin_ = p;
 *(prt+pin_) |= (static_cast <uint8_t> (mux::func0)) << 0;
  LPC_GPIO_PORT->DIR [nPort] |= 1 << pin_;
}

Pin::Pin (Port prt_, uint8_t p , PP m)
:Gpio(prt_)
{
 pin_ = p;
 *(prt+pin_) |= (static_cast <uint8_t> (mux::func0)) << 0;
 LPC_GPIO_PORT->DIR [nPort] &= ~ 1 << pin_;

	/*PortBase[Gpio::prt]->PCR[pin_] |= PORT_PCR_PE_MASK;
	PortBase[Gpio::prt]->PCR[pin_] &= ~PORT_PCR_PS_MASK;
	PortBase[Gpio::prt]->PCR[pin_] |= (uint8_t)m << PORT_PCR_PS_SHIFT;*/
}

void Pin::setPort (Port)
{

}

void Pin::direction (mode m)
{
	LPC_GPIO_PORT->DIR [nPort] &= ~ 1 << pin_;
	LPC_GPIO_PORT->DIR [nPort] |= ((uint8_t)m << pin_);
}
/*
void Pin::setIn (PP pp_)
{
 GpioBase[Gpio::prt]->PDDR &= ~(1 << pin_);
	PortBase[Gpio::prt]->PCR[pin_] |= 1 << PORT_PCR_PE_MASK;
	PortBase[Gpio::prt]->PCR[pin_] &= ~ (1 << PORT_PCR_PS_MASK);
	PortBase[Gpio::prt]->PCR[pin_] |= (uint8_t)pp_ << PORT_PCR_PS_MASK;
}
*/
void Pin::setOut ()
{
	LPC_GPIO_PORT->DIR [nPort] |= ((uint8_t)1 << pin_);
}


void Pin::set()
{
	LPC_GPIO_PORT->SET [nPort] |= 1 << pin_;
}
/*
void Pin::set (bool st)
{
	GpioBase[Gpio::prt]->PCOR |= 1 << pin_;
	GpioBase[Gpio::prt]->PSOR |= st << pin_;
}
*/
void Pin::clear ()
{
	LPC_GPIO_PORT->CLR [nPort]  |= 1 << pin_;
}

void Pin::togle ()
{
	LPC_GPIO_PORT->NOT [nPort]  |= 1 << pin_;
}

bool Pin::state ()
{
	return (LPC_GPIO_PORT->SET [nPort]&(1 << pin_));
}
/*
uint32_t * Pin::getPort ()
{
	return PortBase[prt];
}

uint8_t & Pin::getPin ()
{
	return pin_;
}*/
