#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include "menu.hpp"
class Game;

class Window {
public:
    Window(const std::string& title, int width, int height);

    static void Display();
    static void buttonUP(unsigned char key, int x, int y);
    static void buttonDown(unsigned char key, int x, int y);
    static void Resize(int width ,int height);

    static void setDegree(int deg);
    static void setRayNum(int num);
    static void setColor(float r , float g ,float b );
    static void setMap(int order);
    static int getMapSize();
    static void modeChange(int mode);
    static int getState();
    static void setState(int state);
    static void Restart();
    
private:
    static std::unique_ptr<Game> game;
    static Menu menu;
    static int degree;
    static int ray_num;
    static float r,g,b;
};

#endif  // WINDOW_H
