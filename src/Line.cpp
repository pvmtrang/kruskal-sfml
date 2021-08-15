//
// Created by tieu on 8/13/2021.
//

#include <cmath>
#include <valarray>
#include <iostream>
#include "Line.hpp"

/*Line::Line() {
    shape.setFillColor(sf::Color::White);
}*/

Line::Line(int startX, int startY, int endX, int endY, sf::Color color, int thickness)
            : startX(startX), startY(startY), endX(endX), endY(endY) {
    shape.setFillColor(color);
    resizeShape();

}

void Line::setStartPoint(int startX, int startY) {
//    std::cout << "reset line start point at x=" << startX <<" y=" << startY << std::endl;
    Line::startX = startX;
    Line::startY = startY;
    resizeShape();
}

void Line::setEndPoint(int endX, int endY) {
//    std::cout << "reset line end point at x=" << endX <<" y=" << endY << std::endl;
    Line::endX = endX;
    Line::endY = endY;
    resizeShape();
}

void Line::setColor(sf::Color color) {
    shape.setFillColor(color);
}

void Line::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    if (startX != Node::UNDEFINED && endX != Node::UNDEFINED) {
        target.draw(shape);
    }
}

void Line::resizeShape() {
    shape.setPosition(startX, startY);
    int width = endX - startX;
    int height = endY - startY;
    double length = sqrt(width * width * 1.0 + height * height);
    shape.setSize(sf::Vector2f(length, LINE_THIN));

    shape.setRotation(calculateAngle(width, length));

}

double Line::calculateAngle(int width, double length) {
    double cos = width * 1.0 / length;
    double angle = std::acos(cos) * 180 / M_PI;
    if (endY >= startY) {
        return angle;
    }
    return -angle;
}


void Line::clear() {
    startX = Node::UNDEFINED;
    startY = Node::UNDEFINED;
    endX = Node::UNDEFINED;
    endY = Node::UNDEFINED;

}






