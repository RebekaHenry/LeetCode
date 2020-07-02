#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

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



//leetcode successful solution (check the overflow using long long int)
signed int reverse(signed int x){

signed long long reverse = 0;
signed int back_first;


while (x != 0){
	back_first = x % 10;
	reverse = reverse * 10 + back_first;

	if (reverse <= INT_MIN || reverse >= INT_MAX)
		reverse = 0;

	x /= 10;
	}

	return reverse;

}


//another solution below that does not pass leetcode because of abs function

/*signed int reverse(signed int x){

	//in order to be able to check the overflow condition, use a long long int so compiler doesn't 
	//ignore it as a don't care
	signed long long reverse = 0; 

	//extract the number of digits (add 1 to make sure the 0 is included)
	unsigned num_digits = log10(abs(x)) + 1;

	printf("number of digits %d\n", num_digits );

	signed long long arr_int[num_digits];

	//convert the integer to an arry integer to work with it (arr int is reversed already)
	for (signed int i = 0; i < num_digits; i++){	
		arr_int[i] = x % 10;
		x /= 10;
	}


	//before converting the array back to an integer, check for overflow conditions of the reversed integer
	for (signed int i = 0; i < num_digits; i++)
		reverse = 10 * reverse + arr_int[i];

	if (reverse <= INT_MIN || reverse >= INT_MAX)
		reverse = 0;

	return reverse;
}*/

 
int main(){

	//signed int x = -1534236469;

	signed int x = -2147483648;

	//signed int x = -120;

	signed int reversed_integer;

	reversed_integer = reverse(x);

	printf("Main: %d\n", reversed_integer);

	return 0;
}


