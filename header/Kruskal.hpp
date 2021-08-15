//
// Created by tieu on 8/12/2021.
//

#ifndef MST_SFML_KRUSKAL_HPP
#define MST_SFML_KRUSKAL_HPP


#include <Graph.hpp>
#include <UnionFind.hpp>

class Kruskal : public sf::Drawable {
public:
    Kruskal();

    Kruskal(const Graph &graph);

    void setGraph(const Graph &graph);

    void findMST();

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    bool isGraphSet;


private:
    Graph graph;

    Graph finalGraph;

    std::vector<Edge> edge;

    UnionFind unionFind;

    int numberOfAddedEdge;



};


#endif //MST_SFML_KRUSKAL_HPP
