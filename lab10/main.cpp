#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include "Square.hpp"

using namespace std::chrono_literals;

using namespace ssh;

int main()
{
    srand(time(0));

    const int width = 800;
    const int height = 600;

    setlocale(LC_ALL, "Rus");
    std::cout << "Введите количество квадратов." << std::endl;
    int n = 0;
    float a = 30;
    std::cin >> n;
    std::vector<Square*> squares;
    for (int i = 0; i < height; i += height / n) {
        squares.push_back(new Square(width, i, a, rand() % 10 + 5));
    }

    sf::Texture texture;
    if (!texture.loadFromFile("back.jpg")) {
        std::cout << "error background not found" << std::endl;
        return -1;
    }

    sf::Sprite background(texture);

    sf::RenderWindow window(sf::VideoMode(width, height), L"о нет ректанглсы побежали");

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

        for (const auto& square : squares) {
            square->Move();
            if (square->GetX() < a / 2) square->SetX(a / 2);
        }

        window.clear();

        window.draw(background);

    for (const auto& square : squares) {
        window.draw(*square->Get());
    }

    window.display();

    std::this_thread::sleep_for(30ms);
}
    for (const auto& sqaure : squares) {
        delete sqaure;
    }
    squares.clear();

    return 0;
}
