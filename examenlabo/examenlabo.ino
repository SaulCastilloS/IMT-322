// Definición de pines para los pulsadores
#define PULSADOR_PLAY 3
#define PULSADOR_ALEATORIO 4
#define PULSADOR_SUBIR 5
#define PULSADOR_BAJAR 6

//Definimos las variables y constantes
int cancion = 0;
int volumen = 5;
bool aleatorio = false;
bool pausa = false;
unsigned long lastButtonPressTime = 0;
const int LONG_PRESS = 3000;
int CONTADOR = 30;

void setup() 
{
  Serial.begin(9600);
  pinMode(PULSADOR_PLAY, INPUT);
  pinMode(PULSADOR_ALEATORIO, INPUT);
  pinMode(PULSADOR_SUBIR, INPUT);
  pinMode(PULSADOR_BAJAR, INPUT);
  attachInterrupt(digitalPinToInterrupt(PULSADOR_SUBIR), subirVolumen, FALLING);
  attachInterrupt(digitalPinToInterrupt(PULSADOR_BAJAR), bajarVolumen, FALLING);
}

void loop() 
{
  // Si no está en pausa, contar tiempo y controlar la canción
  if (!pausa) 
  {
    Serial.print("Temporizador: ");
    Serial.println(CONTADOR);
    delay(1000);
    CONTADOR--;

    // Si el temporizador llega a cero, cambiar de canción y reiniciar temporizador
    if (CONTADOR <= 0) 
    {
      avanzarCancion();
      CONTADOR = 30;
    }
  }

  // Control de la reproducción aleatoria
  if (digitalRead(PULSADOR_ALEATORIO) == LOW) 
  {
    aleatorio = !aleatorio; // Cambiar el estado de reproducción aleatoria
    Serial.println(aleatorio ? "Reproducción aleatoria activada" : "Reproducción aleatoria desactivada");
    delay(500); // Pequeña pausa para evitar múltiples detecciones por un solo clic
  }
}

void subirVolumen() 
{
  if (millis() - lastButtonPressTime > LONG_PRESS) 
  {
    volumen = min(volumen + 1, 10);
    lastButtonPressTime = millis();
    Serial.print("Volumen: ");
    Serial.println(volumen);
  }
}

void bajarVolumen() 
{
  if (millis() - lastButtonPressTime > LONG_PRESS) 
  {
    volumen = max(volumen - 1, 0);
    lastButtonPressTime = millis();
    Serial.print("Volumen: ");
    Serial.println(volumen);
  }
}

void avanzarCancion() 
{
  if (aleatorio) 
  {
    // Cambiar a una canción aleatoria
    cancion = random(0, 3);
    Serial.print("Cambiando a la canción aleatoria: ");
    Serial.println(cancion);
  } 
  else 
  {
    // Cambiar a la siguiente canción en orden
    cancion = (cancion + 1) % 3;
    Serial.print("Cambiando a la siguiente canción: ");
    Serial.println(cancion);
  }
}
