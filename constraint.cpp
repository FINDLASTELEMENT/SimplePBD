#include "constraint.h"
#include <glm/gtx/norm.hpp>

void Constraint::initilizeSolve()
{
    lambda = 0;
}

void DistanceConstraint::update(const real& dt)
{
    real imassSum = a.imass + b.imass;
    
    real C = glm::length(a.pos - b.pos) - d;
    vec3 dC = glm::normalize(a.pos - b.pos);
    
    real aTild = k/(dt*dt);
    
    real dLambda = (-C - aTild*lambda) / ((imassSum + aTild));
    vec3 dX = dC * dLambda;
    
    
    /*vec3 f = (glm::length(a.pos - b.pos) - d)/(a.imass + b.imass)*glm::normalize(a.pos - b.pos);*/
    a.setPos(a.pos + a.imass*dX);
    b.setPos(b.pos - b.imass*dX);
    
    lambda += dLambda;
}

void FixedConstraint::update(const real& dt)
{
    if (k != 0)
    {
        p.setPos(pos);
    }
}
