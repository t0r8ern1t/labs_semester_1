#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), L"о нет ректанглсы побежали");

    sf::RectangleShape shape1(sf::Vector2f(150, 200));
    int posx1 = 700, posy1 = 212;
    shape1.setFillColor(sf::Color::Cyan);
    shape1.setPosition(posx1, posy1);
    shape1.setOrigin(75, 100);

    sf::RectangleShape shape2(sf::Vector2f(111, 50));
    shape2.setFillColor(sf::Color::Red);
    int posx2 = 315, posy2 = 111;
    shape2.setPosition(posx2, posy2);
    shape2.setOrigin(55, 25);

    sf::RectangleShape shape3(sf::Vector2f(500, 20));
    shape3.setFillColor(sf::Color::Blue);
    int posx3 = 750, posy3 = 500;
    shape3.setPosition(posx3, posy3);
    shape3.setOrigin(250, 10);

    while (window.isOpen())
    {
        // Переменная для хранения события
        sf::Event event;
        // Цикл по всем событиям
        while (window.pollEvent(event))
        {
            // Обработка событий
            // Если нажат крестик, то
            if (event.type == sf::Event::Closed)
                // окно закрывается
                window.close();
        }

        window.clear();
        if (posx1 > (shape1.getSize().x)/2) {
            posx1 -= 5;
            shape1.setPosition(posx1, posy1);
        }
        else posx1 = 75;

        if (posx2 > (shape2.getSize().x) / 2) {
            posx2 -= 1;
            shape2.setPosition(posx2, posy2);
        }
        else posx2 = 0;

        if (posx3 > (shape3.getSize().x) / 2) {
            posx3 -= 3;
            shape3.setPosition(posx3, posy3);
        }
        else posx3 = 0;

        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
            window.display();
            std::this_thread::sleep_for(25ms);
    }

    return 0;
}
