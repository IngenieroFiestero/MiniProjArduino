int lengthArray = 10;
int secuencia[10];
int recorrer = 0;
int maxr = 1;
boolean mostrar = true;
int melody[] = {39, 35, 33, 31};
int noteDurations[] = {8, 8, 8, 4};
  int victoria[] = {33, 37, 39, 41,39,41};
  int duracion[] = {8, 8, 8, 4,8,4};

void setup() {
  randomSeed(analogRead(0));
  for(int i=0; i < lengthArray; i++){
    secuencia[i]= 2 + random(4);
  }
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10,OUTPUT);
  
}
int getSecuencia(){
  int devolver = secuencia[recorrer];
  recorrer++;
  if(recorrer >= maxr){
    maxr++;
    recorrer = 0;
    mostrar = true;
  }
  if(maxr >= lengthArray){
    winer();
  }
  return devolver;
}
void loop() {
  if(mostrar){
    mostrar = false;
    for(int i = 0; i < maxr; i++){
      digitalWrite(secuencia[i],HIGH);
      delay(300);
      digitalWrite(secuencia[i],LOW);
      delay(200);
    }
  }
  int s = getSecuencia();
  boolean pinEntrada;
  boolean noSalir = true;
  while(noSalir){
    for(int i=0; i < 4; i++){
      if(digitalRead(i+6)){
        if(i+6==s+4){
          pinEntrada = true;
          noSalir = false;
        }else{
          pinEntrada = false;
          noSalir = false;
        }
      }
    }
  }
  if(pinEntrada){
    tone(10, 33,1000/8);
    delay(150);
    noTone(10);
    digitalWrite(s,HIGH);
    delay(300);
    digitalWrite(s,LOW);
  }else{
    lose();
  }
}
void lose(){
  for(int i = 0; i < 4; i++){
    int noteDuration = 1000/noteDurations[i];
    tone(10, melody[i],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(10);
  }
  nuevoValor();
}
void nuevoValor(){
  randomSeed(analogRead(0));
  for(int i=0; i < lengthArray; i++){
    secuencia[i]= 2 + random(4);
  }
  recorrer=0;
  maxr = 1;
  mostrar = true;
}
void winer(){
  for(int i = 0; i < 6; i++){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    int noteDuration = 1000/duracion[i];
    tone(10, victoria[i],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    noTone(10);
  }
  nuevoValor();
}
