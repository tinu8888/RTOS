#include"config.h"
#include"stdlib.h"
#include<LPC21XX.h>
#include<lcd.h>
OS_STK Task1Stack[50];
void Task1(void *pdata);


OS_STK Task2Stack[100];
void Task2(void *pdata);

OS_STK Task3Stack[150];
void Task3(void *pdata);

OS_STK Task4Stack[256];
void Task4(void *pdata);



static OS_EVENT *semaphore;

int main(void)
{

LCD_init();
	LCD_display(1,1,"Sema create");
	OSInit();
	semaphore=OSSemCreate(1);
	if(semaphore!=NULL)
	{
LCD_display(1,1,"Sema create");

	}
	else
	{
		LCD_display(1,1,"Sema not create");
	}
	delay();
	LCD_cmd(0x01);  
	delay();

	OSTaskCreate(Task1,(void *)0,&Task1Stack[49],0);
	OSTaskCreate(Task2,(void *)0,&Task2Stack[99],1);
	OSTaskCreate(Task3,(void *)0,&Task3Stack[149],2);
	OSTaskCreate(Task4,(void *)0,&Task4Stack[255],3);

	OSStart();
	return 0;
}

void Task1(void *pdata)
{
	int n,i;
	char err;
	pdata=pdata;
	LCD_init();
	while(1)
	{
		OSSemPend(semaphore,1,&err);
		LCD_cmd(0x01);  (0x01);
			LCD_display(1,1,"Task1");
		for(i=0;i<900000;i++)
		for(i=0;i<900000;i++);
	LCD_cmd(0x01);
		OSSemPost(semaphore);
		OSTimeDly(1000);
	}
}

void Task2(void *pdata)
{
	int n,i;
	char err;
	pdata=pdata;
	LCD_init();
	while(1)
	{
		OSSemPend(semaphore,1,&err);
		LCD_display(1,1,"Task2");
		for(i=0;i<900000;i++)
		for(i=0;i<900000;i++);
		LCD_cmd(0x01);
		OSSemPost(semaphore);
		OSTimeDly(500);
	}
}

void Task3(void *pdata)
{
	int n,i;
	char err;
	pdata=pdata;
	LCD_init();

	while(1)
	{
		OSSemPend(semaphore,1,&err);
		LCD_display(1,1,"Task3");
		for(i=0;i<900000;i++)
		for(i=0;i<900000;i++);
	LCD_cmd(0x01);
		OSSemPost(semaphore);
		OSTimeDly(500);
	}
}
void Task4(void *pdata)
{
	int n,i;
	char err;
	pdata=pdata;
	LCD_init();

	while(1)
	{
		OSSemPend(semaphore,1,&err);
		LCD_display(1,1,"Task4");
		for(i=0;i<900000;i++)
		for(i=0;i<900000;i++);
		LCD_cmd(0x01);
		OSSemPost(semaphore);
		OSTimeDly(500);
	}
}