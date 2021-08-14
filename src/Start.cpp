//
// Created by tieu on 8/13/2021.
//

#include <iostream>
#include <fstream>
#include "Start.hpp"

//why does it work?? font hasnt been loaded yet???? should read more about constructor
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

Start::Start(std::string filePath) {
    readGraphFromFile(filePath);
    window.create(sf::VideoMode(800, 600), "title");
    count = 0;

}

void Start::loop() {
    std::cout << "start the loop" <<std::endl;
    while (window.isOpen()) {
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
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        int x = event.mouseButton.x;
                        int y = event.mouseButton.y;

                        Node clickedNode = mouseInsideNode(x, y);

                        //if mouse clicks at blank -> create node
                        if (clickedNode.isUndefined()) {

                            tempNode.emplace_back(Node(font, count, x, y));

                            tempLine.clear();
                            isDrawingLine = false;
//                            textField.clear();
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
//khong thich cai nay lam vi phai thoat ra bam vao terminal xong lai quay lai
                                int weight;
                                std::cout << "ENTER EDGE WEIGHT: ";
                                std::cin >> weight;

//                                textField.setPosition((startLine.getX() + endLine.getX()) / 2,
//                                                      (startLine.getY() + endLine.getY()) / 2);
//                                textField.setString(std::to_string(weight));
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
                case sf::Event::MouseMoved: {
                    tempLine.setEndPoint(event.mouseMove.x, event.mouseMove.y);
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

        window.draw(textField);

        window.draw(graph);


        window.display();
    }
}

//shit. This is useless because doesnt have node's position
void Start::readGraphFromFile(const std::string& filePath) {
    std::cout << "reading graph from file" << std::endl;
    std::ifstream file(filePath);
    std::string line;
    bool isFirstLine = true;

    while (std::getline(file, line)) {
        //the first line contains the number of node
        if (isFirstLine) {
            std::string tmp = "";
            for (char i : line) {
                tmp += i;
                if (i == ' ') { //just in case
                    break;
                }
            }
            int numberOfNode = std::stoi(tmp);
            std::cout << "number of nodes: " << numberOfNode << std::endl;
            graph = Graph(numberOfNode);
            isFirstLine = false;
        } else {
            std::vector<int> tmpEdge;
            for (int i = 0; i < line.size(); i++) {
                switch (line[i]) {
                    case ' ':
                        break;
                    default: {// if not space, i.e it is number
                        std::string tmp; // in case it has more than one digit
                        tmp += line[i];
                        for (int j = i + 1; j < line.size(); j++) {
                            if (line[j] == ' ') {
                                break;
                            } else {
                                tmp += line[j];
                            }
                        }
                        tmpEdge.emplace_back(std::stoi(tmp));
                    }

                }
            }
            //tam xoa di vi doi Node constructor
//            graph.addEdge(Node(tmpEdge[0]), Node(tmpEdge[1]), tmpEdge[2]);
            std::cout << "create edge from " << tmpEdge[0] << " to " << tmpEdge[1] << " weight " << tmpEdge[2] << std::endl;
        }
    }

    std::cout << "print graph" << std::endl;
    graph.print();

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

