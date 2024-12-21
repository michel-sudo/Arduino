byte zero[7] = {1,1,1,1,1,1,0};
byte um[7] = {0,1,1,0,0,0,0};
byte dois[7] = {1,1,0,1,1,0,1};
byte tres[7] = {1,1,1,1,0,0,1};
byte quatro[7] = {0,1,1,0,0,1,1};
byte cinco[7] = {1,0,1,1,0,1,1};
byte seis[7] = {1,0,1,1,1,1,1};
byte sete[7] = {1,1,1,0,0,0,0};
byte oito[7] = {1,1,1,1,1,1,1};
byte nove[7] = {1,1,1,0,0,1,1};
int ultLeitura = 0;
int contador = 0;
int leitura = 0;

void setup()
{
  for(int i = 7; i<14; i++){
  	pinMode(i, OUTPUT);
  }
  pinMode(6, INPUT);
}

void loop()
{
  leitura = digitalRead(6);
  if(ultLeitura != leitura) {
    if(leitura == HIGH) {
      contador += 1;
      if(contador > 9){
        contador = 0;
      }
    }
  }
  switch (contador) {
        case 0:
          acendeNumero(zero);
          break;
        case 1:
          acendeNumero(um);
          break;
        case 2:
          acendeNumero(dois);
          break;
        case 3:
          acendeNumero(tres);
          break;
        case 4:
          acendeNumero(quatro);
          break;
        case 5:
          acendeNumero(cinco);
          break;
        case 6:
          acendeNumero(seis);
          break;
        case 7:
          acendeNumero(sete);
          break;
        case 8:
          acendeNumero(oito);
          break;
        case 9:
          acendeNumero(nove);
          break;
      }
      ultLeitura = leitura;
      delay(100);
}

void acendeNumero(byte numero[7]) {
  int porta = 7;
  for(int j = 0; j < 8; j++){
        digitalWrite(porta, !numero[j]);
        porta++;
      }
}