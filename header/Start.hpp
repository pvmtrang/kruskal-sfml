//
// Created by tieu on 8/13/2021.
//

#ifndef KRUSKAL_SFML_START_HPP
#define KRUSKAL_SFML_START_HPP


#include <SFML/Graphics.hpp>
#include <Graph.hpp>
#include "Line.hpp"
#include "../src/TextField.hpp"
#include "Kruskal.hpp"


class Start {
public:
    Start();

    void loop();

    const Graph &getGraph() const;


private:
    int count;

    sf::RenderWindow window;

    Graph graph;

    std::vector<Node> tempNode;
//    std::vector<sf::Text> tempNode;

    sf::Font font;

    sf::Text text;

    Node mouseInsideNode(int mouseX, int mouseY);

    Line tempLine;

    bool isDrawingLine;

    Node startLine;

    Node endLine;

    sf::Text textField;

    Kruskal kruskal;

};


#endif //KRUSKAL_SFML_START_HPP
