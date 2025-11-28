#include "gld_core.h"
#include <GLFW/glfw3.h>

void gld_init(){
    if (!glfwInit()){
        return;
    }
}

void gld_exit(){
    glfwTerminate();
}