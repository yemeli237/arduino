
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define PIN_CE 6
#define PIN_CSN 7
#define pot A0
#define led 2
#define tunnel "00001";
RF24 radio(PIN_CE, PIN_CSN);

//const byte adresse[6]="00001";
const byte adresse[6]= tunnel;
const char text[]= "message recus de l.aute module";
struct DonneesAenvoyer {
  byte data1;
  const char text = "donner recus";
  };
DonneesAenvoyer data;







void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openWritingPipe(adresse);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  
//  data.data2 = "donnees recus";
  int val = analogRead(pot);
  val = val/5.7;
  Serial.println(val);
  if (val >= 1){
    digitalWrite(led, 1);
    data.data1 = 1;
    }else{
      digitalWrite(led, 0);
      data.data1 = 0;
      }
  
  radio.write(&data, sizeof(data));


}

  
