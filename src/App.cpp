#include "App.h"

using namespace std;
App::App()
{
    initVariables();
    initWindow();
    initText();
    spawnBlocks();
}

App::~App()
{
    delete this->window;
}
void App::initVariables()
{
    vidMode.height = 600;
    vidMode.width = 600;
    sizeOfTable = 30;
    for(int i=0;i<sizeOfTable;i++)
    {
        tableForSorting.push_back(i+1);
    }
    std::random_shuffle(tableForSorting.begin(),tableForSorting.end());
}
void App::initWindow()
{
    this->window = new sf::RenderWindow(vidMode,"idk yet");
    this->window->setFramerateLimit(60);
}
void App::render()
{
    this->window->clear();

    renderText();
    //renderBlocks();


    this->window->display();
}
void App::update()
{
    pollEvents();
    checkClick();
}
const bool App::isRunning() const
{
    return this->window->isOpen();
}
void App::pollEvents()
{
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window->close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->window->close();
    }
}
void App::renderBlocks()
{
    for(auto b:blocks)
        b.render(this->window);
}
void App::spawnBlocks()
{
   // int notOnScreen=0;
    for(int i=0;i<sizeOfTable;i++)
    {
        Block block;
        block.setSize(block.getSize().x,block.getSize().y+tableForSorting[i]*10);
        block.setPosition(i*block.getSize().x,vidMode.height-block.getSize().y);
       // if(block.getPosition().x > vidMode.width || block.getPosition().x < 0)
           // notOnScreen++;

        blocks.push_back(block);
        //cout<<"Block:"<<i+1<<" "<<blocks[i].getSize().y<<'\n';
    }
    //cout <<"notOnScreen:"<< notOnScreen<<'\n';

}
void App::mergeSort()
{
    cout<<"DUPA";
    exit(EXIT_FAILURE);
}
void App::selectionSort()
{

}
void App::insertionSort()
{

}
void App::quickSort()
{

}
void App::loadFont()
{
    if(!font.loadFromFile("c.ttf"))
    {
        cout<<"CAN'T LOAD FONT";
        exit(EXIT_FAILURE);
    }
}
void App::initText()
{
    int characterSize = 15;
    loadFont();
    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);
    text4.setFont(font);

    text1.setCharacterSize(characterSize);
    text2.setCharacterSize(characterSize);
    text3.setCharacterSize(characterSize);
    text4.setCharacterSize(characterSize);

    text1.setString("MERGE SORT");
    text2.setString("SELECTION SORT");
    text3.setString("INSERTION SORT");
    text4.setString("QUICK SORT");

    text1.setPosition(10,10);
    text2.setPosition(310,10);
    text3.setPosition(10,40);
    text4.setPosition(310,40);


}
void App::renderText()
{
    this->window->draw(text1);
    this->window->draw(text2);
    this->window->draw(text3);
    this->window->draw(text4);
}
void App::checkClick()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&(text1.getGlobalBounds().contains(mousePos.x,mousePos.y)))
    {
        text1.setCharacterSize(7);
        text2.setCharacterSize(7);
        text3.setCharacterSize(7);
        text4.setCharacterSize(7);
    }
}
