int A = 2;
int B = 3;
int C = 5;
int DP = 4;
int D = 6;
int E = 7;
int F = 8;
int G = 9;

int gantiPinAtas = 12;
int gantiPinBawah = 11;
int counter = 0;
int tombolAtas = 0;
int tombolTerakhirAtas = 0;
int tombolBawah = 0;
int tombolTerakhirBawah = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  pinMode(gantiPinAtas, INPUT);
  pinMode(gantiPinBawah, INPUT);

  digitalWrite(DP ,HIGH);
  gantiAngka(counter);
}

void loop()
{
  tombolAtas = digitalRead(gantiPinAtas);
  tombolBawah = digitalRead(gantiPinBawah);

  if (tombolAtas != tombolTerakhirAtas)
  {
    if (tombolAtas == HIGH)
    {
      if (counter < 9) 
      {
        counter++;
      }
      Serial.println(counter);
      gantiAngka(counter);
      delay(200);
    }
    else
    {
      Serial.println("OFF");
    }
  }

  if (tombolBawah != tombolTerakhirBawah)
  {
    if (tombolBawah == HIGH)
    {
      if (counter > 0) 
      {
        counter--;
      }
      Serial.println(counter);
      gantiAngka(counter);
      delay(200);
    }
    else
    {
      Serial.println("OFF");
    }
  }

  tombolTerakhirAtas = tombolAtas;
  tombolTerakhirBawah = tombolBawah;
  
  delay(10);
}

void gantiAngka(int buttonPress)
{
  switch (buttonPress)
  {
    case 0:
      digitalWrite(A, LOW); digitalWrite(B, LOW); digitalWrite(C, LOW);
      digitalWrite(D, LOW); digitalWrite(E, LOW); digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    case 1:
      digitalWrite(A, HIGH); digitalWrite(B, LOW); digitalWrite(C, LOW);
      digitalWrite(D, HIGH); digitalWrite(E, HIGH); digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 2:
      digitalWrite(A, LOW); digitalWrite(B, LOW); digitalWrite(C, HIGH);
      digitalWrite(D, LOW); digitalWrite(E, LOW); digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    case 3:
      digitalWrite(A, LOW); digitalWrite(B, LOW); digitalWrite(C, LOW);
      digitalWrite(D, LOW); digitalWrite(E, HIGH); digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    case 4:
      digitalWrite(A, HIGH); digitalWrite(B, LOW); digitalWrite(C, LOW);
      digitalWrite(D, HIGH); digitalWrite(E, HIGH); digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 5:
      digitalWrite(A, LOW); digitalWrite(B, HIGH); digitalWrite(C, LOW);
      digitalWrite(D, LOW); digitalWrite(E, HIGH); digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 6:
      digitalWrite(A, LOW); digitalWrite(B, HIGH); digitalWrite(C, LOW);
      digitalWrite(D, LOW); digitalWrite(E, LOW); digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 7:
      digitalWrite(A, LOW); digitalWrite(B, LOW); digitalWrite(C, LOW);
      digitalWrite(D, HIGH); digitalWrite(E, HIGH); digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 8:
      digitalWrite(A, LOW); digitalWrite(B, LOW); digitalWrite(C, LOW);
      digitalWrite(D, LOW); digitalWrite(E, LOW); digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case 9:
      digitalWrite(A, LOW); digitalWrite(B, LOW); digitalWrite(C, LOW);
      digitalWrite(D, LOW); digitalWrite(E, HIGH); digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
  }
}