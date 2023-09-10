/*
 * App.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Azza Saeed
 */

#include "../inc/App.h"
#include "../inc/BIT_MATH.h"
#include "../inc/STD_TYPES.h"


#include "../inc/RCC_interface.h"
#include "../inc/GPIO_interface.h"
#include "../inc/STK_interface.h"
#include "../inc/LED_config.h"
#include "../inc/LED_interface.h"


STD_ERROR App_Init(void){
	uint8 Local_Error=SUCCESS;
	/* Initialize Clock System  */
	RCC_voidInitSysClock();
	/* Enable GPIOC Clock */
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOC_EN);
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOA_EN);
	/* led on stm board */
	GPIO_voidSetPinDirection(GPIOC, PIN13, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(GPIOC, PIN15, OUTPUT_SPEED_10MHZ_PP);
	return Local_Error;
}
STD_ERROR App_Main(void){
	uint8 Local_Error=SUCCESS;
	Traffic_task();
	return Local_Error;
}
STD_ERROR Traffic_task(void){
	uint8 Local_Error=SUCCESS;
	Green_Led();
	STK_voidDelay_ms(ONE_HALF_SEC);
	Yellow_Led();
	STK_voidDelay_ms(ONE_SEC);
	Red_Led();
	STK_voidDelay_ms(ONE_HALF_SEC);
	return Local_Error;
}

STD_ERROR Green_Led(void){
	uint8 Local_Error=SUCCESS;
	LED_voidLed_Toggle(GPIOC, PIN15);
	return Local_Error;
}
STD_ERROR Red_Led(void){
	uint8 Local_Error=SUCCESS;
	LED_voidLed_Toggle(GPIOA, PIN2);
	return Local_Error;
}
STD_ERROR Yellow_Led(void){
	uint8 Local_Error=SUCCESS;
	LED_voidLed_Toggle(GPIOC, PIN13);
	return Local_Error;
}
/*SysTick_Handler(){
	counter++;
}*/
