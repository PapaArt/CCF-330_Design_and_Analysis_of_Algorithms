#include "../headers/map.h"

int main() {	
	// Map* map = initialize_map(10, 10);
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		map->map[i][j] = 0;
	// 	}		
	// }
	// print_field(map);
	int vetor[12];
	int number = 10;
	int count = 0;
	FILE *fptr;
	(fptr) = fopen("./test.txt", "r");
	if (fptr == NULL) printf("nao abriu");
	
	while (fscanf((fptr), "%d", &number) != -1)
	{
			vetor[count] = number;
			count++;
	}	
    
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", vetor[i]);
	}
	printf("\n");
	return 0;
}