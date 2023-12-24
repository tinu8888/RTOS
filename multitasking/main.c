#include "config.h"
#include "stdlib.h"
#include<LPC21xx.H>

#define	TaskStkLengh 64        	//Define the Task0 stack length
 
OS_STK	TaskStk0 [TaskStkLengh];    	//Define the Task0 stack
OS_STK	TaskStk1 [TaskStkLengh];    	//Define the Task0 stack
OS_STK	TaskStk2 [TaskStkLengh];    	//Define the Task0 stack
OS_STK	TaskStk3 [TaskStkLengh];    	//Define the Task0 stack

void 	Task1(void *pdata);        	//Task0
void	Task2(void *pdata);    
void	Task3(void *pdata);

 void Task3	(void *pdata)
{               	 
	pdata = pdata;
	TargetInit ();
   	lcd_msg(2,0,"TASK 3");
        	OSTimeDly(100);
    	LCD_CLEAR();
    

}
 
void Task1	(void *pdata)
{
	pdata = pdata;
              	 
    	lcd_msg(1,0,"TASK 1");
   //      	LED_RUNNING_LIGHT();
            	OSTimeDly(100);
            	LCD_CLEAR();
//            	OSTaskChangePrio(1,2);
   	 
}
void Task2  (void *pdata)
{
	pdata = pdata;
              	 
   	// lcd_msg(1,5,"TASK 2");
           	LED_RUNNING_LIGHT();
            	OSTimeDly(100);
       	/// 	LCD_CLEAR();
//            	OSTaskChangePrio(1,2);
   	 
}

int main (void)
{

 	//IODIR1=0x00ff0000;
	OSInit ();    
	init_LCD();
//	LPC_2148_BSP_INIT();
    
//	OSTaskCreate (Task1,(void *)0, &TaskStk[TaskStkLengh - 1], 5);
//	OSTaskCreate (Task0,(void *)0, &TaskStk[TaskStkLengh - 1], 3);
	OSTaskCreate (Task2,(void *)0, &TaskStk2[TaskStkLengh - 1], 6);
	OSTaskCreate (Task3,(void *)0, &TaskStk3[TaskStkLengh - 1], 3);
	OSTaskCreate (Task1,(void *)0, &TaskStk1[TaskStkLengh - 1], 5);
//	OSTaskCreate (Task3,(void *)0, &TaskStk[TaskStkLengh - 1], 3);                                                                                               	 
//	OSTaskCreate (Task3,(void *)0, &TaskStk[TaskStkLengh - 1], 2);


       	 
	OSStart ();
	return 0;                                                       	 
}
