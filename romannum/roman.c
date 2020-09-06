#include <stdio.h>
#include <string.h>

/*

	Roman:

	Symbol       Value
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000

	Example 1:
	Input: "III"
	Output: 3

	Example 2:
	Input: "IV"
	Output: 4

	Example 3:
	Input: "IX"
	Output: 9

	Example 4:
	Input: "LVIII"
	Output: 58
	Explanation: L = 50, V= 5, III = 3.

	Example 5:
	Input: "MCMXCIV"
	Output: 1994
	Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

	Since we will be given the pointer to the string itself, it is safe to assume that
	we have to loop through the string to search for each character and then when each character is found,
	we put each value that is represented by that character in an array

	The trickiest step is how do we get the correct representation of the roman value as an integer?

	The answer lies in subtraction based on the instructions below

	There are six instances where subtraction is used:

	I can be placed before V (5) and X (10) to make 4 and 9. 
	X can be placed before L (50) and C (100) to make 40 and 90. 
	C can be placed before D (500) and M (1000) to make 400 and 900.

	I need to check when I, X, and C come before each of the numerals mentioned as the first step

	so we need to check this by using i + 1. If the roman numeral is first and the next numeral
	is second, then we can make the subtraction. Here is how it will work

	check i and i + 1 for I and V
	5 - 1 = 4

	check i and i + 1 for I and X

	10 - 1 = 9

	check i and i + 1 for X and L

	50 - 10 = 40

	check i and i + 1 for X and C

	100 - 10 = 90

	check i and i + 1 for C and D

	500 - 100 = 400

	check i and i + 1 for C and M

	1000 - 100 = 900

	I think the second step is how to work with regular cases that don't meet the subtraction conditions:

	simply checking for them as they happen and then adding all of the values together, increases the total

	which is problematic and means that the sum we want is not correct
	
	one solution that I can think of is to check for cases that are not the subtraction cases and make that specific 

	change accordingly. for example, let's say that we found the subraction condition, the next step is to check 

	when it is not a subtraction condition but it has the other value that we are checking for. this way we can

	prevent adding the regular case to the total


*/

int romanToInt( char * s )
{
	int total, size;

	total = 0;

	//size of the string that contains the roman numerals
	size = strlen( s );

	int val[size];

	//traverse through the string and find the subtraction conditions that have to do with I, X, and C 
	for ( int i = 0; i < size; i++)
	{
		/*
			check i and i + 1 for I and V
			5 - 1 = 4

			check i and i + 1 for I and X

			10 - 1 = 9
		*/
		if ( s[i] == 'I' && s[i+1] == 'V'  )
		{
			val[i] = 4;
			total += val[i];
			break;
		}
		

		else if ( s[i] == 'I' && s[i+1] == 'X' )
		{
			val[i] = 9;
		}

		//this is a regular case
		else if ( s[i] == 'I' )
		{
			val[i] = 1;
		}

		/*
			check i and i + 1 for X and L

			50 - 10 = 40

			check i and i + 1 for X and C

			100 - 10 = 90
		*/

		if ( s[i] == 'X' && s[i+1] == 'L' )
		{
			val[i] = 40;
		}

		else if ( s[i] == 'X' && s[i+1] == 'C' )
		{
			val[i] = 90;
		}

		//this is a regular case
		else if ( s[i] == 'X' )
		{
			val[i] = 10;
		}

		/*

			check i and i + 1 for C and D

			500 - 100 = 400

			check i and i + 1 for C and M

			1000 - 100 = 900
		*/
		if ( s[i] == 'C' && s[i+1] == 'D' )
		{
			val[i] = 400;
		}
		else if ( s[i] == 'C' && s[i+1] == 'M' )
		{
			val[i] = 900;
		}

		//this is a regular case
		else if ( s[i] == 'C' )
		{
			val[i] = 100;
		}

		
		//this is a regular case
		if ( s[i] == 'L' )
		{
			val[i] = 50;
		}

		//this is a regular case
		if ( s[i] == 'V' )
		{
			val[i] = 5;
		}


		//this is a regular case
		if ( s[i] == 'D' )
		{
			val[i] = 500;
		}

		//this is a regular case
		if ( s[i] == 'M' )
		{
			val[i] = 1000;
		}

		printf("val[i]= %d\n", val[i] );
		total += val[i];



	}



	printf("total %d\n", total );



	return total;
}


int main()
{
	char str [] = "IVXC";

	printf ( "str: %s, val: %d", str, romanToInt( str ) );

	return 0;
}