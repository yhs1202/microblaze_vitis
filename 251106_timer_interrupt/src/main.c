/*
 * main.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */


#include <stdio.h>
#include "xil_printf.h"
#include "ap/ap.h"

int main() {
   print("hello world!\n");
   xil_printf("hello world\n");

   ap_main();
   return 0;
}
