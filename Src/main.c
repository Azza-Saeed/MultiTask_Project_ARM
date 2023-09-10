/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Azza Saeed
 */



#include "../inc/App.h"



int main(void)
{
	App_Init();

	while(1){
		App_Main();
	}

	return 0;
}
