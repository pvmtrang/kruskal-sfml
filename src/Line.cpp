//
// Created by tieu on 8/13/2021.
//

#include <cmath>
#include <valarray>
#include <iostream>
#include "Line.hpp"


Line::Line(int startX, int startY, int endX, int endY, sf::Color color)
            : startX(startX), startY(startY), endX(endX), endY(endY) {
    shape.setFillColor(color);
    resizeShape();
}

void Line::setStartPoint(int startX, int startY) {
    Line::startX = startX;
    Line::startY = startY;
    resizeShape();
}

void Line::setEndPoint(int endX, int endY) {
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

/**
 * To resize the line as the mouse moves.
 * Recalculate the length with mouse current position
 * Recalculate the angle to rotate line
 * Use setRotation, not rotate
 */
void Line::resizeShape() {
    shape.setPosition(startX, startY);
    int width = endX - startX;
    int height = endY - startY;
    double length = sqrt(width * width * 1.0 + height * height);
    shape.setSize(sf::Vector2f(length, LINE_THIN));

    shape.setRotation(calculateAngle(width, length));

}
/**
 * To calculate the corresponding angle as the mouse moves.
 *  _width_
 * |\ a  |
 * | \ l |
 * |  \  |
 * |   \ height
 * |----\|
 * l is the current length of line
 * width height is the corresponding measuremnts of the outbox
 * angle is between width and length
 * @param width
 * @param length
 * @return +angle if the line is under the width, -angle if above
 */
double Line::calculateAngle(int width, double length) const {
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






