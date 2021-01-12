#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_SysTick.h"

int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	
	SysTick_Init();
	
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USARTx,"AT+EMQNEW='47.104.162.101','1883',12000,100\n");
	SysTick_Delay_Ms(1000);
	Usart_SendString( DEBUG_USARTx,"AT+EMQCON=0,3,'9512c9c9403340e9bd49a0523775f021',1000,1,0\n");
	SysTick_Delay_Ms(1000);
	Usart_SendString( DEBUG_USARTx,"AT+EMQSUB=0,'mytopic',1\n");
	SysTick_Delay_Ms(1000);
	Usart_SendString( DEBUG_USARTx,"AT+EMQPUB=0,'mytopic',1,0,0,4,'31323334'\n");
	
  while(1)
	{	
		
	}	
}
