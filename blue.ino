/*PRJETO 3 - CONTROLE DE VELOCIDADE - RODRIGO & GUSTAVO. 

 */
int roteador = 2;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
  pinMode(roteador, OUTPUT); //saida para PWM do motor

  Serial.begin(9600); //comunicacao serial  
  digitalWrite(roteador, HIGH);
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void loop(){
 char leitura_celular;
 

 if(Serial.available() > 0){ 
   leitura_celular = Serial.read();
   Serial.print(leitura_celular);
 }

 if(leitura_celular == 'l')
   digitalWrite(roteador, HIGH);

 if(leitura_celular == 'd')
   digitalWrite(roteador, LOW);    
}
