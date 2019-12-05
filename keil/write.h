#include <string.h>
unsigned int i=0, count, pwdcounter = 0, pwd =0,times;
char pin[]="12345";	// password, for the user
char admin_pin[]="14567"; // password, for the admin
char pinEntered[5];//array to store password entered by the user
char admin[5];//array to store password entered by the admin
// function prototypes
void admin_entry();
void alarm();
void light_led();

// start method enter_password
void enter_password(){
	// run the function forever
	while(1){
			lcdint(); // initialise the lcd
			lcdcmd(0x01); // clear the lcd
			memset(pinEntered, 0, 5);//reset the password			
			lcd_string("Enter accesscode");			
			lcdcmd(0xC0);//write on the second line of the lcd starting from first address				
			for(i=0;i<5;i++)
			 pinEntered[i] =keypad();// enter password fromkeypad
			lcdcmd(0x01);//clear the lcd
			// compare pasword entered to stored password			
			if (memcmp(pin,pinEntered, 5)== 0){
				memset(pinEntered, 0, 5);
				lcdcmd(0x01);//clear the lcd					
				lcd_string("Access Granted");						
				lcdcmd(0x01);//clear the lcd
				lcd_string("Door opened...");			
				light_led();
				break;
			}
			else{
				lcdcmd(0x01);//clear the lcd
				lcd_string("Access Denied");// write to the lcd			
				memset(pinEntered, 0, 5); // reset password
				count++;
				
				if(count==3){
					count = 0;
					lcdcmd(0x01);
					lcd_string("System locked");
					for(times=0; times<25; times++){
						alarm();
					}
					admin_entry();					
				}			
					
			}							
		 
		}
			  			
}// end method enter_password

// start method admin_entry
 void admin_entry(){
 	while(1){
	 	lcdint();
		lcdcmd(0x01);//clear lcd
		lcd_string("Only the admin");
		lcdcmd(0xc0);//write to second line of the lcd
		lcd_string("is allowed");
		lcdcmd(0x01);// clear lcd
		// reset admin password
		memset(admin, 0, 5);
		// write to lcd	
		lcd_string("Enter admin code");
		lcdcmd(0xc0);		
		for(i=0;i<5;i++)
			admin[i] =keypad();	// enter password fromkeypad
		if (memcmp(admin,admin_pin, 5)== 0){
			lcdcmd(0x01);					
			lcd_string("System unlocked");
			enter_password();
			break;
		}
		else{
			lcdcmd(0x01);					
			lcd_string("Password wrong");			
			admin_entry();		
		}

 	 }
 
 
 
 }// end method admin_entry






	
	
		