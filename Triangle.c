#include <LPC17xx.H>
#define voltage 1024
int main()
{
	unsigned int i;
	LPC_PINCON->PINSEL1 = (1 << 21);
	while(1)
	{
		for(i = 0;i < voltage;i++)
			LPC_DAC->DACR = (i << 6);
		for(i = voltage;i > 0;i--)
			LPC_DAC->DACR = (i << 6);
	}
}