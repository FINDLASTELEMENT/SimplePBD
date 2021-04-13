#include "springedge.h"
#include <glm/gtx/norm.hpp>
#include <cstdio>

void SpringEdge::update(const real& dt)
{
    real f = std::abs(glm::length(particleA.prevpos - particleB.prevpos) - initialDistance)*stiffness;
    particleA.applyForce(f*glm::normalize(particleB.prevpos-particleA.prevpos));
    particleB.applyForce(f*glm::normalize(particleA.prevpos-particleB.prevpos));
}
