#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 *  Example 1:

	Input: nums = [2,7,11,15], target = 9
	Output: [0,1]
	Output: Because nums[0] + nums[1] == 9, we return [0, 1]

	Example 2:

	Input: nums = [3,2,4], target = 6
	Output: [1,2]

	Example 3:

	Input: nums = [3,3], target = 6
	Output: [0,1]

	notes for each variables-

	int* nums -> points to the array of integer numbers that we are going to traverse through
	to find the indices

	int numsSize -> this is the size of the nums array (we are using a for loop for the traversal)

	int target -> target is the value that we want to add up to. If the target is 9, then we need 2 + 7 = 9
				  this is how we check if we find the indices

	int* returnSize -> points to the indices that we will return after adding up the target	

	algorithm:

	traverse the nums array

	have two pointers- one pointer points to the first index (0) and the second pointer points to the second index (1)

	add the values at the indexes together

	if they equal the target, return the indices

	otherwise, shift each pointer by one and keep checking if the values equal to the target
 * 
 */
int* twoSum( int* nums, int numsSize, int target, int* returnSize )
{
	//numsSize = sizeof(nums)/sizeof(int*);

	//malloc the returned array
	int* returnArray = ( int* ) malloc( sizeof( int ) * 2 );

	//pointers 0 and 1
	int ptr0, ptr1;

	int index0 = 0;
	int index1 = 0;

	//traverse through the nums array
	for (int i = 0; i < numsSize; i++)
	{
		if ( returnArray == NULL)
		{
			*returnSize = 0;
			return NULL;
		}
		
		//set ptr0 to the first index (0)
		ptr0 = *( nums + i );
		index0 = i;

		//set ptr1 to the second index (1)
		ptr1 = *( nums + ( i+1 ) );
		index1 = i+1;

		//check if the indices add up to the target
		if ( ptr0 + ptr1 == target )
		{
			//place the indices into return array
			returnArray[0] = index0;
			returnArray[1] = index1;

			*returnSize = 2;
			return returnArray;	
		}
	}

	*returnSize = 0;

	//return the indices that correspond to the target
	return NULL;

}


int main( ){

	int nums[ ] = {2,7,11,15};
	int numsSize = sizeof(nums)/sizeof(int*);
	int target = 9;
	int returnSize[2] = { };

	twoSum( nums, numsSize, target, returnSize );


	return 0;
}