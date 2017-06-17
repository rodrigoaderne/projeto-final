/*PRJETO 3 - CONTROLE DE VELOCIDADE - RODRIGO & GUSTAVO. 
* Através de comunicação serial via bluetooth, o arduino recebe caracteres para desligar ou ligar um rele, que ira ligar ou desligar
o roteador.
 */
int rele = 2;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
  pinMode(roteador, OUTPUT); //saida para acionar rele

  Serial.begin(9600); //comunicacao serial  
  digitalWrite(rele, HIGH); // rele inicia ligado, roteador ligado
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop(){
 char leitura_celular;
//recebe caracteres pelo RX, vindo da interface bluetooth.
 if(Serial.available() > 0){ 
   leitura_celular = Serial.read(); //recebe caracteres pelo RX, enviado via bluetooth do App pelo celular
  // Serial.print(leitura_celular);
 }
//caso no App o usuario solicite reiniciar o roteador, o App envia para o RX do arduino o caracter 'd', após 10s o App envia o 
//o caracter 'l' para religar o roteador.
  
 if(leitura_celular == 'l') // se recebeu caracter 'l' do App
   digitalWrite(rele, HIGH); //aciona rele para ligar roteador

 if(leitura_celular == 'd') // se recebeu caracter 'l' do App
   digitalWrite(rele, LOW); //desliga o roteador   
}
