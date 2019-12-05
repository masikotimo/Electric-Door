// initialise pins
sbit r0=P2^7;
sbit r1=P3^0;
sbit r2=P3^1;
sbit r3=P3^2;
sbit c0=P2^4;
sbit c1=P2^5;
sbit c2=P2^6;
sbit en=P2^2;
sbit rs=P2^0;
sbit rw=P2^1;
sbit busy_flag=P2^3;

// start method delay
void delay(unsigned int no){
		unsigned int i,j;
		for(j=0;j<=(1000*no);j++)
		for(i=0;i<=10;i++); 
}
// start method lcd_busy
void lcd_busy(){
	busy_flag=1;
	rs=0;
	rw=1;
	while(busy_flag==1){
		en=0;
		delay(1);
		en=1;

	}
}
  

// start method enable
void enable(){
	  en = 1;
	  delay(1);
	  en = 0;
}

// start method lcdcmd
void lcdcmd(unsigned int  command){
		lcd_busy();
	    rw=0;
		rs=0;
		P0=command;		
		enable();
}

// start method lcddata
void lcddata(char data1){
		lcd_busy();
		rs = 0;	  
		P0=data1;
		rw=0;
		rs=1;
		enable();
}

// start method lcdint
void lcdint(){		
		lcdcmd(0x30);		
		lcdcmd(0x38);		
		lcdcmd(0x01);		
		lcdcmd(0x0F);	
		lcdcmd(0x80);	
}
// display information to the lcd
void disp(unsigned char c){
		 rs = 1;
		 lcddata(c);

}
// send a string to the lcd
void lcd_string(unsigned char *s){
		while(*s)
		disp(*s++);

}

// send the activated number to the lcd
char keypad(){		
		while(1){
				r0=0;r1=1;r2=1;r3=1;
				if(c0==0){lcddata('*');delay(5);return '1';}
				if(c1==0){lcddata('*');delay(5);return '2';}
				if(c2==0){lcddata('*');delay(5);return '3';}

				r0=1;r1=0;r2=1;r3=1;
				if(c0==0){lcddata('*');delay(5);return '4';}
				if(c1==0){lcddata('*');delay(5);return '5';}
				if(c2==0){lcddata('*');delay(5);return '6';}

				r0=1;r1=1;r2=0;r3=1;
				if(c0==0){lcddata('*');delay(5);return '7';}
				if(c1==0){lcddata('*');delay(5);return '8';}
				if(c2==0){lcddata('*');delay(5);return '9';}

				r0=1;r1=1;r2=1;r3=0;			
				if(c1==0){lcddata('*');delay(5);return '0';}			
		}
}



