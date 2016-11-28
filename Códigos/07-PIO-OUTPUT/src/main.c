/**************************************************************************
* Rafael Corsi   - Insper 
* rafael.corsi@insper.edu.br        
*
* Computação Embarcada
*
* Trabalhando com o PIO em modo saída
* 07-PIO-SAIDA
************************************************************************/

/** 
 * @Breif Defines
 */
#include "asf.h"
#include "stdio_serial.h"
#include "conf_board.h"
#include "conf_clock.h"

/**
 * @Brief Associação do LED (placa) no uC (chip)
 */
#define LED_PIO_ID		ID_PIOC
#define LED_PIO			PIOC
#define LED_PIN			8
#define LED_PIN_MASK	(1<<LED_PIN) 


/************************************************************************/
/* Main                                                                 */
/************************************************************************/
int main(void)
{
	/************************************************************************/
	/* Inicialização básica do uC                                           */
	/************************************************************************/
	
	/**
	* @Brief Inicializa clock do microcontrolador
	*/
	sysclk_init();

	/**
	* @Brief Desabilita o watchdog
	*/ 
	WDT->WDT_MR = WDT_MR_WDDIS;

	/************************************************************************/
	/* Configuração do PMC	                                                */
	/************************************************************************/
	
	/**
	* @Breif Inicializamos aqui o clock do periférico PIO
	*/ 
	PMC->PMC_PCER0 = (1<<LED_PIO_ID);

	/************************************************************************/
	/* PIO				                                                    */
	/************************************************************************/

	/**
	* @Breif Output Enable Register
	* Configuramos o pino como saida
	*/ 
	PIOC->PIO_OER = (1 << 8);
	
	/**
	* @Brief Peripheral Enable Register
	* Fazemos com que o controle do pino seja realizado pelo PIO
	* e nao por outro periférico
	*/ 
	PIOC->PIO_PER = (1 << 8);

	/**
	* @Brief Clear/Set Output Data Register
	* Aqui controlamos o valor da saida desse pino
	* no caso especifico colocamos 0 (acende o LED)
	* O registrador :
	*   - PIO_SODR : coloca 1 nesse pino
	*	- PIO_CODR : coloca 0 nesse pino
	*/
	PIOC->PIO_CODR =  (1 << 8);
	
	/************************************************************************/
	/* Super loop                                                           */
	/************************************************************************/
	
	/**
	* @Brief Diferente de um codigo comum que executa em um pc, no uC deve estar
	* sempre executando um codigo, por isso utilizamos esse loop infintio.
	*/
	while(1){
		
	};
}


