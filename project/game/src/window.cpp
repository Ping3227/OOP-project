#include "../header/window.hpp"
#include "../header/game.hpp"
#include "../header/button.hpp"
#include <GL/freeglut.h>
#include <GL/glut.h>
std::unique_ptr<Game> Window::game;
int  Window::degree=90;
int  Window::ray_num=200;
float Window::r =0.3, Window::g= 0.7, Window::b =0.2;
// set up window 
Window::Window(const std::string& title, int width, int height) {
    #ifdef _MSC_VER 
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    #else  
        glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH ); // use in free glut GLUT_3_2_CORE_PROFILE |
    #endif   
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutCreateWindow(title.c_str());
    glClearColor(0.3f, 0.3f, 0.3f, 0.0f);

    game = std::make_unique<Game>();
    
    glutDisplayFunc(Display);
    glutKeyboardFunc(buttonDown);
    glutKeyboardUpFunc(buttonUP);
    glutReshapeFunc(Resize);
    menu=Menu();
}
// choose what to display by state 
void Window::Display() { // width height 
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 2160, 0, 1080);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(getState()==0){
        game->movement();
        game->draw2DMap();
        game->drawPlayer();
        game->draw2DRays(Window::degree,Window::ray_num ,Window::r ,Window::g ,Window::b);
    }
    else{
        game->drawEnd();
    }
    
    glutSwapBuffers();
}
// resize handler 
void Window::Resize(int width ,int height){
    glutReshapeWindow(2160,1080);

}
// button not pressed handler 
void Window::buttonUP(unsigned char key,int x,int y){
    game->processInput(key,0);
    glutPostRedisplay();
}
 // button  pressed handler 
void Window::buttonDown(unsigned char key,int x,int y){
    
    game->processInput(key,1);
    glutPostRedisplay();
}

void Window::setDegree(int deg){
    degree=deg;
}
void Window::setRayNum(int num){
    ray_num=num;
}

void Window::setColor(float r , float g ,float b ){
    Window::r=r;
    Window::g=g;
    Window::b = b;
}
void Window::setMap(int order){
    game->setMap(order);
};
int  Window::getMapSize(){
    return game->getMapSize();
};
void Window::modeChange(int mode){
    game->modeChange(mode);
}
int Window::getState(){
    return game->getState();
};
void  Window::setState(int state){
    game->setState(state);
};
void Window::Restart(){
    game->Restart();
};