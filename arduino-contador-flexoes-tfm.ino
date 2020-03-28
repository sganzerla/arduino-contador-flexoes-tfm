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

// variáveis limites de altura da distância
int dist_abaixo_cm = 5;
int dist_acima_cm = 25;

void setup()
{
  setandoPinos();
  Serial.begin(9600);
}

void loop()
{

  long dist = (0.01723 * readUltrasonicDistance(TRIGGER_PIN, ECHO_PIN));

  contandoFlexoes(dist);

  Serial.println(dist);
  exibindoTexto(dist);

  resetContagem();
}

void resetContagem()
{
  if (!digitalRead(BUTTON_RESET_PIN)){
      flexao =  0;
       digitalWrite(LED_GREEN_PIN, LOW);
              digitalWrite(LED_RED_PIN, LOW);

    contando = false;
  }
}

void contandoFlexoes(long distancia)
{
  noTone(BUZZ_PIN);
  if (distancia < dist_abaixo_cm)
  {
    digitalWrite(LED_RED_PIN, HIGH);
    digitalWrite(LED_GREEN_PIN, LOW);
    contando = true;
  } else if (distancia > dist_acima_cm && contando)
  {
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, HIGH);

    if (contando)
    {
      flexao++;
      tone(BUZZ_PIN, 500);
      delay(250);
    }
    contando = false;
  }
}

void setandoPinos()
{

  pinMode(BUTTON_RESET_PIN, INPUT_PULLUP);
  digitalWrite(BUTTON_RESET_PIN, HIGH);

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

  lcd.setCursor(0, 0); // Define o cursor na posição de início
  lcd.print("Qtd: ");
  lcd.print(flexao);
  lcd.print("     ");

  if (millis() - timer >= 1000)
  {

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
