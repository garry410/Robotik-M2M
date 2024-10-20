//Latar Belakang:
//Terinspirasi dari mainan 'kerang ajaib' dari kartun animasi Spongebob

//Rumusan Masalah
//Bagaimana cara membuat prototype mainan 'kerang ajaib' di dunia nyata menggunakan Arduino UNO?

//Tujuan Proyek:
//-Membuat mainan yang mirip dengan 'kerang ajaib'

// Daftar Pustaka:
// https://docs.arduino.cc/language-reference/en/functions/random-numbers/random/

const int buzzerPin = 10;
const int ledMerahPin = 8;
const int ledHijauPin = 9;
const int triggerPin = 12;
const int echoPin = 11;

int durasi;
int jarak;
int randomNumber;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledMerahPin, OUTPUT);
  pinMode(ledHijauPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() 
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  durasi = pulseIn(echoPin, HIGH);
  jarak = (durasi * 0.017);
  

  if ((jarak - 1) < 7) 
  {
    tone(buzzerPin, 262, 250);
    randomNumber = random() % 2;
	  if (randomNumber == 1) 
    {
      digitalWrite(ledMerahPin, LOW);
      digitalWrite(ledHijauPin, HIGH);
    }
    else 
    {
      digitalWrite(ledMerahPin, HIGH);
      digitalWrite(ledHijauPin, LOW);
    }
  } 
  else 
  {
    digitalWrite(ledMerahPin, LOW);
    digitalWrite(ledHijauPin, LOW);
  }

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println("cm");
  delay(1000);
}
