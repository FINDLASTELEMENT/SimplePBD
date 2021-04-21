#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "particle.h"
#include "springedge.h"
#include "constraint.h"
#include "consts.h"

sf::Vector2f to2(const vec3& x)
{
    return sf::Vector2f(x.x, x.y);
}

vec3 to3(const sf::Vector2f& x)
{
    return vec3(x.x, x.y, 0);
}

void initCir(sf::CircleShape& cir)
{
    cir.setOrigin(sf::Vector2f(cir.getLocalBounds().width/2, cir.getLocalBounds().height/2));
    cir.setFillColor(sf::Color::Red);
}

int main() {
    int substep = SUBSTEP;
    int iteration = 20;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "softbody!");

    std::vector<Particle> particles(CNT, Particle(k, FRICTION, vec3(400, 0, 0)));
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].setPos(vec3(400, MARGIN+i*INTERVAL, 0));
    }
    particles[0].setImass(0);

    std::vector<DistanceConstraint> constraints;
    for (int i=0; i<particles.size()-1; i++)
    {
        constraints.push_back(DistanceConstraint(particles[i], particles[i+1], 1, INTERVAL));
    }

    FixedConstraint f1 = FixedConstraint(particles[0], vec3(400, MARGIN, 0), 1);
    FixedConstraint f2 = FixedConstraint(particles.back(), vec3(0, 0, 0), 0);

    std::vector<sf::CircleShape> cirs(particles.size(), sf::CircleShape(3));
    for ( auto& elem : cirs )
    {
        initCir(elem);
    }

    sf::Clock deltaClock;

    bool draging = false;
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                draging = true;
            }
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                draging = false;
            }
        }

        mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        window.clear(sf::Color::Black);

        real dt = deltaClock.restart().asSeconds()/SUBSTEP;

        if (1/dt < 60)
        {
            //printf("%f\n", 1/dt);
        }
        
        for (int i=0; i<substep; i++)
        {
            for (auto& elem : particles)
            {
                elem.update(dt, vec3(0, G, 0));
            }
            
            for (auto& elem : constraints)
            {
                elem.initilizeSolve();
            }
            
            f1.initilizeSolve();
            f2.initilizeSolve();

            f2.pos = to3(mousePos);
            f2.k = draging? 1 : 0;

            for (int j=0; j<iteration; j++)
            {
                for (auto& elem : constraints)
                {
                    elem.update(dt);
                }

                f1.update(dt);
                f2.update(dt);
            }

            for (auto& elem : particles)
            {
                elem.apply(dt);
            }
        }

        for (int i=0; i<cirs.size(); i++)
        {
            cirs[i].setPosition(to2(particles[i].pos));
            window.draw(cirs[i]);
        }

        window.display();
    }

    return 0;
}
