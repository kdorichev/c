/**
 * @brief Solution to this problem
 * https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/submissions/
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Count odd numbers between high and low included
 * @param low 
 * @param high 
 * @return int 
 */
int countOdds(int low, int high){
	
	double count = (high - low) / 2.0;
	
	if (low % 2 == 1)
		count += 0.5;
	
	if (high % 2 == 1)
		count += 0.5;

	return (int)count;
}


int main(int argc, char** argv){
	int low, high;
	
	if (argc == 3){
		low  = atoi(argv[1]);
		high = atoi(argv[2]);
	}
	else{
		printf("Enter low: ");
		scanf("%d", &low);
		printf("Enter high: ");
		scanf("%d", &high);
	}

	if (low > high){
		int tmp = high;
		high = low;
		low = tmp;
	}

	printf("low: %d\nhigh: %d\n", low, high);
	printf("Number of odd numbers between %d and %d is %d\n", 
			low, high, countOdds(low, high));
}
