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

// select the font
    text.setFont(font); // font is a sf::Font

// set the string to display
    text.setString("Hello world");

// set the character size
    text.setCharacterSize(24); // in pixels, not points!

// set the color
    text.setFillColor(sf::Color::Red);

// set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
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
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        int x = event.mouseButton.x;
                        int y = event.mouseButton.y;

                        text.setPosition(x, y);

                        //if mouse clicks at blank
                        if (mouseInsideNode(x, y) == Node::UNDEFINED) {
                            std::cout << "create node " << count << " at x = " << x << " y = " << y << std::endl;

                            tempNode.emplace_back(Node(count, font, x, y));
//                        tempNode.emplace_back(text);
                            count += 1;
                        } else {
                            std::cout << "node is already created" << std::endl;
                        }



                    }
                default:
                    break;
            }
        }

        for (const auto & i : tempNode) {
            window.draw(i);

        }

//        window.draw(text);

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
int Start::mouseInsideNode(int mouseX, int mouseY) {
    for (Node &n : tempNode) {
        if (n.getX() <= mouseX && mouseX <= n.getX() + Node::SIZE_NODE
            && n.getY() <= mouseY && mouseY <= n.getY() + Node::SIZE_NODE) {
            std::cout << "mouse is inside node " << n.getData() << std::endl;
            return n.getData();
        }
    }
    std::cout << "mouse is outside" << std::endl;
    return Node::UNDEFINED;
}

