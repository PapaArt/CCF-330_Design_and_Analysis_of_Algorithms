#include "../headers/fibonnaci.h"

int *fib(int n) {	
	int sequence[n];
	int i = 0, flag = 1, count = 1;
	while (flag)
	{
		for (int j = 0; j < count; j++)	{
			if (i == n) {
				flag = 0;
				break;
			}
			if (j < 2) sequence[i] = 1;
			else sequence[i] = sequence[i-1] + sequence[i-2]
			i++;
		}
		count++;
	}
	return sequence;
}