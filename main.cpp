#include <ctime>

#include <SFML/Graphics.hpp>
#include "Puller.hpp"

int pick_rand(int start, int end) {
    return (rand()%(end-start+1)) + start;
}

int main() {
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Repka");

    bool is_draw_repka = true;

    Repka repka(25.f);
    repka.setFillColor(sf::Color(180, 180, 20));
    repka.setPosition(0.f, 300.f);
    repka.need_strength = 21;

    Puller *temp = nullptr;
    Puller *puller = new Puller(sf::Vector2f(25.f, 50.f));
    puller->setFillColor(sf::Color(100, 100, 255));
    puller->setPosition(50.f, 300.f);
    puller->strength = 6;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left && puller != nullptr)
                {
                    if (is_draw_repka)
                    {
                        temp = puller->removeFromChain();
                        delete puller;
                        puller = temp;
                    } else is_draw_repka = true;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    if ((puller == nullptr) || (!puller->pull(repka)))
                    {
                        temp = puller;
                        puller = new Puller(sf::Vector2f(pick_rand(15, 30), pick_rand(25, 50)));
                        puller->setFillColor(sf::Color(pick_rand(50, 255), pick_rand(50, 255), pick_rand(50, 255)));
                        puller->strength = pick_rand(3, 5);
                        if (temp)
                        {
                            puller->setPosition(
                                temp->getPosition().x + temp->getSize().x + 5.f,
                                350.f - puller->getSize().y
                            );
                        }
                        else
                        {
                            puller->setPosition(
                                50.f,
                                350.f - puller->getSize().y
                            );
                        }
                        puller->addToChain(temp);
                    } else is_draw_repka = false;
                }
            }
        }
        
        window.clear();

        if (is_draw_repka) window.draw(repka);
        if (puller) window.draw(*puller);

        window.display();
    }

    return 0;
}