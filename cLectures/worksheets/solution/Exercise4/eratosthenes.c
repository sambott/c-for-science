#include <stdio.h>
#include <math.h>

void findPrimes(char * Prime_List, int max_num)
{
	int current_num, sqmax_num;
	char Mask=1;
	sqmax_num = sqrt((float)max_num);

	for(current_num = 3; current_num <= sqmax_num; current_num += 2)
	{
		int Pnum = current_num / 16; /*Find which char we are on (16 as char is 8 positions of odd only)*/
		short Pbit = (current_num - Pnum * 16) / 2; /*Which bit position in current char*/
		
		if(~Prime_List[Pnum] & (Mask << Pbit))
		{	/*if the current bit in the current char is a zero(prime)
			* then lets strike out some multiples*/
			int strike;
			for(strike = current_num * current_num; strike <= max_num; strike += 2 * current_num)
			{
				int Snum = strike / 16;
				short Sbit = (strike - Snum * 16)/2;
				Prime_List[Snum] |= (Mask << Sbit);
			}
		}
	}
}

int countPrimes(char * Prime_List, int max_num)
{
	int i;
	char Mask = 1;
	int found = 1;
	for(i = 3; i <= max_num; i = i+2)
	{
		int Pnum = i / 16;
		short Pbit = (i - Pnum * 16) / 2;
		if (~Prime_List[Pnum] & (Mask << Pbit))
			found++;
	}
	return found;
}

void printPrimes(char * Prime_List, int max_num)
{
	int i;
	char Mask = 1;
	for(i = 3; i <= max_num; i = i+2)
	{
		int Pnum = i / 16;
		short Pbit = (i - Pnum * 16) / 2;
		if (~Prime_List[Pnum] & (Mask << Pbit))
			printf("%d\n", i);
	}
}
