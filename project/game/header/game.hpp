
#ifndef GAME_H
#define GAME_H
#include "map.hpp"
#include "button.hpp"
//#include "texture.hpp"
//#include "sprite.hpp"
#define PI 3.1415926535897932

class Game {
public:
    Game();
    void processInput(unsigned char key,int state);
    void draw2DRays(int angle, int ray,float r, float g ,float b ) const;
    void drawPlayer() const;
    void draw2DMap() const;
    void movement() ;
    void setMap(int order);
    int getMapSize();
    void modeChange(int mode);
    void Restart();
    int getState();
    void setState(int state);
    void drawEnd();
private:
    double px, py;
    double pa, pdx, pdy;
    Button button;
    double speed;
    Map map;
    double dist(double x, double y) const;
    int mode =1;  
    int state=0;//state 0 game  , state 1 win  
};

#endif  // GAME_H
