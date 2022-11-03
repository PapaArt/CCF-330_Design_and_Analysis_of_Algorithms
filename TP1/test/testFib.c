#include "../include/fibonnaci.h"
#include <stdio.h>

int main() {
	int *sequence;

	sequence = fibonnaci(100);

	for (int i = 0; i < 100; i++)
	{
		printf("%d\n", sequence[i]);
	}
	
	return 0;
}