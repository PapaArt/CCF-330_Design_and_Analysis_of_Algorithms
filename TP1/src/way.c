#include "../headers/way.h"

void make_list_empty(list_type *list)
{
    list->first = (pointer_type)malloc(sizeof(type_cell));
	list->last = list->first;
	list->first->next = NULL;
}

void insert(field field, list_type *tlist)
{
	tlist->last->next = (pointer_type)malloc(sizeof(type_cell));
	tlist->last = tlist->last->next;
	tlist->last->field = field;
	tlist->last->next = NULL;
}

void print_way(list_type *list, int n)
{
	printf("%s %s\n", list->first->field.direction, list->first->field.visited);
}
