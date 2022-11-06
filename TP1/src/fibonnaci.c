#include "../headers/fibonnaci.h"

void fibonnaci(int* sequence, int n) {
    int i = 0, flag = 1, count = 1;
    while (flag) {
        for (int j = 0; j < count; j++) {
            if (i == n) {
                flag = 0;
                break;
            }
            if (j < 2)
                sequence[i] = 1;
            else
                sequence[i] = sequence[i - 1] + sequence[i - 2];
            i++;
        }
        count++;
    }
}

void printFibonnaci(int* sequence, int n) {
	int i = 0, flag = 1, count = 1;
    while (flag) {
        for (int j = 0; j < count; j++) {
            if (i == n) {
                flag = 0;
                break;
            }
            printf("%d ", sequence[i]);
            i++;
        }
		printf("\n");
        count++;
    }
	while (flag)
	{
		for (int j = 0; j < count; j++)	{
			if (i == n) {
				flag = 0;
				break;
			}
			if (j < 2) sequence[i] = 1;
			else sequence[i] = sequence[i-1] + sequence[i-2];
			i++;
		}
		count++;
	}
	return sequence;
}