//
// Created by tieu on 8/13/2021.
//

#ifndef KRUSKAL_SFML_START_HPP
#define KRUSKAL_SFML_START_HPP


#include <SFML/Graphics.hpp>
#include <Graph.hpp>
#include "Line.hpp"
#include "Kruskal.hpp"


class Start {
public:
    static const int SPEED_HIGH = 60;
    static const int SPEED_LOW = 5;

    Start();

    void loop();

    const Graph &getGraph() const;


private:
    /// to count and give corresponding data to nodes created
    int countNodeCreated;

    sf::RenderWindow window;

    Graph graph;

    Kruskal kruskal;

    /// to store all nodes that are created on the screen
    std::vector<Node> tempNode;

    sf::Font font;

    Node mouseInsideNode(int mouseX, int mouseY);

    /// to store the current drawing line on screen
    Line tempLine;

    bool isDrawingLine;

    /// the node where tempLine starts
    Node startLine;

    /// the node where tempLine ends
    Node endLine;

    sf::Text guidelineText;

    void handleInput();

    void drawAll();

    void handleDrawing(sf::Event &event);


};


#endif //KRUSKAL_SFML_START_HPP
