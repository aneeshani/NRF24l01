#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[2];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED1 = 3;

void setup(void){
 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 pinMode(LED1, OUTPUT);}

void loop(void){
 if (radio.available()){
   bool done = false;    
   while (!done){
     done = radio.read(msg, sizeof(msg));      
     Serial.println(msg[0]);
     if (msg[0]>800){digitalWrite(LED1, HIGH);}
     else {digitalWrite(LED1, LOW);}
     delay(10);}}
 else{Serial.println("No radio available");}}
