#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
#define out1 18

const byte address[6] = "00001";

void setup() {
  //Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(out1, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    //Serial.println(text);
    String s = String(text);
    if (s.equals("one")) {
      Serial1.println("M1:2047");
      Serial1.println("M2:2047");
    } else if (s.equals("two")) {
      Serial1.println("M1:-2047");
      Serial1.println("M2:-2047");
    } else if (s.equals("three")) {
      Serial1.println("M1:-2047");
      Serial1.println("M2:2047");
    } else if (s.equals("four")) {
      Serial1.println("M1:2047");
      Serial1.println("M2:-2047");
    } else {
      Serial1.println("M1:0");
      Serial1.println("M2:0");
    }
  }
}