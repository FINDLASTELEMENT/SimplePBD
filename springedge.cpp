#include "springedge.h"
#include <glm/gtx/norm.hpp>
#include <cstdio>

void SpringEdge::update(const real& dt)
{
    real f = abs(glm::length(particleA.pos - particleB.pos) - initialDistance)*stiffness;
    particleA.applyForce(f*glm::normalize(particleB.pos-particleA.pos));
    particleB.applyForce(f*glm::normalize(particleA.pos-particleB.pos));
}
