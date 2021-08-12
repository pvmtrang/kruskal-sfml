//
// Created by tieu on 8/12/2021.
//

#ifndef MST_SFML_EDGE_HPP
#define MST_SFML_EDGE_HPP


#include <Node.hpp>
#include <utility>

class Edge {
public:
    Edge(std::pair<Node, Node> node, int weight);


    const std::pair<Node, Node> &getNode() const;

    int getWeight() const;

    bool operator > (const Edge &otherEdge) const;

private:
    std::pair<Node, Node> node;

    int weight;


};


#endif //MST_SFML_EDGE_HPP
