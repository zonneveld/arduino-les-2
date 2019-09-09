//Opdracht:
//Bekijk de layout teramin.jpg, en kopieer het op je breadboard,
//Maak vervolgens de volgende code af, en test het

#define LDRPIN A0
#define BUZZERPIN 8
#define BUTTONPIN 2

void setup() {
  //Vul de juiste richting in voor de volgende pinnen
  pinMode(LDRPIN,INPUT);
  pinMode(BUTTONPIN,INPUT);
  pinMode(BUZZERPIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // vervang de ....PIN met de juiste PIN naam (zie bovenaan bij de #defines
  if(digitalRead(....PIN) == HIGH)
  {
    int value = analogRead(....PIN);
    value = map(value,0,1024,100,4000);
    Serial.println(value);
    tone(....PIN,value,10);
  }
}
