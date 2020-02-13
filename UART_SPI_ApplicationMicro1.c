/*
 ============================================================================
 Name        : UART_SPI_Application.c
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */


#include "UART_SPI_ApplicationMicro1.h"
volatile uint8_t speed=0;
void Micro_OneApplication(void)
{
	

	

	UART_Config_Structure uart_initialization_structure;
	uart_initialization_structure.Char_Size=USART_8_Bit_CHAR;
	uart_initialization_structure.Clk_Polarity_Mode=TX_RISING_RX_FALLING;
	uart_initialization_structure.Speed_Mode=USART_DOUBLE_SPEED;
	uart_initialization_structure.Parity_Mode=USART_NO_PARITY;
	uart_initialization_structure.Stop_Bit_Mode=USART_1_STOPBIT;
	uart_initialization_structure.Receive_Mode=USART_RECIEVE_ENABLE;
	uart_initialization_structure.Transmit_Mode=USART_TRANSMIT_ENABLE;
	uart_initialization_structure.Double_Speed_Baud_Rate=BAUD9600;
	UART_init(&uart_initialization_structure);

	ST_S_SPI_Configuration spistr1=
	{
		 spistr1.SLAVE_MODE=SPI_MASTER,
		 spistr1.INT_ENABLE=SPI_INT_OFF,
		 spistr1.PRESCALAR=SPI_Fosc16,
		 spistr1.DOUBLE_SPEED=SPI_DOUBLE_SPEED_MODE_OFF,
		 spistr1.ENABLE=SPI_ENABLE_ON,
		 spistr1.SAMPLING_EDGE=SPI_RISING,
		 spistr1.DATA_ORDER=SPI_LSB_FISRT,
		 spistr1.clock_phase=leading_EDGE
	 };
	SPI_Init(&spistr1);

	pushButtonInit(BTN_0);
	pushButtonInit(BTN_1);
	UART_init(&uart_initialization_structure);
	gpioPinDirection(GPIOB,BIT3,OUTPUT);
	INT2_Init(RISIGING_EDGE);
	speed=UART_recieveByte();
	while(1)
	{

		if(pushButtonGetStatus(BTN_0))
		{
			speed--;
			gpioPinWrite(GPIOB,BIT3,BIT3);
		}
	/*	if(pushButtonGetStatus(BTN_1))
		{
			speed--;
			gpioPinWrite(GPIOB,BIT3,LOW);
			
		}*/
		SPI_Transceiver(speed);
		softwareDelayMs(1000);
	}
}
ISR(INT2_vect){
	speed--;
}