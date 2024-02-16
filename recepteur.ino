
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define PIN_CE 6
#define PIN_CSN 7
#define tunnel "00001"
#define led 4
RF24 radio(PIN_CE, PIN_CSN);

//const byte adresse[6]="00001";
const byte adresse[6]= tunnel;
char text[32];
struct DonneesAenvoyer {
  byte data1;
  char data2;
  };
DonneesAenvoyer data;






void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  radio.begin();
  radio.openReadingPipe(0, adresse);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();


}

void loop() {

  if(radio.available()){
      radio.read(&data, sizeof(data));
      Serial.println(data.data1);
      if (data.data1 == 1){
        digitalWrite(led, 1);
        }else{
          digitalWrite(led, 0);
          }
    }
}

  
