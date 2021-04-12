#ifndef SPRINGEDGE_H
#define SPRINGEDGE_H

#include "edge.h"
#include "particle.h"

class SpringEdge : public Edge
{
public:
    SpringEdge(Particle& particleA, Particle& particleB, real initialDistance, real stiffness) : Edge(particleA, particleB), initialDistance(initialDistance), stiffness(stiffness) {};
    
    void update(const real& dt);
    
    real initialDistance;
    real stiffness;
};

#endif // SPRINGEDGE_H
