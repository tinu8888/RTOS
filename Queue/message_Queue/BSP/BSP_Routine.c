#include<lpc22xx.h>
#include<stdio.h>
#include<BSP_Initialisation.h>

#define PINSEL0 	0xE002C000;
#define PINSEL1 	0xE002C004;


#define LED0 		0xE002C004;

#define LED7 		0xE002C004;
#define ALL_LED 	0xE002C004;


void Initialisation(void)
{

PORT_0_DIR = ~( LCD_DATA | LCD_RS | LCD_RW | LCD_EN |  KEY_BOARD );

PORT_1_DIR = ~ LED_DATA ;




void bsp_lcd(void)			   //lcd
  {
  IODIR0 = 0x0FFF0000; 
  }
void bsp_keyboard(void)		   //keyboard
  {	IODIR0=0x0000003c;
  }
  void bsp_led(void)		   //led
  {
	//PINSEL0 = PINSEL0 & 0x3FFFFFFF;
	//PINSEL1 = PINSEL1 & 0xFFFFC000;
	//IODIR0 = IODIR0 | 0x007F8000;
	IODIR1=0x00FF0000;
 }
 void bsp_adc(void)							
 {					   //adc
  IODIR0=0x04000000;
 }