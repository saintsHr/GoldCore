#pragma once
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct{
    GLFWwindow* handle;
    uint16_t width;
    uint16_t height;
    const char* title;
}gld_window;

typedef enum gld_projection{
    GLD_2D,
    GLD_3D
}gld_projection;

gld_window gld_windowCreate(uint16_t width, uint16_t height, const char* title);
bool gld_windowShouldClose(gld_window w);
void gld_windowSetContext(gld_window w);
void gld_windowHandle(gld_window w);
void gld_windowClear();
void gld_windowSetup(gld_window w, gld_projection proj);