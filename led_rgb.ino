const int BUZZER = 10;
const int IR = 2;
const int LED_ROUGE = 3; // Broche PWM !!!
const int LED_BLEU = 6; // Broche PWM !!!
const int LED_VERT = 5; // Broche PWM !!!
const int DELAI = 500;

bool modeAuto = false; 

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_BLEU, OUTPUT);
  pinMode(LED_VERT, OUTPUT);

  Serial.begin(9600);
  Serial.println("Entrez une couleur (R G B) ex: 255 0 128");
  Serial.println("Tapez 'auto' pour activer le mode détection IR");
  Serial.println("Tapez 'stop' pour revenir au mode manuel");
}

void loop() {
  // -- Si des données arrivent du moniteur série --
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.equalsIgnoreCase("auto")) {
      modeAuto = true;
      Serial.println("Mode AUTO activé !");
    } 
    else if (input.equalsIgnoreCase("stop")) {
      modeAuto = false;
      setColor(0, 0, 0); // éteindre les LEDs
      Serial.println("Mode manuel activé");
    }
    else if (!modeAuto) {  // Seulement en mode manuel
      int r, g, b;
      int count = sscanf(input.c_str(), "%d %d %d", &r, &g, &b);
      if (count == 3) {
        Serial.print("→ Couleur définie : ");
        Serial.print(r); Serial.print(" ");
        Serial.print(g); Serial.print(" ");
        Serial.println(b);
        setColor(r, g, b);
      } else {
        Serial.println("Format invalide. Entrez R G B (ex: 255 0 128)");
      }
    }
  }

  // -- Si on est en mode auto, on lit le capteur en continu --
  if (modeAuto) {
    int val = digitalRead(IR);
    if (val == 0) {
      Serial.println("Obstacle détecté !");
      tone(BUZZER, 440, 500);
      setRed();
      setGreen();
      setBlue();
      setPurple();
    } else {
      setColor(0, 0, 0);
      Serial.println("RAS...");
    }
    delay(100);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(LED_ROUGE, red);
  analogWrite(LED_VERT, green);
  analogWrite(LED_BLEU, blue);
}

void setRed()    { setColor(255, 0, 0); delay(DELAI); }
void setGreen()  { setColor(0, 255, 0); delay(DELAI); }
void setBlue()   { setColor(0, 0, 255); delay(DELAI); }
void setPurple() { setColor(247, 79, 255); delay(DELAI); }
