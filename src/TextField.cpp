//
// Created by tieu on 8/14/2021.
//

#include <iostream>
#include "TextField.hpp"


TextField::TextField(const sf::Font& font, sf::Color color, int x, int y,
                     const std::string& someText, int width, int height) : x(x), y(y){
    shape.setPosition(x, y);
//    shape.setOrigin(width / 2, height / 2);
    shape.setFillColor(color);
    shape.setSize(sf::Vector2f(width, height));

    text.setFont(font);
    text.setCharacterSize(SMALL);
    text.setString(someText);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
//    text.setOrigin(width / 2, height / 2);
//    text.setOutlineColor(sf::Color::Black);
//    text.setOutlineThickness(2.f);

}

void TextField::setText(const std::string& newText) {
    text.setString(newText);
}

void TextField::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    if (x != Node::UNDEFINED && y != Node::UNDEFINED) {
        target.draw(shape);
        target.draw(text);
    }

}

void TextField::setPosition(int x, int y) {
    TextField::x = x;
    TextField::y = y;

    shape.setPosition(x, y);
    text.setPosition(x, y);
}

void TextField::clear() {
    x = Node::UNDEFINED;
    y = Node::UNDEFINED;
}

