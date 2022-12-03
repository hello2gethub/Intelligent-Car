#include "delay.h"

static u16 SysTick_each_us_CNT ;	// SysTick��ʱ1us����ļ�������
static u16 SysTick_each_ms_CNT ;	// SysTick��ʱ1ms����ļ�������

// ��ʼ��SysTick��ʱ��
void delay_Init(void)
{
	// RCCͨ��AHBʱ��(HCLK)8��Ƶ����ΪCortexϵͳ��ʱ��(SysTick)�Ŀ�ѡ�ⲿʱ��
	// Ĭ�ϣ�SystemCoreClock = SYSCLK_FREQ_72MHz ;
	//**********************************************************************************************************
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	// SysTick��ʱ��ѡΪ�ⲿʱ�ӵ�8��Ƶ��HCLK/8��
	
	SysTick_each_us_CNT = SystemCoreClock / 8 / 1000000;	// �õ�1us�ļ�������

	SysTick_each_ms_CNT = SysTick_each_us_CNT * 1000;		// �õ�1ms�ļ�������

}


// ��ʱdelay_us_Num΢��	
// ����delay_us_Num��ֵӦ < 1,864,135(ʮ����)
//*********************************************
u8 delay_us(u32 delay_us_Num)
{		
	u8  NOP_CNT = 4 ;
	
	u32 T_SysTick_CTR ;
	
	
	// ���û�д��жϣ�������Ϊ0ʱ����������ѭ��
	//********************************************
	if( delay_us_Num == 0 )		// ����������Ϊ0
	{ return 0 ; }				// ��������
	
	
	// ��������1usʱ����ʹ��SysTick��ʱ����ֱ��ʹ�ü���NOPʵ��1us��ʱ
	//****************************************************************
	if( delay_us_Num == 1 )
	{
		while( --NOP_CNT )		// NOP_CNT = 4 ;
		{
			__NOP();			// NOP��һ��ָ�����ڵĿղ���
		}

		return 0 ;				// ��������
	}
	
	
	// SysTick��ʱ��������ʱǰ��������ʱ1us���ң��ڴ˸�����SysTick������
	//*****************************************************************
	if( delay_us_Num>1 && delay_us_Num<1000 )
	{ delay_us_Num -- ; }
	
	
	// SysTick->LOAD��SysTick��װ�ؼĴ���(SysTick->LOADΪ24λ������)
	// ���������ݼ���0ʱ����ǿ����0ʱ������SysTick->LOAD�е�ֵ�������������
	//**********************************************************************************************************
	SysTick->LOAD = (u32)SysTick_each_us_CNT * delay_us_Num ;			// ���˴κ����ļ�������д����װ�ؼĴ�����
	
	
	// SysTick->VAL��SysTick�ĵݼ�������
	// ��SysTick->VAL��д�����ݣ���ͻᱻ��0��
	// ����ݼ���0ʱ��COUNTFLAGλ��1��
	//**********************************************************************************************************
	SysTick->VAL = 0x00; 						// ��SysTick->VAL��0���Ӷ�ʹ��SysTick->LOAD�е�ֵװ��SysTick->VAL
		

	// SysTick->CTRL�����λΪSysTick��ʱ����ʹ��λ��1ʹ�� 0ʧ��
	//*****************************************************************************************
	SysTick->CTRL |= (u32)0x01 ;				// ʹ��SysTick��ʱ������������ʼ�ݼ�

	
	// һֱ�ȴ��������ݼ���0
	//**********************************************************************************************************************
	do{
		T_SysTick_CTR = SysTick->CTRL ;			// ��SysTick->CTRL�е�ֵ���浽T_SysTick_CTR������
		
	}while( (T_SysTick_CTR & 0x01) && !(T_SysTick_CTR & (1<<16) ) );	// ��SysTick->CTRL�����λΪ1���ҵ�16λΪ0ʱ������ѭ��
	
	
	SysTick->CTRL &= ~ ( (u32)0x01 ) ;			// ʧ��SysTick��ʱ��

	SysTick->VAL = 0X00;      					// ��0������
	
	return 0 ;	// ��������
}



// ��ʱdelay_ms_Num����
// ����delay_ms_Num��ֵӦ < 1,864(ʮ����)
//****************************************
u8 delay_ms(u16 delay_ms_Num)
{	 		  	  
	u32 T_SysTick_CTR ;
	
	// ���û�д��жϣ�������Ϊ0ʱ����������ѭ��
	//********************************************
	if( delay_ms_Num == 0 )		// ����������Ϊ0
	{ return 0 ; }				// ��������

	// SysTick->LOAD��SysTick��װ�ؼĴ���(SysTick->LOADΪ24λ������)
	// ���������ݼ���0ʱ����ǿ����0ʱ������SysTick->LOAD�е�ֵ�������������
	//**********************************************************************************************************
	SysTick->LOAD = (u32)SysTick_each_ms_CNT * delay_ms_Num ;			// ���˴κ����ļ�������д����װ�ؼĴ�����
	
	
	// SysTick->VAL��SysTick�ĵݼ�������
	// ��SysTick->VAL��д�����ݣ���ͻᱻ��0��
	// ����ݼ���0ʱ��COUNTFLAGλ��1��
	//**********************************************************************************************************
	SysTick->VAL = 0x00; 						// ��SysTick->VAL��0���Ӷ�ʹ��SysTick->LOAD�е�ֵװ��SysTick->VAL
	
	
	// SysTick->CTRL�����λΪSysTick��ʱ����ʹ��λ��1ʹ�� 0ʧ��
	//*****************************************************************************************
	SysTick->CTRL |= (u32)0x01 ;				// ʹ��SysTick��ʱ������������ʼ�ݼ�

		
	// һֱ�ȴ��������ݼ���0
	//**********************************************************************************************************************
	do{
		T_SysTick_CTR = SysTick->CTRL ;			// ��SysTick->CTRL�е�ֵ���浽T_SysTick_CTR������
		
	}while( (T_SysTick_CTR & 0x01) && !(T_SysTick_CTR & (1<<16) ) );	// ��SysTick->CTRL�����λΪ1���ҵ�16λΪ0ʱ������ѭ��
	
	
	SysTick->CTRL &= ~ ( (u32)0x01 ) ;			// ʧ��SysTick��ʱ��
	
	SysTick->VAL = 0X00;      					// ��ռ�����
	
	return 0 ;	// ��������
}