//
// Created by tieu on 8/14/2021.
//

#ifndef KRUSKAL_SFML_TEXTFIELD_HPP
#define KRUSKAL_SFML_TEXTFIELD_HPP

#include <SFML/Graphics.hpp>
#include <Node.hpp>


class TextField : public sf::Drawable {
public:
    static const int SMALL = 20;
    static const int BIG = 30;

    TextField(const sf::Font& font, sf::Color color = sf::Color::Transparent,
              int x = Node::UNDEFINED, int y = Node::UNDEFINED,
              const std::string& someText = "",
              int width = SMALL, int height = SMALL);

    void setText(const std::string& newText);

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    void setPosition(int x, int y);

    void clear();

private:
    sf::RectangleShape shape;
    int x;
    int y;
    sf::Text text;




};


#endif //KRUSKAL_SFML_TEXTFIELD_HPP
