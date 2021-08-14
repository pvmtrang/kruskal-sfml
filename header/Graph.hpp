//
// Created by tieu on 8/12/2021.
//

#ifndef MST_SFML_GRAPH_HPP
#define MST_SFML_GRAPH_HPP

#include <vector>
#include <forward_list>
#include <Node.hpp>
#include "Edge.hpp"

class Graph  : public sf::Drawable {
public:
    Graph(int numOfNode = 0);

    void readGraphFromFile(std::string filePath);

    const std::vector<Edge> &getEdge() const;

    void addEdge(Edge otherEdge);

    void addEdge(Node node1, Node node2, int weight);

    int getNumberOfNode() const;

    void print();

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

private:
    int numberOfNode;

    std::vector<Edge> edge;


};


#endif //MST_SFML_GRAPH_HPP
