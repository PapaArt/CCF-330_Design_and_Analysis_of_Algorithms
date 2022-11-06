#include "../headers/menu.h"

int main(){
    Map *map;
    Data *data = (Data*)malloc(sizeof(Data));
    menu(map, data);
    return 0;
}