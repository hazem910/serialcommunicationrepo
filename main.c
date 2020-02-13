
#include "UART_Sender.h"
#include "Spi.h"
#include "softwareDelay.h"
#include "sevenSeg.h"
#include "UART_Receiver.h"
#include "UART_SPI_ApplicationMicro1.h"
#include "UART_SPI_ApplicationMicro2.h"
void spi_transimtter (void);
void spi_reciver (void);
#define  F_CPU 16000000UL
int main (void)
{  Micro_TwoApplication();
	//Micro_OneApplication();
	

	
//UART_Sender_func();
//UART_Receiver_func();
//spi_transimtter();
//spi_reciver();



}
