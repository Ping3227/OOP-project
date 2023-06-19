
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
    // set button  status for 
    void processInput(unsigned char key,int state);
    // dray ray ,and show 3D view by raycasting 
    void draw2DRays(int angle, int ray,float r, float g ,float b ) const;
    // dray player at map
    void drawPlayer() const;
    // draw 2D map 
    void draw2DMap() const;
    // check button statae , and move corresponding 
    void movement() ;
    // set the map ,we currently choose now
    void setMap(int order);
    // get how many map we have 
    int getMapSize();
    //change the mode , show or not show 2D map
    void modeChange(int mode);
    // restart setting 
    void Restart();
    // get current state ,winning or gaming 
    int getState();
    // set state 
    void setState(int state);
    // the scene jump out , while you accomplish the game 
    void drawEnd();
private:
    double px, py; // current postition 
    double pa, pdx, pdy; //angle and the normal direction we are looking
    Button button;
    double speed;
    Map map;
    //help function get distance between (x ,y )and character
    double dist(double x, double y) const;
    int mode =1;  
    int state=0;//state 0 game  , state 1 win  
};

#endif  // GAME_H
