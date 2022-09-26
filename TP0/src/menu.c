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
            asterisk(frame, choice[1]);
            print_frame(frame);
            break;
        case 2:
            print_menu2();
            scanf("%d", &choice[1]);
            plus_asterisk(frame, choice[1]);
            print_frame(frame);
            break;
        case 3:
            print_menu2();
            scanf("%d", &choice[1]);
            X_asterisk(frame, choice[1]);
            print_frame(frame);
            break;
        case 4:
            print_menu2();
            scanf("%d", &choice[1]);
            random_art(frame, choice[1]);
            print_frame(frame);
            break;
        case 5:
            print_menu2();
            scanf("%d", &choice[1]);
            jumpman_logo(frame, choice[1]);
            print_frame(frame);
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
    printf("\nEnter the number of figures: ");
}
