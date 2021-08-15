//
// Created by tieu on 8/12/2021.
//

#include "Edge.hpp"

#include <utility>
#include <Edge.hpp>
#include <iostream>


Edge::Edge(std::pair<Node, Node> node, int weight) : node(std::move(node)), weight(weight) {
    if (node.first != node.second) {
        line.setStartPoint(node.first.getX() + Node::SIZE_NODE / 2,
                           node.first.getY() + Node::SIZE_NODE / 2);
        line.setEndPoint(node.second.getX() + Node::SIZE_NODE / 2,
                         node.second.getY() + Node::SIZE_NODE / 2);
        isFontSet = false;
        //chua xet font o day -> bot 1 argument trong constructor
        weightText.setCharacterSize(20);
        weightText.setString(std::to_string(weight));
        weightText.setOutlineColor(sf::Color::Black);
        weightText.setOutlineThickness(5.f);
        weightText.setFillColor(sf::Color::White);
        weightText.setPosition((node.first.getX() + node.second.getX()) / 2,
                               (node.first.getY() + node.second.getY()) / 2);
    } else {
        std::cout << "No self connect edge allowed" << std::endl;
    }

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

//phai setFont moi khi tao mot edge?? -> phien
//nhung neu them font vao constructor thi o trong graph cung phai them font
void Edge::setFont(const sf::Font &font) {
    Edge::font = font;
    isFontSet = true;
    weightText.setFont(font);

    std::cout << "set font for edge" << std::endl;
}
