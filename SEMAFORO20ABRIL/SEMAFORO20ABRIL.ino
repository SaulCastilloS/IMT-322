#define     ROJO         2
#define     AMARILLO     3
#define     VERDE        4
#define     TIME         2000
typedef enum{
  SROJO,
  SAMARILLO,
  SVERDE
  } 
semaforo;
semaforo estados=SROJO;
int estado =0;
void setup() {
  pinMode (ROJO,OUTPUT);
  pinMode (AMARILLO,OUTPUT);
  pinMode (VERDE,OUTPUT);
}

void loop() {
  switch(estado){
    case 0:
      digitalWrite(ROJO,HIGH); 
      digitalWrite(AMARILLO,LOW);
      digitalWrite(VERDE,LOW);
      delay(TIME);
      estado =1;
      break;
       
    case 1:
      digitalWrite(ROJO,LOW); 
      digitalWrite(AMARILLO,HIGH);
      digitalWrite(VERDE,LOW);
      delay(TIME);
      estado =2;
      break;
    case 2: 
      digitalWrite(ROJO,LOW); 
      digitalWrite(AMARILLO,LOW);
      digitalWrite(VERDE,HIGH);
      delay(TIME);
      estado =0;
      break;

  
  }

}
