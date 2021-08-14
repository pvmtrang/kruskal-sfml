//
// Created by tieu on 8/12/2021.
//

#include "Edge.hpp"

#include <utility>
#include <Edge.hpp>


Edge::Edge(std::pair<Node, Node> node, int weight) : node(std::move(node)), weight(weight) {
    line.setStartPoint(node.first.getX() + Node::SIZE_NODE / 2,
                       node.first.getY() + Node::SIZE_NODE / 2);
    line.setEndPoint(node.second.getX() + Node::SIZE_NODE / 2,
                     node.second.getY() + Node::SIZE_NODE / 2);
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
    target.draw(node.first);
    target.draw(node.second);
}
