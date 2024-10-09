#define out1 18
#define in1 2
long startTime = micros();
long currentTime = 0;
long pulseWidth = 0;
int state = 0;

void setup() {
  //Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(out1, OUTPUT);
  pinMode(in1, INPUT_PULLUP);

  Serial1.println("M1:2047");
  Serial1.println("M2:2047");
  delay(2000);
  Serial1.println("M1:0");
  Serial1.println("M2:0");
  delay(2000);
  Serial1.println("M1:-2047");
  Serial1.println("M2:-2047");
  delay(2000);
  Serial1.println("M1:-2047");
  Serial1.println("M2:2047");
  delay(2000);
  Serial1.println("M1:0");
  Serial1.println("M2:0");
  delay(2000);

  //attachInterrupt(digitalPinToInterrupt(in1),timeCheck,CHANGE);
}

void loop() {
  /*if (pulseWidth < 2000) {
    if (pulseWidth > 1600 && state != 1) {
      state = 1;
      //Serial.println("State 1");
      Serial1.println("M1:2047");
      delay(1000);
    } else if (pulseWidth < 1300 && state != 2) {
      state = 2;
      //Serial.println("State 2");
      Serial1.println("M1:-2047");
      delay(1000);
    } else if (state != 3) {
      state = 3;
      //Serial.println("State 3");
      Serial1.println("M1:0");
      delay(1000);
    }
  }*/
}

void timeCheck() {
  currentTime = micros();
  if (currentTime > startTime) {
    pulseWidth = currentTime - startTime;
    startTime = currentTime;
  }
}