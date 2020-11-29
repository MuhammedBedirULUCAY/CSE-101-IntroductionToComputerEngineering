#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

void Led_Turn_On();
void Led_Turn_Off();
void Led_Blink();
void Square_Num();
void Buton_Count();
void delay(int);
void Menu();


int main()
{
	char serialport = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );					//Serial baglanti acilir
	char Operation[5];

	printf("#-# WELCOME TO GTU ARDUINO LAB         #-#\n");
	printf("#-# MUHAMMED BEDIR ULUCAY  1901042697  #-#\n");
	printf("#-# PLEASE SELECT FROM THE FOLLOWING   #-#\n");

	while (1){

		Menu();
		scanf("%s",Operation);													//Operasyon okunur	
		printf("(First character chosen)\n");	
		
		if(Operation[0] == '0'){								
			return 0;												
		}																
																			
		else if(Operation[0] == '1'){											
			Led_Turn_On();																
		}																				
																							
		else if(Operation[0] == '2'){															
			Led_Turn_Off();																		
		}																			// Kosullara gore islemler yapilir			
																								
		else if(Operation[0] == '3'){															
			Led_Blink();																		
		}																									
																		 
		else if(Operation[0] == '4'){									
			Square_Num();											  
		}															 
																	
		else if(Operation[0] == '5'){									
			Buton_Count();										   		
		}														  
																 		
		else {												    
			printf("-------------------------------\n");	   
			printf("!!!---  UNKNOWN COMMAND  ---!!!\n");	  
			printf("-------------------------------\n");	 	
		}													

		close(serialport);														//Serial baglanti kapanir

	}
	
	return 0;
}

//*===========================================================================================*//

void Menu(){

	printf("# # MENU                               # #\n");
	printf(" (1) TURN ON LED ON ARDUINO 			  \n");
	printf(" (2) TURN OFF LED ON ARDUINO 			  \n");
	printf(" (3) FLASH ARDUINO LED 3 TIMES 			  \n");
	printf(" (4) SEND A NUMBER TO ARDUINO TO COMPUTE  \n     SQUARE BY ARDUINO \n");
	printf(" (5) BUTTON PRESS COUNTER 				  \n");
	printf(" (0) EXIT                                 \n");
	printf(" PLEASE SELECT  : ");

}

//*===========================================================================================*//

void Led_Turn_On(){

	char serialport = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );			// Serial baglantiyi acar
	delay(500);

	write(serialport,"1",2);														// Arduinoya '1' karakterini gonderir

	printf("----------------------------\n");
	printf("----    LED TURNED ON   ----\n");
	printf("----------------------------\n");

	close(serialport);																// Serial baglantiyi kapatir		
}

//*===========================================================================================*//

void Led_Turn_Off(){

	char serialport = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );		    // Serial baglantiyi acar
	delay(500);

	write(serialport,"2",1);                                                        // Arduinoya '2' karakterini gonderir

	printf("----------------------------\n");
	printf("----   LED TURNED OFF   ----\n");
	printf("----------------------------\n");

	close(serialport);																// Serial baglantiyi kapatir
}

//*============================================================================================*//

void Led_Blink(){

	char serialport = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );			// Serial baglantiyi acar
	delay(500);

	write(serialport,"3",1);														// Arduinoya '3' karakterini gonderir
			
	printf("----------------------------\n");
	printf("---  LED BLINKED 3 TIMES ---\n");
	printf("----------------------------\n");

	close(serialport);																// Serial baglantiyi kapatir
}

//*=============================================================================================*//

void Square_Num(){

	char serialport = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );			// Serial baglantiyi acar
	delay(500);

	write(serialport,"4",1);														// Arduinoya '4' karakterini gonderir

	char number[10];      						//Kullanicidan alinan sayi
			
	int i;										//Kullanicidan alinan sayinin uzunlugunu degeri
	unsigned char data[9];						//Arduinonun hesabindan sonra okurken saklanacak yer 
	char read_byte;								//Okunan her byte saklnadigi yer
	int result;									//Sonucun atanacagi degisken 

	printf("----------------------------\n");		
	printf("Enter the number :  ");
	scanf("%s",number);							//Sayi alinir		

	i=strlen(number);							//String uzunlugu belirler

	write(serialport,number,i);

	printf("----Calculating....\n");	
			
	delay(8000);								//Arduinonun hesapi icin tanin sure 
							
	read_byte = read(serialport,data,9);		//Arduino verileri okunur	
			
	result = atoi(data);						//String integer'a cevirir
		
	printf("Square of %s^2 = %d\n",number,result);	//Ekrana yazdirir
	printf("----------------------------\n");		

	close(serialport);																//Serial baglanti kapatir

}

//*===============================================================================================*//

void Buton_Count(){

	char serialport = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );			// Serial baglantiyi acar
	delay(500);

	write(serialport,"5",1);														//Arduino ya '5' karakterini gonderir

	delay(1000);

	unsigned char count[5];										//Arduinodan alinacak verinin koyulacagi yer
	char read_byte;												//Okunacak verilerin atanacagi yer	
	int times=0;												//Basilan degerin oldugu degisken
	int sup;													//Denkleme destek olmasi icin gereken degisken

	printf("----------------------------\n");		

	read_byte = read(serialport,count,5);						//Arduinodaki ilk byte count a atanir 

	sup = atoi(count);											//Count int e cevirilip sup a atanir

	printf("%d times pushed\n",sup );							//Ilk deger 0 olacagi icin 0 times pushed yazilir

	while(1){	

		if(times != sup){										//times sup dan farkliysa yani butona basilip serial monitordeki deger degismeden hic bisey yazdirmiyor
			printf("%d times pushed\n",times);			
			sup = times;										//times sup a atanarak sup degistirilir tekrardan surekli yazilmasini engeller		
		}	
		
		read_byte = read(serialport,count,5);					//Arduinodaki veriler count a atanir
		times = atoi(count);									//count integer a cevirilip times atanir

		delay(300);												//Stabilite icin her dongu arasi kisa bir bekleme suresi gecer	
	}
	close(serialport);																//Serial baglanti kapanir	
}

//*======================================================================================================*//

void delay(int time){									//Arduino yu beklemek icin bos islem yaptiran yani sure geciren fonksiyon

	int i,j,k;

	for( i=0;i<time;i++){
		for( j=0;j<9999;j++){
			for( k=0;k<20;k++){
			}
		}
	}
}

//*======================================================================================================*//
