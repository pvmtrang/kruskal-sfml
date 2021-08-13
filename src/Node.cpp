//
// Created by tieu on 8/12/2021.
//

#include <iostream>
#include "Node.hpp"

Node::Node(int data, const sf::Font& font, int x, int y) : data(data), x(x), y(y) {
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

void Node::setPosition(int posX, int posY){
    this->x = posX;
    this->y = posY;

    shape.setPosition(x, y);

    //chinh bua de cho text in the middle thoi
    text.setPosition(x + SIZE_NODE / 3, y);
}


void Node::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    if (x == UNDEFINED_COORD || y == UNDEFINED_COORD) { //change to throw exception later
        std::cout << "cant draw this node with undefined position" << std::endl;
        return;
    }

    //why it isnt allowed here??
//    shape.setPosition(x, y);

    target.draw(shape);
    target.draw(text);
}

