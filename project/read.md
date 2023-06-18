# raycasting maze
## directory 
```
├── header
│   ├── button.hpp
│   ├── game.hpp
│   ├── map.hpp
│   ├── menu.hpp
│   ├── sprite.hpp
│   ├── texture.hpp
│   └── window.hpp
├── others
│   └── map.sqlite
└── src
    ├── game
    ├── game.cpp
    ├── main.cpp
    ├── makefile
    ├── map.cpp
    ├── menu.cpp
    ├── texture.cpp
    └── window.cpp
```
## Introduce
This is a simple maze escape OOP game made by ray casting algorithm.
[what is raycasting ?](https://en.wikipedia.org/wiki/Ray_casting)
## needed
This program use glut and sqlite,rememeber to download them before you use it 
```
yay -S freeglut sqlite3
```
## compile 
remember to download
```
yay -S automake
cd src 
make 
```
## some sqlite code 
```sqlite
// delete all element in table
DELETE FROM Maps;  
//delete table
Drop TABLE Maps;
// create table 
CREATE TABLE Maps(
    MapID INT,
    Y INT,
    Row TEXT
); 
//first example map
INSERT INTO Maps VALUES 
(1, 0, '11111111'),
(1, 1, '10110001'),
(1, 2, '10010101'),
(1, 3, '11000001'),
(1, 4, '10011101'),
(1, 5, '11010101'),
(1, 6, '10010001'),
(1, 7, '11111111');
//second example map
INSERT INTO Maps VALUES 
(2, 0, '111111111111111111'),
(2, 1, '100000101000100001'),
(2, 2, '101111101110101101'),
(2, 3, '201000100010001001'),
(2, 4, '101110111011111011'),
(2, 5, '101010000000000001'),
(2, 6, '101000010111111001'),
(2, 7, '101111010010001001'),
(2, 8, '100010011010101001'),
(2, 9, '101110101010101011'),
(2, 10,'101010101010101001'),
(2, 11,'100010101010101101'),
(2, 12,'101010101010100001'),
(2, 13,'101010101010100011'),
(2, 14,'101010101010101001'),
(2, 15,'101010101111101101'),
(2, 16,'101000100000000001'),
(2, 17,'111111111111111111');
```

## 評分
### 基本系統功能 (60%)
- 只要有demo，就有 60 分
### 其他評分依據(40%)
- 有寫完整註解 (5%)
- Android APP / GUI (10%)
- 有打包成執行檔(jar/exe)  (5%)
- Package規劃 (5%) 
- 有用資料庫(SQLite也可) (10%)
- PPT (5到10頁，不包含標題頁跟結尾頁) (5%)
- Report  必交，否則從已得分數中倒扣 10 分