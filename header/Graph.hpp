//
// Created by tieu on 8/12/2021.
//

#ifndef MST_SFML_GRAPH_HPP
#define MST_SFML_GRAPH_HPP

#include <vector>
#include <forward_list>
#include <Node.hpp>
#include "Edge.hpp"

class Graph : public sf::Drawable {
public:
    Graph(sf::Color color = sf::Color::Blue);

    const std::vector<Edge> &getEdge() const;

    void addEdge(Edge otherEdge);

    void addEdge(const Node& node1, const Node& node2, int weight);

    int getNumberOfNode() const;

    void print();

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

private:
    //auto increase as list expands and edges added
    int numberOfNode; //needed for union find and kruskal

    std::vector<Edge> edge;

    std::vector<std::vector<int>> adjacencyList;

    bool hasCreatedThisEdge(const Node& node1, const Node& node2);

    void expandList(const Node& node);

    sf::Color color;


};


#endif //MST_SFML_GRAPH_HPP
