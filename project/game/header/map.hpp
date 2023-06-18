#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
public:
    Map();
    int isWall(int x, int y) const;
    int getWidth() const { return map[order][0].size(); }
    int getHeight() const { return map[order].size(); }
    void setMap(int order);
    int getMapSize();
    static int loadMap(void* data, int argc, char** argv, char** column);// return how many number of map found 
    void load(int argc, char** argv, char** column);
private:
    std::vector<std::vector<std::vector<int>>> map;
    int order=0;//default 
   
    int level_num=1;// default 
    int loadAllMap();
};

#endif  // MAP_H
