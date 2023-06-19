#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
public:
    //intiialization , load map from data base , and there is a default map already inside it 
    Map();
    // help function ,told whether (x,y) a wall or floor or exit 
    int isWall(int x, int y) const;
    // get the width of current map 
    int getWidth() const { return map[order][0].size(); }
    // get the height of current map 
    int getHeight() const { return map[order].size(); }
    // choose map 
    void setMap(int order);
    // get how many map we have 
    int getMapSize();
    // by sqlite spec we need a static function , throw the problem to load function
    static int loadMap(void* data, int argc, char** argv, char** column);// return how many number of map found 
    // take care the data read from database 
    void load(int argc, char** argv, char** column);
private:
    std::vector<std::vector<std::vector<int>>> map;
    // current map we choose 
    int order=0;//default 
    int level_num=1;// default 
    // read from database , and take care them by load function 
    int loadAllMap();
};

#endif  // MAP_H
