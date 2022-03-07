#include "Block.h"

Block::Block()
{
    initShape();
}
void Block::initShape()
{
    shape.setSize(sf::Vector2f(20.f,20.f));
    //shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(0.5f);
}
void Block::render(sf::RenderTarget *target)
{
    target->draw(shape);
}
void Block::setPosition(float x,float y)
{
    shape.setPosition(x,y);
}
void Block::setSize(float width,float height)
{
    shape.setSize(sf::Vector2f(width,height));
}
void Block::setColor(int r,int g,int b)
{
    shape.setFillColor(sf::Color(r,g,b));
}
sf::Vector2f Block::getSize()
{
    return shape.getSize();
}
sf::Vector2f Block::getPosition()
{
    return shape.getPosition();
}
