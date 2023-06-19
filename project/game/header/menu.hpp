#ifndef MENU_H
#define MENU_H

class Menu{
public:
    //set up all menu relation 
    Menu();
    // main menu and it's option 
    enum MenuOptions {
        SETTING,
        RESTART,
        EXIT
    };
    static void mainMenu(int option);
    // set  menu and it's option 
    enum setting{
        COLOR,
        RAY_NUM,
        DEG
    };
    static void settingOption(int option);
   // set  color menu and it's option 
    enum Color {
        RED,
        BLUE,
        GREEN
    };
    static void ColorOption(int option);
// set degree menu and it's option 
    enum DEGREE {
        DEG_70,
        DEG_80,
        DEG_90
    };
    static void DegOption(int option);
    // set numer of ray casting  menu and it's option 
    enum NUM {
        NUM_150,
        NUM_200,
        NUM_400
    };
    static void NumOption(int option) ;
    // set  map menu and it's option 
    static void MapOption(int option);
    // set  mode  menu and it's option 
    enum{
        NORMAL,
        CHEAT
    };
    static void ModOption(int option);
};

#endif
