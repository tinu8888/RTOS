#include<linux/ioctl.h>

typedef struct abd_gpio
{
	unsigned char port;
	int pin;
}gpio_t;

//gpio_t PortA, PortB, PortC;

/************ IOCTL-FLAGS **********/

#define GPIO_IOCTL		0xbb

#define GPIO_SEL		_IOW(GPIO_IOCTL,0,gpio_t)
#define GPIO_DIR_IN		_IOW(GPIO_IOCTL,1,gpio_t)
#define GPIO_DIR_OUT		_IOW(GPIO_IOCTL,2,gpio_t)
#define GPIO_SET		_IOW(GPIO_IOCTL,3,gpio_t)
#define GPIO_CLEAR		_IOW(GPIO_IOCTL,4,gpio_t)
#define GPIO_READ		_IOW(GPIO_IOCTL,5,gpio_t)

/***** PORT DEFINATION *********/

#define PORT_A			0
#define PORT_B			1
#define PORT_C			2

/***** PORT C PIN DEFINATION ****/
#define	PC0  		(0x1<<0)     //0001
#define	PC1  		(0x1<<1)
#define	PC2  		(0x1<<2)
#define	PC3  		(0x1<<3)     //1000

#define	PC4  		(0x10<<0)    //1 0000
#define	PC5  		(0x10<<1)
#define	PC6  		(0x10<<2)
#define	PC7  		(0x10<<3)    //1000 0000

#define	PC8  		(0x100<<0)
#define	PC9  		(0x100<<1)
#define	PC10  		(0x100<<2)
#define	PC11  		(0x100<<3)


#define	PC12  		(0x1000<<0)
#define	PC13  		(0x1000<<1)
#define	PC14  		(0x1000<<2)
#define	PC15  		(0x1000<<3)

#define	PC16  		(0x10000<<0)
#define	PC17  		(0x10000<<1)
#define	PC18  		(0x10000<<2)
#define	PC19  		(0x10000<<3)

#define	PC20  		(0x100000<<0)
#define	PC21  		(0x100000<<1)
#define	PC22  		(0x100000<<2)
#define	PC23  		(0x100000<<3)

#define	PC24  		(0x1000000<<3)
#define	PC25  		(0x1000000<<3)
#define	PC26  		(0x1000000<<3)
#define	PC27  		(0x1000000<<3)

#define	PC28  		(0x10000000<<0)  //0001 0000000
#define	PC29  		(0x10000000<<1)
#define	PC30  		(0x10000000<<2)
#define	PC31  		(0x10000000<<3) //1000 0000000

/************** PORT B PIN DEFINATION *********/

#define PB0             (0x1<<0)     //0001
#define PB1             (0x1<<1)
#define PB2             (0x1<<2)
#define PB3             (0x1<<3)     //1000

#define PB4             (0x10<<0)    //1 0000
#define PB5             (0x10<<1)
#define PB6             (0x10<<2)
#define PB7             (0x10<<3)    //1000 0000

#define PB8             (0x100<<0)
#define PB9             (0x100<<1)
#define PB10            (0x100<<2)
#define PB11            (0x100<<3)


#define PB12            (0x1000<<0)
#define PB13            (0x1000<<1)
#define PB14            (0x1000<<2)
#define PB15            (0x1000<<3)

#define PB16            (0x10000<<0)
#define PB17            (0x10000<<1)
#define PB18            (0x10000<<2)
#define PB19            (0x10000<<3)

#define PB20            (0x100000<<0)
#define PB21            (0x100000<<1)
#define PB22            (0x100000<<2)
#define PB23            (0x100000<<3)

#define PB24            (0x1000000<<3)
#define PB25            (0x1000000<<3)
#define PB26            (0x1000000<<3)
#define PB27            (0x1000000<<3)

#define PB28            (0x10000000<<0)     //0001 0000000
#define PB29            (0x10000000<<1)
#define PB30            (0x10000000<<2)
#define PB31            (0x10000000<<3)    //1000 0000000

/*********** PORT A PIN DEFINATION *************/

#define PA0             (0x1<<0)     //0001
#define PA1             (0x1<<1)
#define PA2             (0x1<<2)
#define PA3             (0x1<<3)     //1000

#define PA4             (0x10<<0)    //1 0000
#define PA5             (0x10<<1)
#define PA6             (0x10<<2)
#define PA7             (0x10<<3)    //1000 0000

#define PA8             (0x100<<0)
#define PA9             (0x100<<1)
#define PA10            (0x100<<2)
#define PA11            (0x100<<3)


#define PA12            (0x1000<<0)
#define PA13            (0x1000<<1)
#define PA14            (0x1000<<2)
#define PA15            (0x1000<<3)

#define PA16            (0x10000<<0)
#define PA17            (0x10000<<1)
#define PA18            (0x10000<<2)
#define PA19            (0x10000<<3)

#define PA20            (0x100000<<0)
#define PA21            (0x100000<<1)
#define PA22            (0x100000<<2)
#define PA23            (0x100000<<3)

#define PA24            (0x1000000<<3)
#define PA25            (0x1000000<<3)
#define PA26            (0x1000000<<3)
#define PA27            (0x1000000<<3)

#define PA28            (0x10000000<<0)     //0001 0000000
#define PA29            (0x10000000<<1)
#define PA30            (0x10000000<<2)
#define PA31            (0x10000000<<3)    //1000 0000000

/****************************/                                                 

