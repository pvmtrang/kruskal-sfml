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
    static const int UNDEFINED = -1;

    Node();

    Node(const sf::Font& font, int data = UNDEFINED, int x = UNDEFINED, int y = UNDEFINED);

    int getData() const;

    void setPosition(int posX, int posY);

    int getX() const;

    int getY() const;

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    bool isUndefined();

    void clear();

    bool operator==(const Node &rhs) const;

    bool operator!=(const Node &rhs) const;


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
