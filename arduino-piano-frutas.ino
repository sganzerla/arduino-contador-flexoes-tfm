#define _DO 1046 
#define _SOL 783
#define _LA 880
#define _FA 690

#define BUZZER 8

int tons = 1;

void setup()
{
  Serial.begin(9600);  
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
Serial.print("Analógico 1: ");
Serial.println(analogRead(0));

Serial.print("Analógico 2: "));
Serial.println(analogRead(1));

Serial.print("Analógico 3: "));
Serial.println(analogRead(2));

Serial.print("Analógico 4: "));
Serial.println(analogRead(3));

 

}
