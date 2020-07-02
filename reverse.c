#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Task: reverse an integer that is a signed 32 bit integer

	Example 1:

	Input: 123
	Output: 321

	Example 2:

	Input: -123
	Output: -321

	Example 3:

	Input: 120
	Output: 21


*/

signed int reverse(signed int x){

	signed int reverse = 0;
	signed int back_first;


	while (x != 0){
		back_first = x % 10;
		reverse = reverse * 10 + back_first;
		x /= 10;
	}

	return reverse;

}

int main(){

	signed int x = 120;

	signed int reversed_integer;

	reversed_integer = reverse(x);

	printf("Main: %d\n", reversed_integer);

	return 0;
}


