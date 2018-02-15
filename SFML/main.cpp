#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
    sf::CircleShape shape(600.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();		//These function calls make the window appear
        window.draw(shape);
        window.display();
    }

    return 0;
}

/*
sf::VideoMode(x,y) sets the window dimensions
the constructor for sf::CircleShape takes a parameter which is the circle's radius: shape(600.f);

*/
