#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "particle.h"
#include "springedge.h"

sf::Vector2f to2(vec3 x)
{
    return sf::Vector2f(x.x, x.y);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "softbody!");
    
    Particle part1(1, vec3(400, 300, 0));
    Particle part2(1, vec3(430, 430, 0));
    
    sf::CircleShape cir1(5);
    cir1.setOrigin(sf::Vector2f(cir1.getLocalBounds().width/2, cir1.getLocalBounds().height/2));
    cir1.setFillColor(sf::Color::Red);
    
    sf::CircleShape cir2(5);
    cir2.setOrigin(sf::Vector2f(cir2.getLocalBounds().width/2, cir2.getLocalBounds().height/2));
    cir2.setFillColor(sf::Color::White);
    
    SpringEdge ed1(part1, part2, 15, 20000);
    
    sf::Clock deltaClock;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear(sf::Color::Black);
        
        real dt = deltaClock.getElapsedTime().asSeconds();
        
        part1.update(dt);
        part2.update(dt);
        ed1.update(dt);
        
        cir1.setPosition(to2(part1.pos));
        cir2.setPosition(to2(part2.pos));
        
        window.draw(cir1);
        window.draw(cir2);
        
        window.display();
        
        deltaClock.restart();
    }
    
    return 0;
}
