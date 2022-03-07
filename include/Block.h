#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Graphics.hpp>

class Block
{
    public:
        Block();
        //virtual ~Block();
        void render(sf::RenderTarget *target);
        void setPosition(float x,float y);
        void setSize(float width,float height);
        void setColor(int r,int g,int b);
        sf::Vector2f getSize();
        sf::Vector2f getPosition();

    private:
        sf::RectangleShape shape;
        void initShape();

};

#endif // BLOCK_H
