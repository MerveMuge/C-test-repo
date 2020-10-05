//gcc float_double.c -lm -o output && ./output
#include <math.h>
#include <stdio.h>

int main(){

	float val = 37.777779;

	float rounded_down = floorf(val * 100) / 100;   /* Result: 37.77 */
	float nearest = roundf(val * 100) / 100;  /* Result: 37.78 */
	float rounded_up = ceilf(val * 100) / 100;      /* Result: 37.78 */

	/*
	*float (and double) aren't decimal floating-point - they are binary floating-point
	*/

	if(rounded_down != 37.77){
		printf("couldnt be equal. it's inexact.\n");
	}
	
	return 0;
}
