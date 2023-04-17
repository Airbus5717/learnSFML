#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window{sf::VideoMode(200, 200), "CMake SFML Project"};
    // sf::RenderWindow window{{1080u, 640u}, "CMake SFML Project"};
    window.setFramerateLimit(144);
    sf::CircleShape circle{100.0f};
    circle.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }
}