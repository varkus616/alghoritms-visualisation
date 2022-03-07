#ifndef APP_H
#define APP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <windows.h>
#include "Block.h"
class App
{
    public:

        App();
        virtual ~App();
        void render();
        void update();
        const bool isRunning() const;
        void initWindow();

    private:

        int choice;
        int sizeOfTable;

        sf::RenderWindow *window;
        sf::VideoMode vidMode;
        sf::Event event;

        sf::Font font;
        sf::Text text1,text2,text3,text4;

        std::vector<Block>blocks;
        std::vector<int>tableForSorting;

        void initVariables();
        void initText();
        void renderText();
        void pollEvents();
        void spawnBlocks();
        void renderBlocks();
        void mergeSort();
        void insertionSort();
        void quickSort();
        void selectionSort();
        void loadFont();
        void checkClick();


};

#endif // APP_H
