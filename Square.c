#include <LPC17xx.H>
#define freq 120000
#define voltage 1024
int main()
{
	unsigned int i;
	LPC_PINCON->PINSEL1 = (1 << 21);
	while(1)
	{
		LPC_DAC->DACR = (voltage / 2 << 6);
		for(i = freq;i > 0;i--);
		LPC_DAC->DACR = (voltage << 6);
		for(i = freq;i > 0;i--);
	}
}