#include <gld.h>

int main(){
    gld_init();

    gld_window window = gld_windowCreate(640, 480, "Minha Janela");
    gld_windowSetContext(window);
    gld_windowSetup(window, GLD_2D);

    int track = 0;

    while (!gld_windowShouldClose(window)){
        gld_windowClear();

        glRotatef(1, 0, track, 0);

        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5f, -0.4f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(0.0f, 0.6f);

            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.5f, -0.4f);
        glEnd();

        track++;
        
        gld_windowHandle(window);
    }

    gld_exit();
    return 0;
};