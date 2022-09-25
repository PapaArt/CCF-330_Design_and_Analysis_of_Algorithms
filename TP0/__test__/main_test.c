#include "../headers/frame.h"

int main(){
    char **quadro = init_frame();
    //asterisk(quadro, 20);
    //plus_asterisk(quadro, 20);
    //X_asterisk(quadro, 20);
    //jordan1(quadro, 8);
    //jordan2(quadro, 12);
    piano1(quadro, 5);
    print_frame(quadro);
    
    return 0;
}