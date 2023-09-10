/*
 * App.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Azza Saeed
 */

#ifndef APP_H_
#define APP_H_


#define STD_OK    1
#define SDT_NOK   2


#define ONE_SEC          500
#define ONE_HALF_SEC     300
#define MILL_500         100

typedef enum{
	FAIL,
	SUCCESS
}STD_ERROR;

STD_ERROR App_Init(void);
STD_ERROR App_Main(void);
STD_ERROR Traffic_task(void);
STD_ERROR Green_Led(void);
STD_ERROR Red_Led(void);
STD_ERROR Yellow_Led(void);

#endif /* APP_H_ */
