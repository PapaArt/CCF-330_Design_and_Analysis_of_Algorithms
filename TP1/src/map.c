#include "../headers/map.h"

void initialize_map(map *map, int width, int height)
{
    map->height = height;
    map->width = width;

    map->map = (char **)malloc(sizeof(char *) * width);
    for (int i = 0; i < width; i++)
    {
        map->map[i] = (char *)malloc(sizeof(char *) * height);
    }
}

void insert_line(map *map, int position, char *line)
{
    for (int i = 0; i < map->width; i++)
    {
        for (int j = 0; j < map->height; j++)
        {
            map->map[position][j] = line[j];
        }
    }
}

// Função para fazer a movimentação do fazendeiro, necessidade de definir os parâmetros
int movement()
{

}

void initialize_data(data *data)
{
    data->number_of_recursions = -1;
}

void print_field()
{
	FILE *fptr;

	char c;
    char *filename;

    filename = "./data/field.txt";
    
	// Open file
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	// Read contents from file
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf ("%c", c);
		c = fgetc(fptr);
	}
    printf("\n");
	fclose(fptr);
}