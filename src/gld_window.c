#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include "gld_window.h"

gld_window gld_windowCreate(uint16_t width, uint16_t height, const char* title){
    gld_window w;
    w.width = width;
    w.height = height;
    w.title = title;

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    w.handle = glfwCreateWindow(w.width, w.height, w.title, NULL, NULL);

    if (!w.handle){
        return (gld_window){0};
    }

    return w;
}

void gld_windowSetContext(gld_window w){
    glfwMakeContextCurrent(w.handle);
}

bool gld_windowShouldClose(gld_window w){
    return glfwWindowShouldClose(w.handle);
}

void gld_windowSetup(gld_window w, gld_projection proj){
    glViewport(0, 0, w.width, w.height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (proj == GLD_2D){
        glOrtho(-1, 1, -1, 1, -1, 1);
    } else if (proj == GLD_3D){
        float aspect = (float)w.width / (float)w.height;
        gluPerspective(60.0f, aspect, 0.1f, 100.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void gld_windowResize(gld_window w, uint16_t newWidth, uint16_t newHeight){
    glfwSetWindowSize(w.handle, newWidth, newHeight);
}

void gld_windowClear(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gld_windowHandle(gld_window w){
    glfwSwapBuffers(w.handle);
    glfwPollEvents();
}