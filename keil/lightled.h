#include "delay.h"
#include <stdio.h>
unsigned char digit, time,num ;
unsigned int people=0;
unsigned char buffer[5];
sbit motor_pin_1 = P1^6;
sbit motor_pin_2 = P1^7;
sbit en_motor=P1^5;
sbit bcd1=P3^4;
sbit bcd2=P3^5;
sbit bcd3=P3^6;
sbit bcd4=P3^7;
sbit led=P3^3;
sbit buzz=P1^4;
void lcd_string(unsigned char *s);
void lcdcmd(unsigned int  command);
void lcddata(char data1);
void display_delay(unsigned char time);
void second_delay(unsigned int seconds);
void alarm_delay(int t);
void alarm();
/*function that works with the led, seven segment and motor*/
void light_led(){ 
	motor_pin_1 = 1; //rotates motor anticlockwise
	motor_pin_2 = 0;
	led=1;
	for(digit=2; digit>=0; digit--){
		display_delay(digit);
		if(digit==0){ 
			led=0;
    		bcd1=bcd2=bcd3=bcd4=1;
			break;
		}
		second_delay(60);
	}
	people++;
	for(time=0; time<5; time++){
		alarm();
	}

	lcdcmd(0x01);
	lcd_string("Door closing...");
	lcdcmd(0x01);
	lcd_string("People inside");
	lcdcmd(0xC0);		  
	sprintf(buffer,"%d",people);
	lcd_string(buffer);
	second_delay(1);
	motor_pin_1 = 1;//stops the motor
	motor_pin_2 = 1;
	timer_delay();
	motor_pin_1 = 0;
	motor_pin_2 = 1; //Rotates Motor Clockwise
	timer_delay();
	motor_pin_1 = 0;
	motor_pin_2 = 0; //Stops Motor
	second_delay(5);
}	
	 
void display_delay(unsigned char time){// count down from 2 minutes to 0
	if (time==1){
	 	bcd1=bcd2=bcd3=0;
		bcd4=1;
	}
	else if(time==2){
	 	bcd1=bcd2=bcd4=0;
		bcd3=1;
	 }
	 else if (time==0){
	 	bcd1=bcd2=bcd3=bcd4=0;
		second_delay(1);
	 }
}

void alarm(){//generates alarm
	int t; 
	for (t=0; t<100; t++){
		buzz=1;
		alarm_delay(0);
		buzz=0;
		alarm_delay(0);
	}
}

void alarm_delay(int t){//delay to toggle alarm
	int i,j;
		for(i=0;i<=t;i++){
			for(j=0;j<10;j++){}
		}
	
}
void second_delay(unsigned int seconds){//generates delay accordint to specified number of seconds
 	unsigned int count, sec;
 	for(sec=0; sec<seconds; sec++){
		for (count=0; count<40; count++){
			timer_delay();
		}
	}
 
 }



   
