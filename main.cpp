#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Node.hpp"
#include "Pendule.hpp"
//tha9lili3th <=> boucle s taqbaylith

void fondBlanc(sf::RenderWindow *app);

int main()
{
    srand(time(0));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    sf::RenderWindow app(sf::VideoMode(1300, 1000), "Numberium", sf::Style::Close, settings);
    sf::Clock clock;

    Pendule Pendule1(&app, sf::Color::Blue);
    //Pendule Pendule2(&app, sf::Color::Green);

    sf::Vertex line[2];


    fondBlanc(&app);
    Pendule1.draw();
    //Pendule2.draw();
    app.display();


    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        if (  clock.getElapsedTime().asMilliseconds() >= 30 )
        {
            clock.restart();

            app.clear();
            fondBlanc(&app);
            Pendule1.miseAjour();
            Pendule1.draw();
            //Pendule2.miseAjour();
            //Pendule2.draw();
            app.display();

        }
        
    }

    return 0;
}

void fondBlanc(sf::RenderWindow *app){
    sf::RectangleShape fond(sf::Vector2f(1300.f, 1000.f));
    fond.setFillColor(sf::Color(255, 255, 255));

    app->draw(fond);
}

