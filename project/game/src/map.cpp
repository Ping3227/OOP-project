#include "../header/map.hpp"
#include <sqlite3.h>
#include <iostream>
Map::Map() {
    // for sure that if there are any of map been read , set a default map 
    map = {
        {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 1, 0, 0, 0, 2},
            {1, 0, 0, 1, 0, 0, 0, 1},
            {1, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        }
    };
    loadAllMap();
}
// help function tell whether end point wall , or floor 
int  Map::isWall(int x, int y) const {
    if (x < 0 || y < 0 || y >= map[order].size() || x >= map[order][y].size())
        return 1; // Out of bounds
    return map[order][y][x] ;
}
// set the map ,we currenlty selelect now 
void Map::setMap(int order){
    if(order >= 0 && order < map.size()) this->order =order;;
    return;
}
/// need a static function , so use this function to recall a real function to load database 
int Map::loadMap(void* data, int argc, char** argv, char** column) {
    Map* mapPtr = static_cast<Map*>(data);
    mapPtr->load(argc,argv,column);
    return 0;
}


// load every map from database 
int Map::loadAllMap(){
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open("../others/map.sqlite", &db);

    if(rc){
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    std::string sql = "SELECT * FROM Maps;";
    rc = sqlite3_exec(db, sql.c_str(), Map::loadMap, this, &zErrMsg);

    if(rc != SQLITE_OK){
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);

    return rc;
}

// get how many map we have 
int Map::getMapSize(){
    return map.size();
};
// help function take care all the value read from database 
void Map::load(int argc, char** argv, char** column){
    int map_id = std::stoi(argv[0]);
    int y = std::stoi(argv[1]);
    std::string row = argv[2];

    // 將行數據分解為單獨的格子值
    if(map_id !=0 &&y==0) map.push_back(std::vector<std::vector<int>>{});
    map[map_id].push_back(std::vector<int>{});
    for(int x = 0; x < row.size(); x++) {
        int value = row[x] - '0';
        map[map_id][y].push_back(value);

    }
}