//
// Created by tieu on 8/12/2021.
//

#include "Edge.hpp"

#include <utility>
#include <Edge.hpp>
#include <iostream>


Edge::Edge(std::pair<Node, Node> node, int weight) : node(std::move(node)), weight(weight) {
    line.setStartPoint(node.first.getX() + Node::SIZE_NODE / 2,
                       node.first.getY() + Node::SIZE_NODE / 2);
    line.setEndPoint(node.second.getX() + Node::SIZE_NODE / 2,
                     node.second.getY() + Node::SIZE_NODE / 2);
    isFontSet = false;
    weightText.setFont(font);
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
    target.draw(weightText);
    target.draw(node.first);
    target.draw(node.second);
    /*if (isFontSet) {    //thuc ra neu chua set font thi no hien ra dau cham thoi
        target.draw(weightText);
    }*/
}

void Edge::setFont(const sf::Font &font) {
    Edge::font = font;
    isFontSet = true;
    weightText.setFont(font);

    std::cout << "set font for edge" << std::endl;
}
