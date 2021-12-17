#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "ball.hpp"
#include "platform.hpp"
#include "block.hpp"

using namespace std::chrono_literals;
using namespace std;
using namespace ssh;

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
    srand(time(0));
    float t = 0;

    const int width = 800;
    const int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), L"баунс энд дестрой");

    setlocale(LC_ALL, "Rus");
    int a_circ = 20;
    int a_platf = 100;
    int b_platf = 30;
    int a_block = 80;
    int b_block = 47;
    bool if_started = 0;
    bool story_showed = 0;
    int blocks_num = 0;
    int rows = 1;
    //забиваем все объекты
    Circle* circle = new Circle(width / 2 - a_circ, height - b_platf - 2*a_circ, a_circ, 0, 0);
    if (!circle->Setup()) {
        delete circle;
        cout << "error setupping fireball" << endl;
        return -1;
    }
    Platform* platform = new Platform(width / 2, height - b_platf / 2, a_platf, b_platf, 0);

    vector<vector<Block*>> blocks;
    for (int i = 0; i < rows; ++i) {
        blocks.push_back(vector<Block*>());
        for (int j = 0; j < width / a_block; ++j) {
            blocks[i].push_back(new Block(a_block*j+12, b_block*i+8, a_block, b_block));
            if (!blocks[i][j]->Setup())
                return -1;
            if (blocks[i][j]->RandomPattern() == 0) blocks[i][j] = nullptr;
            else blocks_num += 1;
        }
    }
    //фон
    sf::Texture texture;
    if (!texture.loadFromFile("img/back.jpg")) {
        cout << "error background not found" << endl;
        return -1;
    }
    sf::Sprite back;
    back.setTexture(texture);

    //предыстория
    sf::Texture story;
    if (!story.loadFromFile("img/story.png")) {
        cout << "error while loading story" << endl;
        return -1;
    }
    sf::Sprite storyback;
    storyback.setTexture(story);

    //in case you won
    sf::Texture win;
    if (!win.loadFromFile("img/win.png")) {
        cout << "error while loading winning page" << endl;
        return -1;
    }
    sf::Sprite winback;
    winback.setTexture(win);

    // Подгрузка шрифта и счет
    sf::Font font;
    if (!font.loadFromFile("fonts/comic.ttf"))
    {
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }

    // Добавление иконки
    sf::Image icon;
    if (!icon.loadFromFile("img/icon.png"))
    {
        return -1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Yellow);

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
        //предыстория
        if (story_showed == 0) {
            window.draw(storyback);
            window.display();
            story_showed = 1;
            while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
                story_showed = 0;
            }
        }
        
        //когда хлеб закончился
        if (blocks_num <= 0) {
            window.clear();
            window.draw(winback);
            window.display();
            while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                int k = 1;
            }
            window.close();
        }
        
        //начало игры с пробела
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (if_started == 0)) { 
            platform->SetVelocity(15);
            circle->SetYVelocity(10);
            circle->SetXVelocity(8);
            if_started = 1;
        }
        //управление стрелками
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Right)
                platform->Move(1);
            else if (event.key.code == sf::Keyboard::Left)
                platform->Move(0);
            break;
        }
        //пауза
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            platform->SetVelocity(0);
            circle->SetYVelocity(0);
            circle->SetXVelocity(0);
            if_started = 0;
        }

        if (circle != nullptr)
            circle->Move();

        //движение файербола + столкновения
        if (circle != nullptr) {
            if ((circle->GetX() <= 0) || (circle->GetX() >= width - 2*a_circ)) circle->SetXVelocity(-circle->GetXVelocity()); //касание боковых границ
            if (circle->GetY() <= 0) circle->SetYVelocity(-circle->GetYVelocity()); //касание верха
            if (circle->GetY() >= height - a_circ) { // при попадении на нижнюю границу рестарт
                if_started = 0;
                t = 0;
                platform->SetVelocity(0);
                circle->SetXVelocity(0);
                circle->SetYVelocity(0);
                circle->SetX(width / 2 - a_circ);
                circle->SetY(height - b_platf - 2 * a_circ);
                platform->SetX(width / 2);
            }

            if (platform->IfTangent(circle->GetX(), circle->GetY(), a_circ) == 1) circle->SetYVelocity(-circle->GetYVelocity()); // прямое касание платформы, закон отражения
            if (platform->IfTangent(circle->GetX(), circle->GetY(), a_circ) == 2) { // касание угла платформы, отражается в обратном направлении
                circle->SetYVelocity(-circle->GetYVelocity());
                circle->SetXVelocity(-circle->GetXVelocity());
            }
            //уничтожение кусков хлеба
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < blocks[i].size(); ++j){
                if (blocks[i][j] != nullptr) {
                    if (blocks[i][j]->IfTangent(circle->GetX(), circle->GetY(), a_circ) == 1) {
                        blocks_num -= 1;
                        delete blocks[i][j];
                        blocks[i].erase(blocks[i].begin() + j);
                        --j;
                        circle->SetYVelocity(-circle->GetYVelocity());
                    }
                }
            }
        }
        
        }

        window.clear();
        text.setString(std::string("You're holding for ") + std::to_string((int)t) + std::string(" seconds."));
        window.draw(back);
        if (circle != nullptr)
            window.draw(*circle->Get());
        window.draw(*platform->Get());
        for (const auto& vec : blocks) {
            for (const auto& block : vec) {
                if (block != nullptr)
                window.draw(*block->Get());
            }
        }
        window.draw(text);

        window.display();

        std::this_thread::sleep_for(40ms);
        t += 0.04;
    }

    delete platform;
    delete circle;
    for (const auto& vec : blocks) {
        for (const auto& block : vec) {
            delete block;
        }
    }

    return 0;
}
