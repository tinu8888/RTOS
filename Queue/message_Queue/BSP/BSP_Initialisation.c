#include<lpc22xx.h>
#include<stdio.h>

#define  LCD_DATA   	0x03fC0000;
#define  LCD_RS     	0x00010000; 
#define  LCD_Rw     	0x00000000; 
#define  LCD_EN     	0x00020000; 

#define  LED_DATA   	0x00FF0000;

#define  ADC_INPUT  	0x01000000;

#define  KEY_BOARD  	0x000001FE;
 
#define  EX_INTRRUPT  	0x40000000;

#define  CAN_CON_L  	0x00000000;
#define  CAN_CON_H  	0x00000000;

#define  USART_RX_2  	0x00000100;
#define  USART_TX_2  	0x00000200;

#define  USART_RX_1  	0x00000001;
#define  USART_TX_1  	0x00000002;

#define  PORT_0_DIR  	IODIR0;

#define  PORT_1_DIR  	IODIR1;

#define  PORT_2_DIR  	IODIR2;

#define  SET_PORT_0	SETIO0;
#define  SET_PORT_1	SETIO1;
#define  SET_PORT_2	SETIO2;

#define  CLEAR_PORT_0	CLRIO0;
#define  CLEAR_PORT_1	CLRIO1;
#define  CLEAR_PORT_2	CLRIO2;




#define PINSEL0 	0xE002C000;
#define PINSEL1 	0xE002C004;


#define LED0 		0xE002C004;

#define LED7 		0xE002C004;
#define ALL_LED 	0xE002C004;




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