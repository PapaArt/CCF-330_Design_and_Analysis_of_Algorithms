#include "../headers/frame.h"

int main(){
    char **quadro = init_frame();
    //asterisk(quadro, 20);
    plus_asterisk(quadro, 20);
    print_frame(quadro);
    // X_asterisk();
    // jordan1();
    // jordan2();
    
    return 0;
}