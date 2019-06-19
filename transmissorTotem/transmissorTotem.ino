//transmissor

#include <RH_ASK.h> //INCLUSÃO DE BIBLIOTECA
#include <SPI.h> //INCLUSÃO DE BIBLIOTECA

RH_ASK driver; //CRIA O DRIVER PARA COMUNICAÇÃO

const int pinoBotaoVERDE = 2; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON
const int pinoBotaoVERMELHO = 3; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON
const int pinoBotaoAMARELO = 4; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON


void setup(){
	driver.init(); //INICIALIZA A COMUNICAÇÃO RF DO DRIVER
	pinMode(pinoBotaoVERDE, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
	pinMode(pinoBotaoVERMELHO, INPUT_PULLUP);
	pinMode(pinoBotaoAMARELO, INPUT_PULLUP);
	//DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
}
void loop(){
	const char *msgVERMELHO = "ledVERMELHO"; //VARIÁVEL RECEBE O VALOR (led)
const char *msgVERDE = "ledVERDE"; //VARIÁVEL RECEBE O VALOR (led)
const char *msgAMARELO = "ledAMARELO"; //VARIÁVEL RECEBE O VALOR (led)

	if(digitalRead(pinoBotaoVERDE) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    	driver.send((uint8_t *)msgVERDE, strlen(msgVERDE)); //ENVIA AS INFORMAÇÕES PARA O RECEPTOR (PALAVRA: led)
    	driver.waitPacketSent(); //AGUARDA O ENVIO DAS INFORMAÇÕES
    	delay(100); //INTERVALO DE 200 MILISSEGUNDOS
	}
    
 	if(digitalRead(pinoBotaoVERMELHO) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    	driver.send((uint8_t *)msgVERMELHO, strlen(msgVERMELHO)); //ENVIA AS INFORMAÇÕES PARA O RECEPTOR (PALAVRA: led)
    	driver.waitPacketSent(); //AGUARDA O ENVIO DAS INFORMAÇÕES
    	delay(100); //INTERVALO DE 200 MILISSEGUNDOS
	}
 	if(digitalRead(pinoBotaoAMARELO) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    	driver.send((uint8_t *)msgAMARELO, strlen(msgAMARELO)); //ENVIA AS INFORMAÇÕES PARA O RECEPTOR (PALAVRA: led)
    	driver.waitPacketSent(); //AGUARDA O ENVIO DAS INFORMAÇÕES
    	delay(100); //INTERVALO DE 200 MILISSEGUNDOS
	}
}

