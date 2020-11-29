
int led = 13;         // Arduino uzerindeki ledin pin degeri 
int button = 4;
////==================================================================================
void setup() {
  
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}
////==================================================================================

void loop() {


    char Operation='0';              // Operasyon degiskeni
    
    if( Serial.available()){
    
      Operation=Serial.read();     // C den gelen komutu okuyor
    }
    
    if(Operation == '1'){        // Ledi aciyor
      
        digitalWrite(led,HIGH);                
    }
   
    else if(Operation == '2'){     // Ledi sonduruyor
      
      digitalWrite(led,LOW);
    }  


    else if(Operation == '3'){      //Blink fonksiyonuna gonderir
      
        Blink3();  
    }

     else if(Operation == '4'){      //Karesini alma fonksiyonunan gonderir
      
        SquareFonk();
     } 
    
      else if(Operation == '5'){            //Push button fonsiyonuna gonderir            
                
        PushButton(); 
      }
}     
////========================================================================================================= 
 void SquareFonk(){
  
  int Number=0;
  int k=1;
  
  while(1){
    
     if(Serial.available()){       // Baglanti yolunu kontrol ediyor
                
        delay(100);         
        String Data = Serial.readString();   // C den gelen komutu okuyor            
        delay(10);
                    
        Number = Data.toInt();       //Stringi integer a ceviriyor
        Number=Number*Number;        //Sayinin karesini aliyor
      
        Serial.println(Number);      //Okunacak degeri yazdiriyor
              
        if(Number>0 || k+Number == 1){   //C den bir deger okundugunda dongunun kirilmasi icin gerkeli sartlari iceren fonk.
           break;
        }        
     }
  }
}
////==============================================================================================================
//fonsiyon dizi[2] uzerine kurulu  Not push komutu surekli 0 degeri okuyor Push 1 okuyor

void PushButton(){

     int count=0;        //sayac
     int pushButton=0;  //Ilk sifir atandi cunku ilk durum not push durumu
     int dizi[2];       // Farki gormek icin (0 dan 1 e donusumu) 
        
      while(1){
          
         dizi[0] = pushButton;         //ilk karakteri okuyor
         pushButton = digitalRead(4);
         dizi[1] = pushButton;         //Degisim olursa yani butona basilirsa 1 basilmassa 0 aliyor
     
         if(dizi [0] != dizi[1]){       //Digitalread deki degisim olursa fonkicine giriyor  (0 dan 1) veya(1 den 0)a  
             if(dizi[1]==0){            // eger degisim 0 dana 1 e ise count 1 artiriyor
                 count ++;
                 Serial.println(count);  //Serial monitore c nin almasi icin yazdiriyor
              }       
          }
          delay(20);     //Stabilite icin
       }
}

////===============================================================================================================

void Blink3(){
  
  for(int i=0;i<3;i++){         // Ledi 3 kez yakip sonduren dongu
     
      digitalWrite(led,HIGH);    //Ledi yakiyor
      delay(500);
      digitalWrite(led,LOW);    //Ledi sonduruyor
      delay(500);
      } 
}

////===============================================================================================================
