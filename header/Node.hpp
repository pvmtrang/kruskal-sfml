//
// Created by tieu on 8/12/2021.
//

#ifndef MST_SFML_NODE_HPP
#define MST_SFML_NODE_HPP

#include <SFML/Graphics.hpp>


class Node : public sf::Drawable {
public:
    static const int SIZE_NODE = 30;
    static const int SIZE_BORDER = -2;
    static const int UNDEFINED_COORD = -1;

    Node(int data,const sf::Font& font, int x = UNDEFINED_COORD, int y = UNDEFINED_COORD);

    int getData() const;

    void setPosition(int posX, int posY);

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;


private:
    int data;

    //x is horizontal
    int x;
    //y is vertical
    int y;

    sf::RectangleShape shape;

    sf::Text text;

};


#endif //MST_SFML_NODE_HPP
