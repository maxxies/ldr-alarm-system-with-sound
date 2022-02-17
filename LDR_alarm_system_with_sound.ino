//Variables

int greenLed = 11;
int redLed = 10;
int piezoSound = 9;
int btn = 6;
int ldr = 3;
bool flash = false;

void setup() {
  // put your setup code here, to run once:

  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(btn,INPUT);

  //Indicates start of program
  tone(piezoSound, 2000);
  delay(200);
  tone(piezoSound, 2000);
  delay(200);
  noTone(piezoSound);
  
  digitalWrite(greenLed, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrvalue = analogRead(ldr); //reads value from LDR 
  if(ldrvalue <= 300){  //Checks if light to LDR is blocked
    soundAlarm(); //sets alarm
   }

  //Resets alarm system
  int btnValue = digitalRead(btn);
  if (btnValue == HIGH){
    flash = false;
    noTone(piezoSound);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(1000);
  }
   
}

void soundAlarm(){
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  delay(200);
  
  //Calculates frequencies for alarm
  for(int x=0; x< 180;x++){
    int sinVal = (sin(x * (3.1412/180)));
    int toneVal = (2000 *(int(sinVal) * 1000));
    tone(piezoSound, toneVal);
    delay(2);
  }
  
  flash = true;
  
  //Flashes red LED light indicating that there has been a breach if sound was not heard
  while(flash){
    noTone(piezoSound);
    digitalWrite(redLed, LOW);
    delay(400);
    digitalWrite(redLed, HIGH);
    delay(700);
    }
}


