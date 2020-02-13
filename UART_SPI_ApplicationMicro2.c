/*
 ============================================================================
 Name        : UART_SPI_ApplicationMicro2.c
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */


#include "UART_SPI_ApplicationMicro2.h"

void Micro_TwoApplication(void)
{
	
	sei();
	uint8_t speed=0;
	uint8_t distance=0;
	//uint8_t total_distance;
	//uint8_t timer_tickes=0;
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
		 spistr1.SLAVE_MODE=SPI_SLAVE,
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
	while(1)
	{			

		if(timer0_compare_match_tickes%4==0)
		{
			speed=SPI_Transceiver(0);
			//speed-=48;
			//distance+=speed;
		}
		if(pushButtonGetStatus(BTN_0))
		{
			timer0Init(T0_COMP_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,250,T0_INTERRUPT_CMP);
			distance=0;
		}
	
		if(pushButtonGetStatus(BTN_1))
		{
			//timer_tickes=timer0Read();
			timer0Stop();
			distance+=48;
			UART_sendByte(speed);
						distance=0;

		}

		

	}
}

/*
static uint8_t calculate_speed(uint8_t speed)
{
	uint8_t distance;
	distance=(timer0_compare_match_tickes/4)*speed;
	return distance;
}
*/
