#include <stdio.h>
#include <stdlib.h>

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

int reverse(int x){
	
	//int val;
	//int arr_val[x];

	//for (int i = 32; i >= 0; i--)
	//	arr_val[i] = x % 10;
	//	x /= 10;





	return x; //return the value reversed

}

int main(){

	int x = 123;

	int reversed_integer;

	reversed_integer = reverse(x);

	printf("%d\n", reversed_integer);

	return 0;
}


