
void timer_delay(){	//using the timer to generate a delay for 25ms
	TMOD=0x01;
	TH0=0xA5;
	TL0=0xFF;
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;
}