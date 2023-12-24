#include <LPC22xx.h>
//#include <lcd.h>
static void lcdcmd(unsigned int);
void lcddata(unsigned int);
static void delay_lcd(void);
void h2disp(unsigned int ) ;


void waitOnPowerOnForLCD(void)
{
	unsigned int i;

	for(i=0; i < 65536; i++);
}

void LCDInit(void)
{
	waitOnPowerOnForLCD();	
	PINSEL1 = PINSEL1 & ~(0x000FFFFF);

	IODIR0 = IODIR0 | 0x03FF0000;

	lcdcmd(0x38);
	lcdcmd(0x0e);
	lcdcmd(0x01);
	lcdcmd(0x06);
	lcdcmd(0x80);
}

void cursratline1clm1(void)
{
	lcdcmd(0x80);
}

void inccursor(void)
{
	lcdcmd(0x06);
}

void clrscreen(void)
{
	lcdcmd(0x01);
	lcdcmd(0x80);
}

void lcdcmd(unsigned int cmddata)
{
    	waitOnPowerOnForLCD() ;
       IOCLR0 = IOCLR0 | 0x00010000;	/* RS = 0, Select Command register */

	IOCLR0 = IOCLR0 | 0x03FC0000;	/* Clear the data bus 	*/
	cmddata = cmddata << 18;
	IOSET0 = IOSET0 | cmddata;		/* Write the command data on the bus */

	IOCLR0 = IOCLR0 | 0x00020000;	/* */
	delay_lcd();
	IOSET0 = IOSET0 | 0x00020000;	/* */
	delay_lcd();
	IOCLR0 = IOCLR0 | 0x00020000;	/* */

}


void lcddata(unsigned int outdata)
{
         waitOnPowerOnForLCD() ;
   IOSET0 = IOSET0 | 0x00010000;	/* RS = 1, Select Data register */
	
	outdata = outdata << 18;
	IOCLR0 = IOCLR0 | 0x03FC0000;
    IOSET0 = IOSET0 | outdata;

	IOCLR0 = IOCLR0 | 0x00020000;	/* */
	delay_lcd();					/* approx 400ns delay */
	IOSET0 = IOSET0 | 0x00020000;	/* */
	delay_lcd();
	IOCLR0 = IOCLR0 | 0x00020000;	/* */
	
}

void DisplayLCD(char *str, int len)
{  
    waitOnPowerOnForLCD() ;
	while(len-- != 0)
	{
		lcddata(*str);
		str++;
	}
}

void delay_lcd(void)
{
	int j;
	for (j=0;j<500;j++);
}





void h2disp(unsigned int h)
{
	int r,d;
	if(h>9)
	{
	   d=h/10;
	   r=h-10*d;
	   h2disp(d);
	   r=r+0x30;
	   lcddata(r);		 

	}
	else
	{
	h=h+0x30;
	lcddata(h);
	}
}







