//
// Created by tieu on 8/12/2021.
//

#ifndef MST_SFML_EDGE_HPP
#define MST_SFML_EDGE_HPP


#include <Node.hpp>
#include <utility>
#include "Line.hpp"

class Edge : public sf::Drawable {
public:
    Edge(std::pair<Node, Node> node, int weight);

    const std::pair<Node, Node> &getNode() const;

    int getWeight() const;

    bool operator > (const Edge &otherEdge) const;

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    void setFont(const sf::Font &font);

private:
    std::pair<Node, Node> node;

    int weight;

    Line line;

    sf::Text weightText;

    sf::Font font;

    bool isFontSet;



};


#endif //MST_SFML_EDGE_HPP
