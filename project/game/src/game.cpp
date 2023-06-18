#include "../header/game.hpp"
#include <cmath>
#include <GL/glut.h>
#include <string>
#define PI 3.1415926535897932
Game::Game() : px(90), py(80), pa(0), pdx(0), pdy(0), speed(1) {
    map = Map();
    button =Button();
}

void Game::processInput(unsigned char key,int state) {
    switch (key){
        case 'a':button.left=state;
            break;
        case 'w':button.up=state;
            break;
        case 's':button.down=state;
            break;
        case 'd':button.right=state;
            break;
    }
    
}
double Game::dist(double x, double y) const {
    return (x - px) * (x - px) + (y - py) * (y - py);
}

void Game::draw2DRays(int angle, int ray,float red, float green ,float blue ) const {
    int size = 50;
    int mx, my, mp, dof;
    double rx, ry, ra, x0, y0, rx2, ry2;
    ra = pa - PI / 360 * angle;
    if (ra < 0) ra += 2 * PI;
    double ri = PI / 180 * angle / ray;
    double height;

    for (int r = 0; r < ray; r++, ra += ri) {
        if (ra >= 2 * PI) ra -= 2 * PI;
        dof = 0;
        double atan = -1 / tan(ra);

        if (ra > PI) { // Looking downwards
            ry = static_cast<int>(py / size) * size - 0.00001;
            rx = (py - ry) * atan + px;
            y0 = -size;
            x0 = -y0 * atan;
        } else if (ra < PI) { // Looking upwards
            ry = static_cast<int>(py / size) * size + size;
            rx = (py - ry) * atan + px;
            y0 = size;
            x0 = -y0 * atan;
        } else { // Looking horizontal
            rx = px;
            ry = py;
            dof = map.getHeight();
        }

        while (dof < map.getHeight()) {
            mx = static_cast<int>(rx / size);
            my = static_cast<int>(ry / size);

            if (map.isWall(mx, my)) {
                break;
            } else {
                rx += x0;
                ry += y0;
                dof++;
            }
        }

        dof = 0;
        atan = 1 / atan;

        if (ra < PI / 2 || ra > 3 * PI / 2) { // Looking rightwards
            rx2 = static_cast<int>(px / size) * size + size;
            ry2 = (px - rx2) * atan + py;
            x0 = size;
            y0 = -x0 * atan;
        } else if (ra > PI / 2 && ra < 3 * PI / 2) { // Looking leftwards
            rx2 = static_cast<int>(px / size) * size - 0.00001;
            ry2 = (px - rx2) * atan + py;
            x0 = -size;
            y0 = -x0 * atan;
        } else { // Looking horizontal
            rx2 = px;
            ry2 = py;
            dof = map.getHeight();
        }

        while (dof < map.getHeight()) {
            mx = static_cast<int>(rx2 / size);
            my = static_cast<int>(ry2 / size);

            if (map.isWall(mx, my)) {
                break;
            } else {
                rx2 += x0;
                ry2 += y0;
                dof++;
            }
        }

        glColor3f(0, 1, 0);
        glLineWidth(1);
        glBegin(GL_LINES);
        //color setting 
        float shade=0.75;
        
        if (dist(rx, ry) > dist(rx2, ry2)) {
            if(mode==1){
                glVertex2i(px, py);
                glVertex2i(rx2, ry2);
            }
            glColor3f(red*shade, green*shade, blue*shade);
            if (map.isWall(rx2/size, ry2/size)==2) glColor3f(0.3,0.3,0.3);// exit
            
            height = dist(rx2, ry2);
        } else {
            if(mode==1){
                glVertex2i(px, py);
                glVertex2i(rx, ry);
            }
            glColor3f(red, green, blue);
            if (map.isWall(rx/size, ry/size)==2) glColor3f(0.3,0.3,0.3);// exit
            height = dist(rx, ry);
            
        }

        glEnd();
        
        height = 10000 / (sqrt(height) * cos(pa - ra));
        /*int y;
        float ty =0;
        float ty_step=32.0/(float)height;*/
        
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(-r * (float)1600/ray + 2160, 500 - height);
        glVertex2i(-r * (float)1600/ray + 2160, 500 + height);
        glEnd();
           //for (y=0;y<height;y++){}
            /*float c= tex.index()
            glPointSize(4);
            glBegin(GL_POINTS);
            glVertex2i(-r * 8 + 2160, 500 - height+2y);
            glEnd();*/
        
    }
}

void Game::drawPlayer() const {
    if(mode==1){
        glColor3f(1, 1, 0);
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2i(px, py);
        glEnd();
    }
    
}

void Game::draw2DMap() const {
    if(mode==1){
        int size = 50;
        glBegin(GL_QUADS);

        for (int i = 0; i < map.getHeight(); i++) {
            for (int j = 0; j < map.getWidth(); j++) {
                if (map.isWall(j, i))
                    glColor3f(1, 1, 1);
                else
                    glColor3f(0, 0, 0);

                glVertex2i(j * size + 1, i * size + 1);
                glVertex2i(j * size + 1, (i + 1) * size - 1);
                glVertex2i((j + 1) * size - 1, (i + 1) * size - 1);
                glVertex2i((j + 1) * size - 1, i * size + 1);
            }
        }

        glEnd();
    }
}
void Game::movement() {
    if(button.left==1 ) {
        pa += 0.1;
        if (pa >= 2 * PI) pa -= 2 * PI;
        pdx = 5 * cos(pa);
        pdy = 5 * sin(pa);
        
    };
    if(button.right==1 ){
        pa -= 0.1;
        if (pa <= 0) pa += 2 * PI;
        pdx = 5 * cos(pa);
        pdy = 5 * sin(pa);
        
    }
    if (button.up==1){
        px += speed * pdx;
        py += speed * pdy;
        if(map.isWall(px/50,py/50)==2) state=1;
        else if(map.isWall(px/50,py/50)==1){
            px-=speed *pdx;
            py-=speed *pdy;
        }
    }
    if(button.down==1){
        px -= speed * pdx;
        py -= speed * pdy;
        if(map.isWall(px/50,py/50)==2) state=1;
        else if(map.isWall(px/50,py/50)==1){
            px+=speed *pdx;
            py+=speed *pdy;
        }
    }
};

void Game::setMap(int order){
    map.setMap(order);

}
int  Game::getMapSize(){
    return map.getMapSize();
}
void Game::modeChange(int mode){
    if(mode==1||mode==0) this->mode=mode;
}
int Game::getState(){
    return state;
}
void Game::drawEnd(){
    glColor3f(1.0f, 1.0f, 1.0f);

    std::string text = "YOU WIN!!";
    void *font = GLUT_BITMAP_TIMES_ROMAN_24;

    // 算出文字繪製開始的位置
    int textWidth = glutBitmapLength(font, (const unsigned char*)text.c_str());
    int x = (1920-textWidth) / 2;
    int y = 1080 / 2;

    // 繪製文字
    glRasterPos2i(x, y);
    for (char c : text) {
        glutBitmapCharacter(font, c);
    }

};
void Game::Restart(){
    px= 90;
    py =80;
    pa=0;
    pdx =0;
    pdy =0;
    
};
void Game::setState(int state){
    if(state==0||state==1)this->state=state;
};