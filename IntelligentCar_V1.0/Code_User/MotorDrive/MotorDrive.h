#ifndef __MOTORDRIVE_H
#define __MOTORDRIVE_H


#include "stm32f10x.h"
#include "bit_band.h"


// С����Ϩ��/ɲ���궨��
//-----------------------------------
#define CAR_FLAMEOUT	0	// Ϩ��

#define CAR_BREAK		1	// ɲ��
//-----------------------------------


// ������PA8~PA11��PB6~PB9�ܽŵ����״̬
//-------------------------------------------------------------------------------------

// PA8ģʽ����
//----------------------------------------------------------------------------
// PA8��ͨ���������
#define PA8_Out_PP  { GPIOA->CRH&=0XFFFFFFF0; GPIOA->CRH|=(u32)0x01<<(0*4); }

// PA8�������������
#define PA8_AF_PP   { GPIOA->CRH&=0X0FFFFFF0; GPIOA->CRH|=(u32)0x09<<(0*4); }
//----------------------------------------------------------------------------


// PA9ģʽ����
//----------------------------------------------------------------------------
// PA9��ͨ���������
#define PA9_Out_PP  { GPIOA->CRH&=0XFFFFFF0F; GPIOA->CRH|=(u32)0x03<<(1*4); }

// PA9�������������
#define PA9_AF_PP   { GPIOA->CRH&=0XFFFFFF0F; GPIOA->CRH|=(u32)0x09<<(1*4); }
//----------------------------------------------------------------------------


// PA10ģʽ����
//----------------------------------------------------------------------------
// PA10��ͨ���������
#define PA10_Out_PP { GPIOA->CRH&=0XFFFFF0FF; GPIOA->CRH|=(u32)0x01<<(2*4); }

// PA10�������������
#define PA10_AF_PP  { GPIOA->CRH&=0XFFFFF0FF; GPIOA->CRH|=(u32)0x09<<(2*4); }
//----------------------------------------------------------------------------


// PA11ģʽ����
//----------------------------------------------------------------------------
// PA11��ͨ���������
#define PA11_Out_PP { GPIOA->CRH&=0XFFFF0FFF; GPIOA->CRH|=(u32)0x01<<(3*4); }

// PA11�������������
#define PA11_AF_PP  { GPIOA->CRH&=0XFFFF0FFF; GPIOA->CRH|=(u32)0x09<<(3*4); }
//----------------------------------------------------------------------------



// PB6ģʽ����
//----------------------------------------------------------------------------
// PB6��ͨ���������
#define PB6_Out_PP  { GPIOB->CRL&=0XF0FFFFFF; GPIOB->CRL|=(u32)0x01<<(6*4); }

// PB6�������������
#define PB6_AF_PP   { GPIOB->CRL&=0XF0FFFFFF; GPIOB->CRL|=(u32)0x09<<(6*4); }
//----------------------------------------------------------------------------



// PB7ģʽ����
//----------------------------------------------------------------------------
// PB7��ͨ���������
#define PB7_Out_PP  { GPIOB->CRL&=0X0FFFFFFF; GPIOB->CRL|=(u32)0x01<<(7*4); }

// PB7�������������
#define PB7_AF_PP   { GPIOB->CRL&=0X0FFFFFFF; GPIOB->CRL|=(u32)0x09<<(7*4); }
//----------------------------------------------------------------------------



// PB8ģʽ����
//----------------------------------------------------------------------------
// PB8��ͨ���������
#define PB8_Out_PP  { GPIOB->CRH&=0XFFFFFFF0; GPIOB->CRH|=(u32)0x01<<(0*4); }

// PB8�������������
#define PB8_AF_PP   { GPIOB->CRH&=0XFFFFFFF0; GPIOB->CRH|=(u32)0x09<<(0*4); }
//----------------------------------------------------------------------------


// PB9ģʽ����
//----------------------------------------------------------------------------
// PB9��ͨ���������
#define PB9_Out_PP  { GPIOB->CRH&=0XFFFFFF0F; GPIOB->CRH|=(u32)0x01<<(1*4); }

// PB9�������������
#define PB9_AF_PP   { GPIOB->CRH&=0XFFFFFF0F; GPIOB->CRH|=(u32)0x09<<(1*4); }
//----------------------------------------------------------------------------
//------------------------------------------------------------------------------------



//----------------------------------------------------------------------------
void Motor_LF_forward(u8 speed);		// ��ǰ��=ǰת(�ٶ� = speed%)
void Motor_LF_backward(u8 speed);		// ��ǰ��=��ת(�ٶ� = -speed%)
void Motor_LF_Stop(u8 Wheel_STOP);		// ��ǰ��=ֹͣ(Ϩ��/ɲ��)

void Motor_LB_forward(u8 speed);		// �����=ǰת(�ٶ� = speed%)
void Motor_LB_backward(u8 speed);		// �����=��ת(�ٶ� = -speed%)
void Motor_LB_Stop(u8 Wheel_STOP);		// �����=ֹͣ(Ϩ��/ɲ��)

void Motor_RF_forward(u8 speed);		// ��ǰ��=ǰת(�ٶ� = speed%)
void Motor_RF_backward(u8 speed);		// ��ǰ��=��ת(�ٶ� = -speed%)
void Motor_RF_Stop(u8 Wheel_STOP);		// ��ǰ��=ֹͣ(Ϩ��/ɲ��)

void Motor_RB_forward(u8 speed);		// �Һ���=ǰת(�ٶ� = speed%)
void Motor_RB_backward(u8 speed);		// �Һ���=��ת(�ٶ� = -speed%)
void Motor_RB_Stop(u8 Wheel_STOP);		// ��ǰ��=ֹͣ(Ϩ��/ɲ��)


void Car_Stop(u8 Wheel_STOP);			// С��=ֹͣ(Ϩ��/ɲ��)
void Car_forward(u8 speed);				// С����ǰ(�ٶ� = speed%)
void Car_backward(u8 speed);			// С�����(�ٶ� = -speed%)

void Car_Turn_Left(u8 speed);			// С����ת(�ٶ� = speed%)
void Car_Turn_Right(u8 speed);			// С����ת(�ٶ� = speed%)
//----------------------------------------------------------------------------


#endif /* __MOTORDRIVE_H */