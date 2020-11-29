#include <stdio.h>

void Menu();
void Add();
void Subtract();
void Multiply();			//fonksiyonlari tanimladim
void Divide();
void Power();
float Average();
float Max();

int main(){

	char  operation[10];						//Main fonksiyonundaki degiskenleri tanimladim
	float result;

	printf("%% WELCOME TO GTU CALCULATOR MACHINE   %%\n");
	printf("%% STUDENT NAME: MUHAMMED BEDIR ULUCAY %%\n");		//Giris yeri
	printf("%% PLEASE SELECT FROM THE FOLLOWING    %%\n");

	while (1){
		
		printf("_____________________________________\n\n");
		Menu();	
		scanf(" %s",operation); 
		printf("YOUR FISRST CHARACTER CHOOSEN\n");  //girilecek satirdaki ilk karakter secilecek
		printf("_____________________________________\n\n");

		switch(operation[0]){


			case '0':
					    return 0;
				  		break;

			case '1':
						Add();					  
				  		break;

			case '2':
						Subtract();	
				  		break;
						
			case '3':
						Multiply();	 		
				  		break;

			case '4':		
						Divide();		
				  		break;
						
			case '5':
						Power();
				  		break;
						
			case '6':
						result = Average();
						printf("Average of numbers -> %.2f\n", result);						 
				  		break;

			case '7':
						result = Max();
						printf("Max of numbers %.2f\n",result);		  
				  		break;
						
			default:
			    		printf("--%s UNKNOWN COMMOND--\n",operation);
		}			
	}

	return 0;   
}

void Menu(){

	printf("%% MENU :                              %%\n");						
	printf("(1) ADD TWO NUMBERS\n");
	printf("(2) SUBTRACT TWO NUMBERS\n");
	printf("(3) MULTIPLY TWO NUMBERS\n");
	printf("(4) DIVIDE TWO NUMBERS\n");
	printf("(5) TAKE THE NTH POWER OF A NUMBER\n");
    printf("(6) FIND AVERAGE OF NUMBERS INPUTTED\n");
	printf("(7) FIND THE MAXIMUM OF NUMBERS INPUTTED\n");
	printf("(0) EXIT\n");
	printf("PLEASE SELECT :  ");  
	
}

void Add(){   					//Toplama fonksiyonu

	float Num_1,Num_2;
	float result;

	printf("Enter first number -> ");	
	scanf("%f",&Num_1);
	printf("Enter second number -> ");
	scanf("%f",&Num_2);

	result = Num_1+Num_2;
	printf("%.2f+%.2f = %.2f\n",Num_1,Num_2,result);
}

void Subtract(){ 				//Cikarma fonksiyonu

	float Num_1,Num_2;
	float result;

	printf("Enter first number -> ");	
	scanf("%f",&Num_1);
	printf("Enter second number -> ");
	scanf("%f",&Num_2);

	result = Num_1-Num_2; 
	printf("%.2f-%.2f = %.2f\n",Num_1,Num_2,result);					
}

void Multiply(){				//Carpma fonksiyonu

	float Num_1,Num_2;
	float result;

	printf("Enter first number -> ");	
	scanf("%f",&Num_1);
	printf("Enter second number -> ");
	scanf("%f",&Num_2);

	result= Num_1*Num_2;
	printf("%.2f*%.2f = %.2f\n",Num_1,Num_2,result);					
}

void Divide(){					//Bolme fonksiyonu

	float Num_1,Num_2;
	float result;

	printf("Enter first number -> ");	
	scanf("%f",&Num_1);
	printf("Enter second number -> ");
	scanf("%f",&Num_2);

	result = Num_1/Num_2; 
	printf("%.2f/%.2f = %.2f\n",Num_1,Num_2,result);					
}

void Power(){				//Kuvvet fonksiyonu
	
	int i;
	float result=1,base,power;
	
	printf("Enter the base  -> ");
	scanf("%f",&base);					//Tabani ve ussu alir
	printf("Enter the power -> ");
	scanf("%f",&power);

	for(i=0;i<power;++i){				//Us kadar sayiyi kendisi ile carpmayi sagliyor

		result = result*base; 
		printf("%.2f*",base );
	}	
	printf(" = %.2f\n",result);
	printf("%.2f^%.2f = %.2f\n",base,power,result);
}

float Average(){         				//Max sayi bulma fonksiyonun		

	float avg;
	float sum=0;
	float number=0;
	int Pc=0;
	int operation;

	printf("\n- If you want to stop enter -1 -\n");

	while(number != -1){				//Dongu -1 girilene kadar devam eder

		printf("Enter %d. number -> ",Pc+1);
		scanf("%f",&number);
		
		if (number == -1){  // while dongusunden cikmak icin kosul

			printf("\n--If you want to exit press >1 \n");
			printf("--Or you want -1 as a number press >2 \n   Choose  -->");
			scanf("%d",&operation);
			
			if(operation == 1){ //cikmak istiyorsa donguyu kiriyor
				break;
			}
			
			else if(operation == 2){ //istemiyorsa dongu devam ediyor
				number=0;
				sum--;				// -1 sayi oldugu icin toplam 1 eksiliyor
				Pc++;				//  Pc sayac bir artiriliyor	
				continue;
			}

			else {
				printf("Unknown command\n");
			}
		}
								//printf("S%f  C%d \n",sum,Pc );
		sum+=number; 			//Sayiyi toplamla topluyor
		Pc++;					//Sayac artiyor

	}
								//printf("S%f  C%d \n",sum,Pc );
		avg = sum/Pc;
		return avg;
}	

float Max(){       				//Max bulma fonsiyonu

	float Max;
	float number;
	int operation;
	int pc=0;             // Ilk degerin max yapilmasini sagliyor

	printf("-- If you want to stop enter '-1' -\n"); 

	while(number != -1 ){         // -1 girilince dongu bitirme

 		printf("Enter %d. number -> ",pc+1); //Sayi aliyor
 		scanf("%f",&number);

 		if(pc == 0){        //ilk terimi max yapiyor
 			Max=number;
 		}	

	 	if (number == -1){  // while dongusunden cikmak icin kosul

			printf("\n--If you want to exit press >1 \n");
			printf("--Or you want -1 as a number press >2 \n");
			scanf(" %d",&operation);
			
			if(operation == 1){ //cikmak istiyorsa donguyu kiriyor
				break;
			}
			
			else if(operation == 2){ //istemiyorsa dongu devam ediyor
			
			}

			else {
				printf("Unknown Command\n");   // 1-2 Harici degerlerde yaziliyor 
			}	
		}

		if(number > Max){   //Eger sonradan girilen herhangi bir deger 
 						    //max tan buyukse o deger artik max oluyor
 		Max=number;
	 	
	 	}
	 	//    printf("%f\n",Max );
	 	
	 	if(number== -1){   //-1 giriliip dongu kirilmadiysa donguyu devam ettirmek icin
	 		number--;
	 	}

	 	pc++;    	// Ilk degerin max olmasini saglayan 0 degeri degistiriliyor  
	}

	return Max;
}
