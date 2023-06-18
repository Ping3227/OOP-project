#include "../header/menu.hpp"
#include "../header/window.hpp"
#include <cstdlib>
#include <string>
#include <GL/glut.h>

Menu::Menu() {
    int colorSettingSubMenuId = glutCreateMenu(Menu::ColorOption);
    glutAddMenuEntry("Red", RED);
    glutAddMenuEntry("Blue", BLUE);
    glutAddMenuEntry("Green", GREEN);

    int numberSettingSubMenuId = glutCreateMenu(Menu::NumOption);
    glutAddMenuEntry("150", NUM_150);
    glutAddMenuEntry("200", NUM_200);
    glutAddMenuEntry("400", NUM_400);

    int angleSettingSubMenuId = glutCreateMenu(Menu::DegOption);
    glutAddMenuEntry("70 degree", DEG_70);
    glutAddMenuEntry("80 degree", DEG_80);
    glutAddMenuEntry("90 degree", DEG_90);

    int mapSubMenuId = glutCreateMenu(Menu::MapOption);
    int map_size= Window::getMapSize();
    for(int i = 0; i < map_size; i++){
        glutAddMenuEntry(("map" + std::to_string(i)).c_str(), i);
    }

    int ModeSubMenuId = glutCreateMenu(Menu::ModOption);
    glutAddMenuEntry("Normal mode",NORMAL );
    glutAddMenuEntry("Cheat mode", CHEAT);
    int settingId = glutCreateMenu(Menu::settingOption);
    glutAddSubMenu("angle", angleSettingSubMenuId);
    glutAddSubMenu("number",numberSettingSubMenuId);
    glutAddSubMenu("color",colorSettingSubMenuId);
    glutAddSubMenu("map",mapSubMenuId);
    glutAddSubMenu("mode",ModeSubMenuId);

    int mainMenuId = glutCreateMenu(Menu::mainMenu);
    glutAddSubMenu("Setting", settingId);
    glutAddMenuEntry("Restart", RESTART);
    glutAddMenuEntry("Exit", EXIT);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Menu::mainMenu(int option){
    switch (option) {
        case SETTING:
            break;
        case RESTART:
            Window::Restart();
            Window::setState(0);
            glutPostRedisplay();
            break;
        case EXIT:
            exit(0);
            break;
    }
}

void Menu::settingOption(int option){
    switch (option){
        case COLOR:
            break;
        case RAY_NUM:
            break;
        case DEG:
            break;
    }
}

void Menu::ColorOption(int option) {
    switch (option) {
        case RED:
            Window::setColor(0.8,0.1,0.2);
            glutPostRedisplay();
            break;
        case BLUE:
            Window::setColor(0.0,0.2,0.8);
            glutPostRedisplay();
            break;
        case GREEN:  
            Window::setColor(0.3,0.7,0.2);
            glutPostRedisplay();
            break;
    }
}

void Menu::DegOption(int option) {
    switch (option) {
        case DEG_70:
            Window::setDegree (70);
            glutPostRedisplay();
            break;
        case DEG_80:
            Window::setDegree(80);
            glutPostRedisplay();
            break;
        case DEG_90:
            Window::setDegree(90);
            glutPostRedisplay();
            break;
    }
}
void Menu::MapOption(int option) {
    // set order = option;
    Window::setMap(option);
    Window::Restart();
    Window::setState(0);
    glutPostRedisplay();
}
void Menu::ModOption(int option){
    switch(option){
        case NORMAL:
            Window::modeChange(NORMAL);
            break;
        case CHEAT :
            Window::modeChange(CHEAT);
            break;
    }
    glutPostRedisplay();
}
void Menu::NumOption(int option) {
    switch (option) {
        case NUM_150:
            Window::setRayNum(150);
            glutPostRedisplay();
            break;
        case NUM_200:
            Window::setRayNum(200);
            glutPostRedisplay();
            break;
        case NUM_400:
            Window::setRayNum(400);
            glutPostRedisplay();
            break;
    }
}
