//
// Created by tieu on 8/12/2021.
//

#include "Edge.hpp"

#include <utility>
#include <Edge.hpp>
#include <iostream>

/**
 * To create an edge with given vertex and weight, and color (optional).
 * @param node two vertices, order doesnt matter
 * @param weight positive
 * @param color is the color of the line
 */
Edge::Edge(std::pair<Node, Node> node, int weight, sf::Color color) : node(std::move(node)), weight(weight) {
    line.setStartPoint(node.first.getX() + Node::SIZE_NODE / 2,
                       node.first.getY() + Node::SIZE_NODE / 2);
    line.setEndPoint(node.second.getX() + Node::SIZE_NODE / 2,
                     node.second.getY() + Node::SIZE_NODE / 2);
    setColor(color);

    weightText.setCharacterSize(20);
    weightText.setString(std::to_string(weight));
    weightText.setOutlineColor(sf::Color::Black);
    weightText.setOutlineThickness(5.f);
    weightText.setFillColor(sf::Color::White);
    weightText.setPosition((node.first.getX() + node.second.getX()) / 2,
                           (node.first.getY() + node.second.getY()) / 2);
}

const std::pair<Node, Node> &Edge::getNode() const {
    return node;
}

int Edge::getWeight() const {
    return weight;
}

bool Edge::operator > (const Edge &otherEdge) const {
    return (getWeight() > otherEdge.getWeight());
}

void Edge::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    target.draw(line);
    //if font isn't set -> nothing display, no error
    target.draw(weightText);
    target.draw(node.first);
    target.draw(node.second);
}

/**
 * Such pain to setFont whenever an edge is created.
 * Two instructions must be together is troublesome
 * But if add font to Edge constructor -> more trouble
 * @param font
 */
void Edge::setFont(const sf::Font &font) {
    weightText.setFont(font);
}

void Edge::setColor(sf::Color color) {
    line.setColor(color);
}
