//
// Created by tieu on 8/13/2021.
//

#ifndef KRUSKAL_SFML_LINE_HPP
#define KRUSKAL_SFML_LINE_HPP


#include <SFML/Graphics.hpp>
#include <Node.hpp>

class Line : public sf::Drawable {
public:
    static const int LINE_THIN = 2;

//    Line();

    Line(int startX = Node::UNDEFINED, int startY = Node::UNDEFINED,
         int endX = Node::UNDEFINED, int endY= Node::UNDEFINED, int thickness = LINE_THIN);

    void setStartPoint(int startX, int startY);

    void setEndPoint(int endX, int endY);

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    double calculateAngle(int width, double length);

    void clear();


private:
    int startX;
    int startY;
    int endX;
    int endY;

    sf::RectangleShape shape;

    void resizeShape();


};


#endif //KRUSKAL_SFML_LINE_HPP
