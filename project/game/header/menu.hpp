#ifndef MENU_H
#define MENU_H

class Menu{
public:
    Menu();

    enum MenuOptions {
        SETTING,
        RESTART,
        EXIT
    };
    static void mainMenu(int option);

    enum setting{
        COLOR,
        RAY_NUM,
        DEG
    };
    static void settingOption(int option);

    enum Color {
        RED,
        BLUE,
        GREEN
    };
    static void ColorOption(int option);

    enum DEGREE {
        DEG_70,
        DEG_80,
        DEG_90
    };
    static void DegOption(int option);

    enum NUM {
        NUM_150,
        NUM_200,
        NUM_400
    };
    static void NumOption(int option) ;
    static void MapOption(int option);
    enum{
        NORMAL,
        CHEAT
    };
    static void ModOption(int option);
};

#endif
