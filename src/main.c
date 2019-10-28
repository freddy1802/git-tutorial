#include<stdio.h>

#include "espl_lib.h"

int main() 
{
unsigned int num = 99;

	while(num != 0)
		{
		printf("Enter a number (unsigned integer) or enter '0' to exit program:\n");
		scanf("%u", &num);
			if(num != 0)
			printf("Corresponding character is: '%c'\n", &num_to_words(num));
		}

	return 0;
}