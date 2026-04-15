#include <LPC17xx.H>
void delay(unsigned int count)
{
	unsigned int i, j;
	for(j = 0;j < count;j++)
	{
		for(i = 0;i < 12000;i++);
	}
}
int main()
{
	unsigned int del = 100;
	unsigned int val = 0x11111111;
	LPC_GPIO1->FIODIR = 0x03C00000;
	while(1)
	{
		LPC_GPIO1->FIOPIN = val;
		val = (val << 1)|(val >> 31);
		delay(del);
	}
}