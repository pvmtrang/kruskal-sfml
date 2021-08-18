//
// Created by tieu on 8/13/2021.
//

#include <iostream>
#include <fstream>
#include "Start.hpp"

Start::Start() {
    window.create(sf::VideoMode(800, 600), "Krrrrrrrruskal");

    countNodeCreated = 0;

    font.loadFromFile("assets/font/Abel-Regular.ttf");

    isDrawingLine = false;

    guidelineText.setFont(font);
    guidelineText.setCharacterSize(20);
    guidelineText.setString("Click any where to create a node. \n"
                            "Click on a node to start or end a line. "
                            "Re-click on the start node to delete a line.\n"
                            "Assign weight to edge on the Run tool window.\n"
                            "Press Space to start finding MST by Kruskal.\n");
    guidelineText.setFillColor(sf::Color::White);
    guidelineText.setOutlineColor(sf::Color::Red);
    guidelineText.setOutlineThickness(1.f);
}


void Start::loop() {
    std::cout << "start the loop" <<std::endl;
    while (window.isOpen()) {
        window.setFramerateLimit(SPEED_HIGH);
        window.clear(sf::Color::Black);

        handleInput();

        drawAll();
    }
}


/**
 * Check if mouse is clicking on any existed node.
 * @param mouseX the x position of mouse click
 * @param mouseY the y position of mouse click
 * @return the data/id of node if mouse clicks on a node
 *        else return undefined value
 */
Node Start::mouseInsideNode(int mouseX, int mouseY) {
    for (Node &n : tempNode) {
        if (n.getX() <= mouseX && mouseX <= n.getX() + Node::SIZE_NODE
            && n.getY() <= mouseY && mouseY <= n.getY() + Node::SIZE_NODE) {
            std::cout << "mouse is inside node " << n.getData() << std::endl;
            return n;
        }
    }
    std::cout << "mouse is outside" << std::endl;
    return Node();
}

void Start::handleInput() {
    sf::Event event{};

    while (window.pollEvent(event)) {
        // Window closed
        switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    std::cout << "PRINT GRAPHHHHHH" << std::endl;
                    graph.print();
                    guidelineText.setString(guidelineText.getString() + "Finding MST...");
                    kruskal.setGraph(getGraph());
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    handleDrawing(event);
                }
                break;
            case sf::Event::MouseMoved: {
                tempLine.setEndPoint(event.mouseMove.x, event.mouseMove.y);
                break;
            }
            default:
                break;
        }
    }
}

void Start::drawAll() {
    window.draw(tempLine);

    for (const auto & i : tempNode) {
        window.draw(i);
    }

    window.draw(guidelineText);

    window.draw(graph);

    if (kruskal.isGraphSet) {
        window.setFramerateLimit(SPEED_LOW);
        kruskal.findMST();
        window.draw(kruskal);
    }

    window.display();
}

void Start::handleDrawing(sf::Event &event) {
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    //khong hieu sao < 0 duoc ay, chon related to window roi ma
    if (x >= 0 && y >= 0) {
        Node clickedNode = mouseInsideNode(x, y);

        //if mouse clicks at blank -> create node
        if (clickedNode.isUndefined()) {
            tempNode.emplace_back(Node(font, countNodeCreated, x, y));
            std::cout << "CREATED NODE " << countNodeCreated << " at x=" << x
                      << " y=" << y << std::endl;
            countNodeCreated += 1;
            tempLine.clear();
            isDrawingLine = false;

        } else { //if mouse click on a node -> create edge
            if (!isDrawingLine) { // if no line created yet aka click the first node
                tempLine.setStartPoint(x, y);
                isDrawingLine = true;
                startLine = clickedNode;

                //if there is a line started from some node aka click on node the second time
                //-> complete the edge
            } else {
                endLine = clickedNode;
                if (startLine == endLine) {
                    std::cout << "self connected a? " << std::endl;
                    isDrawingLine = false;
                    tempLine.clear();
                    return;
                }
//khong thich cai nay lam vi phai thoat ra bam vao terminal xong lai quay lai
                int weight;
                do {
                    std::cout << "ENTER POSITIVE EDGE WEIGHT:";
                    std::cin >> weight;
                } while (weight <= 0);

                //phai tao duoc edge o cho nay co
                Edge tmpEdge(std::pair(startLine, endLine), weight);
                tmpEdge.setFont(font);

                graph.addEdge(tmpEdge);

                //finish drawing a line - creating an edge
                isDrawingLine = false;

                tempLine.clear();
            }
        }
    }
}

const Graph &Start::getGraph() const {
    return graph;
}



