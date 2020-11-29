void setup() {
    
  Serial.begin(9600);

  int i,j,k,n;
  int isim[] = {77,117,104,97,109,109,101,100,32};
  int isim_2[] = {66,101,100,105,114,32};
  int soyad[] = {85,76,85,67,65,89};
  int selamla[] = {71,111,111,100,32,116,111,32,115,101,101,32,121,111,117}; 
  
  for (i=0;i<9;i++){
    Serial.write(isim[i]);
  }
  
  for(j=0;j<6;j++){
    Serial.write(isim_2[j]);
  }

  for(k=0;k<6;k++){
    Serial.write(soyad[k]);
  }
        Serial.println ("");

  for(n=0;n<15;n++){
    Serial.write(selamla[n]);
  }
}

void loop() {
  
}
