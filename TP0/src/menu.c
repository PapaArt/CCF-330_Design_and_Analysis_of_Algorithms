#include "../headers/menu.h"

void menu(){
    int choice[2];
    choice[0] = 1;
    int n;
    char **frame;

    while (choice[0] != 0)
    {
        frame = init_frame();
        print_menu1();
        scanf("%d", &choice[0]);
        switch (choice[0])
        {
        case 1:
            print_menu2();
            scanf("%d", &choice[1]);
            
            break;
        
        default:
            break;
        }
    }
       
}
void print_menu1(){

    printf("ARTWORK GENERATOR PROGRAM:");
    printf("\n=================================");
    printf("\nChoose the type of figure that will be used to generate the artwork:");
    printf("\n1 - Simple asterisk\n2 - Plus symbol with asterisks\n3 - X with asterisks\n4 - Random figures\n5 - Jumpman logo");
    printf("\nEnter the desired basic figure type: ");

}

void print_menu2(){
    printf("\nEnter the number of figures (less than or equal to zero to random): ");
}
