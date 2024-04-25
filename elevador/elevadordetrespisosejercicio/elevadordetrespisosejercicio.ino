int piso;

typedef enum  {
  PRIMER_PISO,
  SEGUNDO_PISO,
  TERCER_PISO
}
asensor;
asensor edificio= PRIMER_PISO;

void setup() {
  Serial.begin(9600);

}
void loop() {
  switch(edificio){
    case PRIMER_PISO:
      piso = Serial.read();
      if(piso == '2' ){
        edificio= SEGUNDO_PISO;
        Serial.println("Esta subiendo al segundo piso");
        delay(2000);
        Serial.println("piso 2");   
      }
      if(piso == '3'){
        edificio= TERCER_PISO;
         Serial.println("Esta subiendo al tercer piso");
         delay(2000);
        Serial.println("piso 3");   
      }
      break;
    case SEGUNDO_PISO:
    piso = Serial.read();
    if (piso == '3'){
      edificio= TERCER_PISO;
      Serial.println(" Esta subiendo del segundo al tercer piso");
      delay(2000);
      Serial.println("piso 3");
    }
    if (piso == '1'){
      edificio = PRIMER_PISO;
      Serial.println("Esta bajando al primer piso");
      delay(2000);
      Serial.println("piso 1"); 
    }
     break;
    case TERCER_PISO:
    piso = Serial.read();
    if (piso == '2'){
       edificio = SEGUNDO_PISO;
       Serial.println("Esta bajando al segundo piso");
       delay(2000);
       Serial.println("piso 2");  
    }
    if (piso == '1'){
      edificio = PRIMER_PISO;
      Serial.println("Esta bajando al primer piso");
      delay(2000);
      Serial.println("piso 1"); 
    }
     break;
  }
}