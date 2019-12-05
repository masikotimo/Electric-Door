#include<reg52.h>
#include "keypad.h"
#include "write.h"
#include "lightled.h"

void delay(unsigned int no);
void enable();
void lcdcmd(unsigned int  command);
void lcddata(char data1);
void lcdint();
char keypad();
void lcd_string(unsigned char *s);
void disp(unsigned char c);

										 

unsigned int m = 0;
unsigned int flag = 0;

char *p;
void main(){
	while(1){
		led=0;		
		enter_password();	
	}		
}
