void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

void loop() {
  Serial.println("Elige piedra papel tijeras lagarto spook");
  delay(1000);
  int select = 0;
  int rnd = random(5);
  for(int i = 2; i < 7; i++){
    select = digitalRead(i);
    if (select){
      switch (i){
        case 2:
        switch (rnd){
          case 1: 
            Serial.println("Spokes empatan");
            break;
          case 2: 
            Serial.println("Spoke gana a tijeras");
            break;
          case 3: 
            Serial.println("Spoke pierde contra papel");
            break;
          case 4: 
            Serial.println("Spoke gana a piedra");
            break;
          case 5: 
            Serial.println("Spoke es envenenado por lagarto");
            break;
          default:
            break;
        }
          break;
        case 3: 
        switch (rnd){
          case 1: 
            Serial.println("Tijeras destruidas por spoke");
            break;
          case 2: 
            Serial.println("Empate de tijeras");
            break;
          case 3: 
            Serial.println("Tijeras cortan papel");
            break;
          case 4: 
            Serial.println("Tijeras pierden con piedra");
            break;
          case 5: 
            Serial.println("Tijeras decapitan lagarto");
            break;
          default:
            break;
        }
          break;
        case 4: 
        switch (rnd){
          case 1: 
            Serial.println("Papel gana a spoke");
            break;
          case 2: 
            Serial.println("Papel pierde con tijeras");
            break;
          case 3: 
            Serial.println("Papel envuelve piedra");
            break;
          case 4: 
            Serial.println("Empate de papel");
            break;
          case 5: 
            Serial.println("Lagarto se come papel");
            break;
          default:
            break;
        }
          break;
        case 5: 
        switch (rnd){
          case 1: 
            Serial.println("Spoke pulveriza piedra");
            break;
          case 2: 
            Serial.println("Piedra vence a tijeras");
            break;
          case 3: 
            Serial.println("Papel envuelve piedra");
            break;
          case 4: 
            Serial.println("Empate Piedras");
            break;
          case 5: 
            Serial.println("Piedra aplasta lagarto");
            break;
          default:
            break;
        }
          break;
        case 6: 
        switch (rnd){
          case 1: 
            Serial.println("Lagarto envenena spoke");
            break;
          case 2: 
            Serial.println("Tijeras decapitan lagarto");
            break;
          case 3: 
            Serial.println("lAGARTO SE COME PAPEL");
            break;
          case 4: 
            Serial.println("Piedra aplasta lagarto");
            break;
          case 5: 
            Serial.println("Empate lagartos");
            break;
          default:
            break;
        }
          break;
        default:
          break;
      }
    }
  }
  delay(1000);
}
