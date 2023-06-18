#ifndef BUTTON_H
#define BUTTON_H
#include "game.hpp"
class Button{

public: 
    int up,down,left, right;
    Button(){
        up=down=left=right=0;
    }
    friend class Game;
};
#endif  // Button_H