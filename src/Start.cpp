//
// Created by tieu on 8/13/2021.
//

#include <iostream>
#include <fstream>
#include "Start.hpp"

Start::Start() {
    window.create(sf::VideoMode(800, 600), "title");
    count = 0;

    font.loadFromFile("assets/font/Abel-Regular.ttf");

    isDrawingLine = false;
    textField.setFont(font);
    textField.setString("initial string");
    textField.setFillColor(sf::Color::White);
    textField.setOutlineColor(sf::Color::Red);
    textField.setOutlineThickness(5.f);

}


void Start::loop() {
    std::cout << "start the loop" <<std::endl;
    while (window.isOpen()) {
        window.setFramerateLimit(SPEED_HIGH);
        window.clear(sf::Color::Black);

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
                        kruskal.setGraph(getGraph());
                    }
                    break;
//xem lai xem nen get mouse button relative to window or to screen
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        int x = event.mouseButton.x;
                        int y = event.mouseButton.y;

                        //khong hieu sao < 0 duoc ay, chon related to window roi ma
                        if (x >= 0 && y >= 0) {
                            Node clickedNode = mouseInsideNode(x, y);

                            //if mouse clicks at blank -> create node
                            if (clickedNode.isUndefined()) {
                                tempNode.emplace_back(Node(font, count, x, y));
                                std::cout << "CREATED NODE " << count << "at x=" << x << " y=" << y << std::endl;

                                tempLine.clear();
                                isDrawingLine = false;
                                textField.setString("");

                                count += 1;
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
                                        break;
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
                case sf::Event::MouseMoved: {
                    tempLine.setEndPoint(event.mouseMove.x, event.mouseMove.y);
//                    std::cout << "mouse at x = " << event.mouseMove.x << " y = " << event.mouseMove.y << std::endl;
                    break;
                }
// định cho text hiện ngay ra màn hình để gõ xong thấy luôn thay vì gõ vào terminal
// nhưng chưa nghĩ ra
                /*case sf::Event::TextEntered: {
                    if (48 <= event.text.unicode && event.text.unicode <= 57) {
                        std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                        int weight = static_cast<char>(event.text.unicode) - '0';
                        if (!startLine.isUndefined() && !endLine.isUndefined()) {
                            textField.setString(std::to_string(weight));
                            textField.setPosition((startLine.getX() + endLine.getX()) / 2,
                                                  (startLine.getY() + endLine.getY()) / 2);

                            graph.addEdge(startLine, endLine, weight);

                            startLine.clear();
                            endLine.clear();
                        }

                    }
                }*/
                default:
                    break;
            }
        }

        window.draw(tempLine);



        for (const auto & i : tempNode) {
            window.draw(i);
        }

//        std::cout << "count = " << count << std::endl;

        window.draw(textField);

        window.draw(graph);

        if (kruskal.isGraphSet) {
            window.setFramerateLimit(SPEED_LOW);
            kruskal.findMST();
            window.draw(kruskal);
        }

        window.display();
    }
}


const Graph &Start::getGraph() const {
    return graph;
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

