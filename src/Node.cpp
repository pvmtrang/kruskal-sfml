//
// Created by tieu on 8/12/2021.
//

#include <iostream>
#include "Node.hpp"

/**
 * This is only for the creation of temporary, unnecessary node.
 * This kind of node can't be drawn on the window
 */
Node::Node() : data(UNDEFINED), x(UNDEFINED), y(UNDEFINED){}

/**
 * To create a node with given data and coordination
 * @param font is for rendering the number - the data
 * @param data
 * @param x
 * @param y
 */
Node::Node(const sf::Font& font, int data, int x, int y) : data(data), x(x), y(y) {
    shape.setSize(sf::Vector2f(SIZE_NODE, SIZE_NODE));
    shape.setFillColor(sf::Color::Blue);
    shape.setOutlineThickness(SIZE_BORDER);
    shape.setOutlineColor(sf::Color::White);

    setPosition(x, y);

    text.setFont(font);
    text.setString(std::to_string(data));
    text.setCharacterSize(SIZE_NODE * 2 / 3);

}

int Node::getData() const {
    return data;
}

/**
 * Change position of a node -> change position of the shape and the guidelineText also
 * @param posX
 * @param posY
 * Perhaps this is not necessary because it's only used in constructor??
 * Why is it here the first place? :D
 */
void Node::setPosition(int posX, int posY){
    this->x = posX;
    this->y = posY;

    shape.setPosition(x, y);

    //chinh bua de cho guidelineText in the middle thoi
    text.setPosition(x + SIZE_NODE / 3, y);
}

int Node::getX() const {
    return x;
}

int Node::getY() const {
    return y;
}

/**
 * To render node (shape + guidelineText+ on screen.
 * Only temporary node (created with no argument constructor) has UNDEFINED coordinate??
 * @param target
 * @param state
 */
void Node::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    if (x == UNDEFINED || y == UNDEFINED) { //change to throw exception later
        std::cout << "cant draw this node with undefined position" << std::endl;
        return;
    }

    target.draw(shape);
    target.draw(text);
}

bool Node::isUndefined() {
    return data == UNDEFINED && x == UNDEFINED && y == UNDEFINED;
}

void Node::clear() {
    data = UNDEFINED;
    x = UNDEFINED;
    y = UNDEFINED;
}

bool Node::operator==(const Node &rhs) const {
    return data == rhs.data;
}

bool Node::operator!=(const Node &rhs) const {
    return !(rhs == *this);
}






