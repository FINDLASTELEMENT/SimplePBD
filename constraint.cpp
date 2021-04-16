#include "constraint.h"

void DistanceConstraint::update()
{
    vec3 f = (glm::length(a.pos - b.pos) - d)/(a.imass + b.imass)*glm::normalize(a.pos - b.pos);
    a.setPos(a.pos - a.imass*f*k);
    b.setPos(b.pos + b.imass*f*k);
}

void FixedConstraint::update()
{
    if (k != 0)
    {
        p.setPos(pos);
    }
}
