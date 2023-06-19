#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include "menu.hpp"
class Game;

class Window {
public:
    // set up window 
    Window(const std::string& title, int width, int height);
    // choose what game function to be display 
    static void Display();
    // button not pressed handler 
    static void buttonUP(unsigned char key, int x, int y);
    // button  pressed handler 
    static void buttonDown(unsigned char key, int x, int y);
    // screen size change handler 
    static void Resize(int width ,int height);
    // set something for menu 
    static void setDegree(int deg);
    static void setRayNum(int num);
    static void setColor(float r , float g ,float b );
    static void setMap(int order);
    static void modeChange(int mode);
    static void setState(int state);
    // get map number 
    static int getMapSize();
    // get state 
    static int getState();
    // restatrt the game with current map 
    static void Restart();
    
private:
    static std::unique_ptr<Game> game;
    static Menu menu;
    static int degree;
    static int ray_num;
    static float r,g,b;
};

#endif  // WINDOW_H
