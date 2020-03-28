#include <LiquidCrystal.h>

#define BUTTON_RESET_PIN 6

#define ECHO_PIN 7
#define TRIGGER_PIN 8

#define LED_RED_PIN 9
#define LED_GREEN_PIN 10
#define BUZZ_PIN 13

uint32_t timer = 0; 

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int flexao = 0;
bool contando = false;

void setup()
{
  setandoPinos();
  Serial.begin(9600);
}

void loop()
{

 long dist = (0.01723 * readUltrasonicDistance(TRIGGER_PIN, ECHO_PIN));

  contagem(dist);

  Serial.println(dist);
  exibindoTexto(dist);
}

void contagem(long distancia)
{
  noTone(BUZZ_PIN);
  if (distancia < 5)
  {
    digitalWrite(LED_RED_PIN, HIGH);
    digitalWrite(LED_GREEN_PIN, LOW);
    contando = true;
  }

  if (distancia > 20 && contando)
  {
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, HIGH);

    if (contando){
      flexao++;
      tone(BUZZ_PIN, 500);
      delay(250);
    } 
    contando = false;
  }
}

void setandoPinos()
{

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIGGER_PIN, LOW);

  pinMode(BUZZ_PIN, OUTPUT);
  noTone(BUZZ_PIN);

  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  lcd.begin(16, 2); // Define o display com 16 colunas e 2 linhas
  lcd.clear();      // limpa a tela do display
}

void exibindoTexto(long texto)
{

  // Exibe no display LCD o valor da humidade
  lcd.setCursor(0, 0); // Define o cursor na posição de início
  lcd.print("Qtd: ");
  lcd.print(flexao);
  lcd.print("     ");

  if (millis() - timer >= 1000)
  {

    // Exibe no display LCD o valor da temperatura
    lcd.setCursor(0, 1); // Define o cursor na posição de início
    lcd.print("Dist: ");
    lcd.print(texto);
    lcd.print("     ");
    timer = millis(); // Atualiza a referência
  }
}

long readUltrasonicDistance(int trigger, int echo)
{
  pinMode(trigger, OUTPUT); // Clear the trigger
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  pinMode(echo, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echo, HIGH);
}
