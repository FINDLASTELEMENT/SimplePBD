#include "springedge.h"
#include <cstdio>

void SpringEdge::update(const real& dt)
{
    real f = - stiffness * (glm::length(particleA.pos - particleB.pos) - initialDistance);
    particleA.applyForce(f*glm::normalize(particleA.pos-particleB.pos));
    particleB.applyForce(f*glm::normalize(particleB.pos-particleA.pos));
}
