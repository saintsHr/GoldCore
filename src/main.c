#include <gld.h>

int main(){
    gld_init();

    gld_window window = gld_windowCreate(640, 480, "Minha Janela");
    gld_windowSetContext(window);
    gld_windowSetup(window, GLD_2D);

    while (!gld_windowShouldClose(window)){
        gld_windowClear();



        gld_windowHandle(window);
    }

    gld_exit();
    return 0;
};