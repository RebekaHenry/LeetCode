#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*

	Example 1:
	Input: 121
	Output: true
	
	Example 2:
	Input: -121
	Output: false
	Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
	
	Example 3:
	Input: 10
	Output: false
	Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

	challenge- solve this problem without converting the integer to a string. this may be difficult
	because how will we deal with negative numbers. Only thing I can assume is that I have to deal with negative 
	cases separately from positive cases. Here is what I am thinking so far:

	reverse the integer using the reverse function I had previously created and check if it is a palindrome (positive cases)
	for negative cases, detect that the value is less than 0 and if it is, it is likely that the value 
	will not be a palindrome




*/

signed int reverse( signed int x )
{
	signed long long reverse = 0;
	signed int back_first;

	while( x != 0 )
	{
		back_first = x % 10;
		reverse = reverse * 10 + back_first;

		if ( reverse <= INT_MIN || reverse >= INT_MAX )
			reverse = 0;

		x /= 10;
	}

	return reverse;

}
_Bool isPalindrome( int x )
{
	int reversedVal = 0;

	reversedVal = x;

	//check for negative integers
	if ( x < 0 )
	{
		//printf("false\n");
		return false;
	}

	//check if the value would be the same when reversed
	else if ( x == reverse ( reversedVal ) )
	{
		//printf( "true\n" );
		//printf( "reversed Value %d\n", reverse ( reversedVal )  );
		return true;
	}
	//if not, then it is false
	else
	{
		//printf( "false\n" );
		//printf( "reversed Value %d\n", reverse ( reversedVal ) );
		return false;
	}
}

int main( )
{
	isPalindrome( -121 );

	return 0;
}