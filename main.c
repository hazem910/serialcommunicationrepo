
#include "UART_Sender.h"
#include "Spi.h"
#include "softwareDelay.h"
#include "sevenSeg.h"
#include "UART_Receiver.h"
void spi_transimtter (void);
void spi_reciver (void);
int main (void)
{
	
//UART_Sender_func();
//UART_Receiver_func();
//spi_transimtter();
spi_reciver();
}
