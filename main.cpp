#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "particle.h"
#include "springedge.h"
#include "constraint.h"

sf::Vector2f to2(vec3 x)
{
    return sf::Vector2f(x.x, x.y);
}

void initCir(sf::CircleShape& cir)
{
    cir.setOrigin(sf::Vector2f(cir.getLocalBounds().width/2, cir.getLocalBounds().height/2));
    cir.setFillColor(sf::Color::Red);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "softbody!");
    
    Particle p1 = Particle(1, .9995, glm::vec3(400, 300, 0));
    Particle p2 = Particle(1, .9995, glm::vec3(350, 300, 0));
    Particle p3 = Particle(1, .9995, glm::vec3(300, 300, 0));
    
    DistanceConstraint d1 = DistanceConstraint(p1, p2, .5, 50);
    DistanceConstraint d2 = DistanceConstraint(p2, p3, .5, 50);
    
    FixedConstraint f1 = FixedConstraint(p1, glm::vec3(400, 300, 0), 1);
    
    auto c1 = sf::CircleShape(5);
    initCir(c1);
    
    auto c2 = sf::CircleShape(5);
    initCir(c2);
    
    auto c3 = sf::CircleShape(5);
    initCir(c3);
    
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
        
        p1.update(dt, vec3(0, 0, 0));
        p2.update(dt, vec3(0, 1000000, 0));
        p3.update(dt, vec3(0, 1000000, 0));
        
        for (int i=0;i<20;i++)
        {
            d1.update();
            d2.update();
            f1.update();
        }
        
        p1.apply(dt);
        p2.apply(dt);
        p3.apply(dt);
        
        c1.setPosition(to2(p1.pos));
        c2.setPosition(to2(p2.pos));
        c3.setPosition(to2(p3.pos));
        
        window.draw(c1);
        window.draw(c2);
        window.draw(c3);
        
        window.display();
        
        deltaClock.restart();
    }
    
    return 0;
}
