#include <LPC22xx.h>

static void delay(void);
static void debounce(void);

void ledinit(void)
{
	PINSEL0 = PINSEL0 & 0x3FFFFFFF;
	PINSEL1 = PINSEL1 & 0xFFFFC000;
	IODIR0 = IODIR0 | 0x007F8000;
}

int keyread1 (void)
{
	unsigned int rows,columns,i, code;
	unsigned int scancodes[] = { 	0x7E,0x7D,0x7B,0x77,
									0xBE,0xBD,0xBB,0xB7,
									0xDE,0xDD,0xDB,0xD7,
									0xEE,0xED,0xEB,0xE7  };

		
	IODIR0 = IODIR0 | 0x000003FC;		/* Set P0.2 to P0.9 as Output 						*/
	IOCLR0 = 0x000003FC;				/* Clear all the port pins							*/
	IODIR0 = IODIR0 |  0x000003C0;   	/* P0.6, P0.7, P0.8 and P0.9 are Output ROWS 		*/
	IODIR0 = IODIR0 & ~0x0000003C;   	/* P0.2, P0.3, P0.4 and P0.5 are Input Columns 		*/
	IOSET0 = 0x0000003C;				/* Set high 4 Cloumns of keybord, P0.6 to P0.9		*/
	

	rows= IOPIN0;					    /* read columns				*/
	rows = 	rows & 0x0000003C;		    /* Mask the Columns 		*/
		rows = 	rows >> 2;				/* right shift 				*/
	 

	IODIR0 = IODIR0 | 0x000003FC;
	IOCLR0 = 0x000003FC;
	IODIR0 = IODIR0 |  0x0000003C;    /* P0.6, P0.7, P0.8 and P0.9 are Output ROWS */
	IODIR0 = IODIR0 & ~0x000003C0;    /* P0.2, P0.3, P0.4 and P0.5 are Input Columns */
	IOSET0 = 0x000003C0;

columns = IOPIN0;
columns= columns & 0x000003C0;			/* Read rows  	*/
columns= columns>> 2;					/* right shift	*/
	
	code = columns |  rows ;	
				/* merge rows and columns */

	debounce();
	 
	for(i = 0; i < 16; i++)
	{
		if(scancodes[i]==code)			/* Check if the code generated matchs with the scan code table */
		{ 
			return(i+1);				/* Return the scan code index, which infact is the key pressed */
		}
	}

	return(0);
}




void keyinit(void)
{
	PINSEL0 = PINSEL0 & 0xFFF0000F;
	IODIR0 = IODIR0 | 0x000003FC;
}

unsigned char keyread (void)
{
	unsigned int rows,columns,i, code;
	unsigned int scancodes[] = {
									0x7E,0x7D,0x7B,0x77,
									0xBE,0xBD,0xBB,0xB7,
									0xDE,0xDD,0xDB,0xD7,
									0xEE,0xED,0xEB,0xE7 };
	do{	
	IODIR0 = IODIR0 | 0x000003FC;		/* Set P0.2 to P0.9 as Output 						*/
	IOCLR0 = 0x000003FC;				/* Clear all the port pins							*/
	IODIR0 = IODIR0 |  0x000003C0; 	/* P0.6, P0.7, P0.8 and P0.9 are Output ROWS 		*/
	IODIR0 = IODIR0 & ~0x0000003C;   	/* P0.2, P0.3, P0.4 and P0.5 are Input Columns 		*/
	IOSET0 = 0x0000003C;				/* Set high 4 Cloumns of keybord, P0.6 to P0.9		*/
	

	rows= IOPIN0;					/* read columns				*/
	rows = 	rows & 0x0000003C;		/* Mask the Columns 		*/
		rows = 	rows >> 2;				/* right shift 				*/
	 

	IODIR0 = IODIR0 | 0x000003FC;
	IOCLR0 = 0x000003FC;
	IODIR0 = IODIR0 |  0x0000003C; 	/* P0.6, P0.7, P0.8 and P0.9 are Output ROWS */
	IODIR0 = IODIR0 & ~0x000003C0;    /* P0.2, P0.3, P0.4 and P0.5 are Input Columns */
	IOSET0 = 0x000003C0;

columns = IOPIN0;
columns= columns & 0x000003C0;			/* Read rows  	*/
columns= columns>> 2;					/* right shift	*/
	
	code = columns |  rows ;	
				/* merge rows and columns */

	debounce();
	 }while(rows == 0x0000000f) ;
	for(i = 0; i < 16; i++)
	{
		if(scancodes[i]==code)			/* Check if the code generated matchs with the scan code table */
		{ 
			return(i+1);				/* Return the scan code index, which infact is the key pressed */
		}
	}

	return(0);
}


void led (void)
{
	IOCLR0 = 0x007f8000;
	delay();
	IOSET0 = 0x007f8000;
	delay();
}

void delay(void)
{
	int j;
	for (j=0;j<500000;j++);
}

void debounce(void)
{
	int j;
	for (j=0;j<150000;j++);
}
