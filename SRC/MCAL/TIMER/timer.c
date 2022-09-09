/*******************************************************************************
 *
 * Module: Timer's Modules
 *
 * File Name: timer.c
 *
 * Description: Source File For AVR_Timer Module
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "../../utils/common_macros.h"

/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/
/*
 * [Description]: This Pointer To Function Save the Address Of The function
 *                That will call when Event occur .
 *
 *                AND Every Timer have Pointer To Function .
 */
static volatile void(*g_Ptr_To_Fun_0)(void)= NULL_PTR;
static volatile void(*g_Ptr_To_Fun_1)(void)= NULL_PTR;
static volatile void(*g_Ptr_To_Fun_2)(void)= NULL_PTR;


/*******************************************************************************
 *                                 TIMER0_ISR
 *******************************************************************************/

/*
 * [Description]: Here The ISR's specific For TIMER0
 */

ISR(TIMER0_OVF_vect){
	 /* Call the Call Back function in the application after the Event is Occur */

	if(g_Ptr_To_Fun_0 != NULL_PTR){
		/* This is called --> Call Back Notification */
		/* another method to call the function using pointer to function g_Ptr_To_Fun_0(); */
		(g_Ptr_To_Fun_0)();
	}
}

ISR(TIMER0_COMP_vect){
	if(g_Ptr_To_Fun_0 != NULL_PTR){
		(g_Ptr_To_Fun_0)();
	}
}
/*******************************************************************************
 *                                 TIMER2_ISR
 *******************************************************************************/
ISR(TIMER2_OVF_vect){
	if(g_Ptr_To_Fun_2 != NULL_PTR){
		(g_Ptr_To_Fun_2)();
	}
}

ISR(TIMER2_COMP_vect){
	if(g_Ptr_To_Fun_2 != NULL_PTR){
		(g_Ptr_To_Fun_2)();
	}
}
/*******************************************************************************
 *                                 TIMER1_ISR
 *******************************************************************************/
ISR(TIMER1_OVF_vect){
	if(g_Ptr_To_Fun_1 != NULL_PTR){
		(g_Ptr_To_Fun_1)();
	}
}

ISR(TIMER1_COMPA_vect){
	if(g_Ptr_To_Fun_1 != NULL_PTR){
		(g_Ptr_To_Fun_1)();
	}
}

ISR(TIMER1_COMPB_vect){
	if(g_Ptr_To_Fun_1 != NULL_PTR){
		(g_Ptr_To_Fun_1)();
	}
}

/*******************************************************************************
 *                                    MASK's
 *******************************************************************************/


/*------------------------------------------------------------------------------
 *                            [Masks For Timer's Mode]
 * -----------------------------------------------------------------------------*/


/* TIMER0 Mode's */
#define TIMER0_Mode_Clr_msk                           0xB7
#define TIMER0_Mode_Ovf_msk                           0x00  /* Normal Mode */
#define TIMER0_Mode_Pwm_PhaseCorrect_msk              0x40
#define TIMER0_Mode_Ctc_msk                           0x08
#define TIMER0_Mode_FastPwm_msk                       0x48

/* TIMER2 Mode's */
#define TIMER2_Mode_Clr_msk                           0xB7
#define TIMER2_Mode_Ovf_msk                           0x00  /* Normal Mode */
#define TIMER2_Mode_Pwm_PhaseCorrect_msk              0x40
#define TIMER2_Mode_Ctc_msk                           0x08
#define TIMER2_Mode_FastPwm_msk                       0x48

/* TIMER1 Mode's */
#define TIMER1_Mode_Clr_msk                           0xF0
#define TIMER1_Mode_Ovf_msk                           0x00  /* Normal Mode */
#define TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk        0x01
#define TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk        0x02
#define TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk       0x03
#define TIMER1_Mode_Ctc_msk                           0x04
#define TIMER1_Mode_FastPwm_8_bit_msk                 0x05
#define TIMER1_Mode_FastPwm_9_bit_msk                 0x06
#define TIMER1_Mode_FastPwm_10_bit_msk                0x07
#define TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk   0x09
#define TIMER1_Mode_Pwm_Phase_Correct_msk             0x0B
#define TIMER1_Mode_Fast_Pwm_msk                      0x0F



/*
 * Timer's Clock Select
 */

/* TIMER0 Clock and PreScaler */
#define TIMER0_Clk_With_PreScaler_Clr_msk              0xF8
#define TIMER0_Clk_With_No_PreScaler_msk               0x01
#define TIMER0_Clk_With_8_PreScaler_msk                0x02
#define TIMER0_Clk_With_64_PreScaler_msk               0x03
#define TIMER0_Clk_With_256_PreScaler_msk              0x04
#define TIMER0_Clk_With_1024_PreScaler_msk             0x05

#define TIMER0_External_Clk_With_Falling_Edge_msk      0x06
#define TIMER0_External_Clk_With_Rising_Edge_msk       0x07


/* TIMER2 Clock and PreScaler */
#define TIMER2_Clk_With_PreScaler_Clr_msk              0xF8
#define TIMER2_Clk_With_No_PreScaler_msk               0x01
#define TIMER2_Clk_With_8_PreScaler_msk                0x02
#define TIMER2_Clk_With_32_PreScaler_msk               0x03
#define TIMER2_Clk_With_64_PreScaler_msk               0x04
#define TIMER2_Clk_With_128_PreScaler_msk              0x05
#define TIMER2_Clk_With_256_PreScaler_msk              0x06
#define TIMER2_Clk_With_1024_PreScaler_msk             0x07


/* TIMER1 Clock and PreScaler */
#define TIMER1_Clk_With_PreScaler_Clr_msk              0xF8
#define TIMER1_Clk_With_No_PreScaler_msk               0x01
#define TIMER1_Clk_With_8_PreScaler_msk                0x02
#define TIMER1_Clk_With_64_PreScaler_msk               0x03
#define TIMER1_Clk_With_256_PreScaler_msk              0x04
#define TIMER1_Clk_With_1024_PreScaler_msk             0x05

#define TIMER1_External_Clk_With_Falling_Edge_msk      0x06
#define TIMER1_External_Clk_With_Rising_Edge_msk       0x07


/*******************************************************************************
 *                            FUNCTION's Initialization
 *******************************************************************************/
#define TIMER0_OC0_clr_msk                           0xCF
#define TIMER0_OC0_TOGGLE_msk                        0x01
#define TIMER0_OC0_CLR_msk                           0x02
#define TIMER0_OC0_SET_msk                           0x03
#define TIMER0_OC0_NON_INVERTING_msk                 0x04
#define TIMER0_OC0_INVERTING_msk                     0x05

#define TIMER2_OC2_clr_msk                           0xCF
#define TIMER2_OC2_TOGGLE_msk                        0x01
#define TIMER2_OC2_CLR_msk                           0x02
#define TIMER2_OC2_SET_msk                           0x03
#define TIMER2_OC2_NON_INVERTING_msk                 0x04
#define TIMER2_OC2_INVERTING_msk                     0x05

#define TIMER1_OC1A_clr_msk                          0x3F
#define TIMER1_OC1B_clr_msk                          0xCF
#define TIMER1_OC1_TOGGLE_msk                        0x01
#define TIMER1_OC1_CLR_msk                           0x02
#define TIMER1_OC1_SET_msk                           0x03
#define TIMER1_OC1_NON_INVERTING_msk                 0x04
#define TIMER1_OC1_INVERTING_msk                     0x05

#define TIMER1_OC1_SPECIAL_TOGGLE_FastPWM_msk        0x06
#define TIMER1_OC1_SPECIAL_TOGGLE_Phase_Correct_msk  0x07



void TIMER_Init(void){


#if TIMER0_Enable == ENABLE
#if (TIMER0_Mode_Selector == TIMER0_Mode_Pwm_PhaseCorrect_msk )
	CLEAR_BIT(TCCR0,TIMER0_Mode_Clr_msk);
	SET_BIT(TCCR0,WGM00);
#elif	(TIMER0_Mode_Selector == TIMER0_Mode_FastPwm_msk )
	CLEAR_BIT(TCCR0,TIMER0_Mode_Clr_msk);
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#endif

#if	(TIMER0_Mode_Selector == TIMER0_Mode_Pwm_PhaseCorrect_msk)  || (TIMER0_Mode_Selector == TIMER0_Mode_FastPwm_msk)
#if TIMER0_OC0_Behavior_Selector == TIMER0_OC0_NON_INVERTING_msk
	SET_BIT(DDRB,PB3);
	CLEAR_BIT(TCCR0,TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM01);
#elif TIMER0_OC0_Behavior_Selector == TIMER0_OC0_INVERTING_msk
	SET_BIT(DDRB,PB3);
	CLEAR_BIT(TCCR0,TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif
#endif

#if (TIMER0_Mode_Selector != TIMER0_Mode_Pwm_PhaseCorrect_msk)  && (TIMER0_Mode_Selector != TIMER0_Mode_FastPwm_msk)
	SET_BIT(TCCR0,FOC0);

#if TIMER0_Mode_Selector == TIMER0_Mode_Ctc_msk
	CLEAR_BIT(TCCR0,TIMER0_Mode_Clr_msk);
	SET_BIT(TCCR0,WGM01);
#endif

#if TIMER0_OC0_Behavior_Selector == TIMER0_OC0_TOGGLE_msk
	SET_BIT(DDRB,PB3);
	CLEAR_BIT(TCCR0,TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM00);
#elif TIMER0_OC0_Behavior_Selector == TIMER0_OC0_CLR_msk
	SET_BIT(DDRB,PB3);
	CLEAR_BIT(TCCR0,TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM01);
#elif TIMER0_OC0_Behavior_Selector == TIMER0_OC0_SET_msk
	SET_BIT(DDRB,PB3);
	CLEAR_BIT(TCCR0,TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif
#endif

	switch(TIMER0_PreScaler_Selector){
	case TIMER0_Clk_With_No_PreScaler_msk:
		CLEAR_BIT(TCCR0,TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		break;
	case TIMER0_Clk_With_8_PreScaler_msk:
		CLEAR_BIT(TCCR0,TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS01);
		break;
	case TIMER0_Clk_With_64_PreScaler_msk:
		CLEAR_BIT(TCCR0,TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		break;
	case TIMER0_Clk_With_256_PreScaler_msk:
		CLEAR_BIT(TCCR0,TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_Clk_With_1024_PreScaler_msk:
		CLEAR_BIT(TCCR0,TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_External_Clk_With_Falling_Edge_msk:
		CLEAR_BIT(TCCR0,TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_External_Clk_With_Rising_Edge_msk:
		CLEAR_BIT(TCCR0,TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}


	/* Initial value for Timer/Counter0 */
	TCNT0 = TIMER0_Initial_Value;

	/* Compare value for Timer/Counter0 */
	OCR0 = TIMER0_Compare_Value;
#endif


#if TIMER2_Enable == ENABLE
#if (TIMER2_Mode_Selector == TIMER2_Mode_Pwm_PhaseCorrect_msk )
	CLEAR_BIT(TCCR2,TIMER2_Mode_Clr_msk);
	SET_BIT(TCCR2,WGM20);/*DONE*/
#elif	(TIMER2_Mode_Selector == TIMER2_Mode_FastPwm_msk )
	CLEAR_BIT(TCCR2,TIMER2_Mode_Clr_msk);
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);/*DONE*/
#endif

#if (TIMER2_Mode_Selector == TIMER2_Mode_Pwm_PhaseCorrect_msk)  || (TIMER2_Mode_Selector == TIMER2_Mode_FastPwm_msk)
#if TIMER2_OC2_Behavior_Selector == TIMER2_OC2_NON_INVERTING_msk
	CLEAR_BIT(TCCR2,TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM21);/*DONE*/
#elif TIMER2_OC2_Behavior_Selector == TIMER2_OC2_INVERTING_msk
	CLEAR_BIT(TCCR2,TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);/*DONE*/
#endif
#endif

#if (TIMER2_Mode_Selector != TIMER2_Mode_Pwm_PhaseCorrect_msk)  && (TIMER2_Mode_Selector != TIMER2_Mode_FastPwm_msk)
	SET_BIT(TCCR2,FOC2); /*DONE*/

#if TIMER2_Mode_Selector == TIMER2_Mode_Ctc_msk
	CLEAR_BIT(TCCR2,TIMER2_Mode_Clr_msk);
	SET_BIT(TCCR2,WGM21);/*DONE*/
#endif

#if TIMER2_OC2_Behavior_Selector == TIMER2_OC2_TOGGLE_msk
	CLEAR_BIT(TCCR2,TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM20);/*DONE*/
#elif TIMER2_OC2_Behavior_Selector == TIMER2_OC2_CLR_msk
	CLEAR_BIT(TCCR2,TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM21);/*DONE*/
#elif TIMER2_OC2_Behavior_Selector == TIMER2_OC2_SET_msk
	CLEAR_BIT(TCCR2,TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM20);/*DONE*/
	SET_BIT(TCCR2,COM21);
#endif
#endif

	switch(TIMER2_PreScaler_Selector){
	case TIMER2_Clk_With_No_PreScaler_msk:
		CLEAR_BIT(TCCR2,TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,TIMER2_Clk_With_No_PreScaler_msk);
		break;
	case TIMER2_Clk_With_8_PreScaler_msk:
		CLEAR_BIT(TCCR2,TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,TIMER2_Clk_With_8_PreScaler_msk);
		break;
	case TIMER2_Clk_With_32_PreScaler_msk:
		CLEAR_BIT(TCCR2,TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,TIMER2_Clk_With_32_PreScaler_msk);
		/*SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);*/
	break;
	case TIMER2_Clk_With_64_PreScaler_msk:
		CLEAR_BIT(TCCR2,TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,TIMER2_Clk_With_64_PreScaler_msk);
		/*SET_BIT(TCCR2,CS22);*/
		break;
	case TIMER2_Clk_With_128_PreScaler_msk:
		CLEAR_BIT(TCCR2,TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,TIMER2_Clk_With_128_PreScaler_msk);
		/*SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS22);*/
		break;
	case TIMER2_Clk_With_256_PreScaler_msk:
		CLEAR_BIT(TCCR2,TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,TIMER2_Clk_With_256_PreScaler_msk);
		/*SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);*/
		break;
	case TIMER2_Clk_With_1024_PreScaler_msk:
		CLEAR_BIT(TCCR2,TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,TIMER2_Clk_With_1024_PreScaler_msk);
		/*SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);*/
		break;
	}


	/* Initial value for Timer/Counter0 */
	TCNT2 = TIMER2_Initial_Value;

	/* Compare value for Timer/Counter0 */
	OCR2 = TIMER2_Compare_Value;
#endif







#if TIMER1_Enable == ENABLE

	switch(TIMER1_Mode_Selector){
	case TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk);
		break;
	case TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk);
		break;
	case TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk);
		break;
	case TIMER1_Mode_Ctc_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_Ctc_msk);
		break;
	case TIMER1_Mode_FastPwm_8_bit_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_FastPwm_8_bit_msk);
		break;
	case TIMER1_Mode_FastPwm_9_bit_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_FastPwm_9_bit_msk);
		break;
	case TIMER1_Mode_FastPwm_10_bit_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_FastPwm_10_bit_msk);
		break;
	case TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk);
		break;
	case TIMER1_Mode_Pwm_Phase_Correct_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_Pwm_Phase_Correct_msk);
		break;
	case TIMER1_Mode_Fast_Pwm_msk:
		CLEAR_BIT(TCCR1A,TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,TIMER1_Mode_Fast_Pwm_msk);
		break;
	}


#if TIMER1_Mode_Selector == TIMER1_Mode_Ctc_msk
	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);
#if TIMER1_OC1A_Select == ENABLE
	SET_BIT(DDRD,PD5);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_TOGGLE_msk
	SET_BIT(TCCR1A,COM1A0);

#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_CLR_msk
	SET_BIT(TCCR1A,COM1A1);

#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SET_msk
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif
#endif

#if TIMER1_OC1B_Select == ENABLE
	SET_BIT(DDRD,PD4);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_TOGGLE_msk
	SET_BIT(TCCR1A,COM1B0);
#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_CLR_msk
	SET_BIT(TCCR1A,COM1B1);

#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SET_msk
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#endif

#endif
#endif

#if (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_Phase_Correct_msk)

#if TIMER1_OC1A_Select == ENABLE
	SET_BIT(DDRD,PD5);

#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_Phase_Correct_msk
	SET_BIT(TCCR1A,COM1A0);
#endif
#endif


#if TIMER1_OC1B_Select == ENABLE
	SET_BIT(DDRD,PD4);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_Phase_Correct_msk
	SET_BIT(TCCR1A,COM1B0);
#endif
#endif

#endif




#if (TIMER1_Mode_Selector == TIMER1_Mode_FastPwm_8_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_FastPwm_9_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_FastPwm_10_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Fast_Pwm_msk)

#if TIMER1_OC1A_Select == ENABLE
	SET_BIT(DDRD,PD5);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_FastPWM_msk
	SET_BIT(TCCR1A,COM1A0);
#endif

#endif




#if TIMER1_OC1B_Select == ENABLE
	SET_BIT(DDRD,PD4);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_FastPWM_msk
	SET_BIT(TCCR1A,COM1B0);
#endif

#endif
#endif



	switch(TIMER1_PreScaler_Selector){
	case TIMER1_Clk_With_No_PreScaler_msk:
		SET_BIT(TCCR0,CS10);
		break;
	case TIMER1_Clk_With_8_PreScaler_msk:
		SET_BIT(TCCR0,CS11);
		break;
	case TIMER1_Clk_With_64_PreScaler_msk:
		SET_BIT(TCCR0,CS10);
		SET_BIT(TCCR0,CS11);
		break;
	case TIMER1_Clk_With_256_PreScaler_msk:
		SET_BIT(TCCR0,CS12);
		break;
	case TIMER1_Clk_With_1024_PreScaler_msk:
		SET_BIT(TCCR0,CS10);
		SET_BIT(TCCR0,CS12);
		break;
	case TIMER1_External_Clk_With_Falling_Edge_msk:
		SET_BIT(TCCR0,CS11);
		SET_BIT(TCCR0,CS12);
		break;
	case TIMER1_External_Clk_With_Rising_Edge_msk:
		SET_BIT(TCCR0,CS10);
		SET_BIT(TCCR0,CS11);
		SET_BIT(TCCR0,CS12);
		break;
	}


	/* Initial value for Timer/Counter0 */
	TCNT1 = TIMER1_Initial_Value;

	/* Compare value for Timer/Counter0 */
	OCR1A = TIMER1_CompareA_Value;
	OCR1B = TIMER1_CompareB_Value;
#endif



	/* To enable TIMER's Interrupt */
	TIMER_EnableInterrupt();
}




/*
  * [FUNCTION NAME]: TIMER_EnableInterrupt
  * [DISCRIPTION]  : This function is responsible to Enable The required Type of Interrupt
  *                  Depend on Timer That you made it Enable.
  * [Args]  : void
  * [RUTURN]: Void
  */

void TIMER_EnableInterrupt(void){

#if TIMER0_Enable == ENABLE

#if TIMER0_OVF_INT_EN == ENABLE
	SET_BIT(TIMSK,TOIE0);
#elif TIMER0_COMP_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE0);
#endif
#endif

#if  TIMER2_Enable == ENABLE

#if TIMER2_OVF_INT_EN == ENABLE
	SET_BIT(TIMSK,TOIE2);
#elif TIMER2_COMP_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE2);
#endif
#endif


#if TIMER1_Enable == ENABLE

#if   TIMER1_OVF_INT_EN   ==  ENABLE
	SET_BIT(TIMSK,TOIE1);
#elif TIMER1_COMPA_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE1A);
#elif TIMER1_COMPB_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE1B);
#endif
#endif


}






void TIMER0_SetCallBack(void (*Ptr_To_fun)(void)){
	g_Ptr_To_Fun_0=Ptr_To_fun;
}


void TIMER1_SetCallBack(void (*Ptr_To_fun)(void)){
	g_Ptr_To_Fun_1=Ptr_To_fun;
}


void TIMER2_SetCallBack(void (*Ptr_To_fun)(void)){
	g_Ptr_To_Fun_2=Ptr_To_fun;
}


void TIMER_Deinit(void){

	/* TIMER0 De-init */
	TCCR0 = 0;
	/* TIMER2 De-init */
	TCCR2 = 0;

	/* TIMER1 De-init */
	TCCR1A = 0;
}
