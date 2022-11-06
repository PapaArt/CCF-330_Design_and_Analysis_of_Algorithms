#include "../headers/map.h"

int main() {	
	
	Map* map;
	
	int count = 0;
	char line[100];
	int width, height;
	int flag = 1;
	int number;
	FILE *fptr;
	(fptr) = fopen("./data/field.txt", "r");
	if (fptr == NULL) printf("nao abriu");
	int result;
	int j;
	char *word;
	while (!feof(fptr))
	{
		// Lê uma linha (inclusive com o '\n')
		result = fgets(line, 100, fptr);  // o 'fgets' lê até 99 caracteres ou até o '\n'
						
		if (count == 0) {
			sscanf(line, "%d %d", &width, &height);			
			map = initialize_map(width, height);
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < height; j++)
				{
					map->map[i][j] = 2;
				}		
			}
			print_field(map);			
			printf("\n");
		} else {
			j = 0;
			word = strtok(line, " ");
			map->map[count-1][j] = atoi(word);
			j++;
			while ((word = strtok(NULL, " ")) != NULL) {
				map->map[count-1][j] = atoi(word);
				j++;
			}
		}
		count++;
	}
	
	print_field(map);

	

	//  while (fscanf((fptr), "%d", &number) != -1)
	// {
	// 		vetor[count] = number;
	// 		count++;
	// }	
    
	// for (int i = 0; i < width; i++)
	// {
	// 	printf("%d ", vetor[i]);
	// }
	// printf("%s\n", line);
	return 0;
}