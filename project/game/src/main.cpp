#include <iostream>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include "../header/window.hpp"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    Window window("WindowCreate", 2160, 1080);
    glutMainLoop();
    return 0;
}
