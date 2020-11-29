
int maximumRange = 100;                                 //max range to turn on the buzzer
int minimumRange = 0;                                   //min range to turn on the buzzer

void setup() {
  int trigPin=7;                                        //checker pin on the transmitter
  int echoPin=8;                                        //receiver pin on the transmitter
  int buzzerPin=9;                                      //Power supply of buzzer
  pinMode(trigPin, OUTPUT);                             // Sensörün çıkış pini
  pinMode(echoPin, INPUT);                              // Sensörün Alıcı pini
  pinMode(buzzerPin, OUTPUT);                           // Sensörün güç kaynağı

}

void loop() {

  int olcum = mesafe(maximumRange, minimumRange);       //ölçüm fonksiyonu
  nota(olcum*2);                                        //buzzerdan çıkan ses tonu
}

int mesafe(int maxrange, int minrange)
{
  long duration, distance;
  int trigPin=7;
  int echoPin=8;
  int buzzerPin=9;
  digitalWrite(trigPin,LOW);                            //trigPini kapatır
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                          //trigPini açar
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);                           //trigPini kapatır
  
  duration = pulseIn(echoPin, HIGH);                    //açılış-kapanış arası geçen süreyi ölçer
  distance = duration / 58.2;
  delay(50);                                            //bekleme süresi
  if(distance >= maxrange || distance <= minrange)      //distance belirlenen mesafeler arasında değilse ötmez
  return 0;
  return distance;                                      //distance belirlenen mesafeler arasında ise öter
}

int nota(int dly)
{
  int buzzerPin=9;
  tone(buzzerPin, 1000);                                //buzzerin çıkardığı ses tonu
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
  
}
