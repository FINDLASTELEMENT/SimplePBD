#ifndef EDGE_H
#define EDGE_H

#include "particle.h"

class Edge
{
public:
    Edge(Particle& particleA, Particle& particleB) : particleA(particleA), particleB(particleB) {};
    virtual ~Edge();
    
    virtual void update(const real& dt) = 0;
    
    Particle& particleB;
    Particle& particleA;
};

#endif // EDGE_H
