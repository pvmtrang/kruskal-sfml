//
// Created by tieu on 8/12/2021.
//

#include "Edge.hpp"

#include <utility>
#include <Edge.hpp>


Edge::Edge(std::pair<Node, Node> node, int weight) : node(std::move(node)), weight(weight) {}

const std::pair<Node, Node> &Edge::getNode() const {
    return node;
}

int Edge::getWeight() const {
    return weight;
}

bool Edge::operator > (const Edge &otherEdge) const {
    return (getWeight() > otherEdge.getWeight());
}
