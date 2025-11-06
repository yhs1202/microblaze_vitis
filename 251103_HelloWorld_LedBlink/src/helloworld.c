/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

typedef struct {
	volatile uint32_t DR;
	volatile uint32_t CR;
} GPIO_TypeDef;

#define GPIO_BASE_ADDR		0x40000000
#define GPIOA				((GPIO_Type_Def *)(GPIO_BASE_ADDR))
#define GPIO_DR             (*(uint32_t *) (GPIO_BASE_ADDR + 0x00))
#define GPIO_CR             (*(uint32_t *) (GPIO_BASE_ADDR + 0x04))

void delay_m(uint32_t ms);

int main()
{
    GPIOA->CR = 0x0000;   // 16 bit all output
    print("Hello World\n\r");


    while (1)
    {   
//      GPIO_DR = 0xffff;
//      GPIOA->DR = 0xffff;
//      GPIOA.DR = 0xffff;
//      ((GPIO_TypeDef *)(0x40000000))->DR;
    	LED_write(GPIOA, 0xffff);
        delay_m(300);
        delay_m(300);
    }
    
    return 0;
}


void LED_write (GPIO_TypeDef *gpio, uint32_t data)
{
	gpio->DR = data;
}
void delay_m(uint32_t ms)
{
    usleep(ms * 1000);
}
