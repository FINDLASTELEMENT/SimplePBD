#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "precision.h"
#include "particle.h"


class Constraint
{
public:
    Constraint(real k) : k(k) {};
    virtual ~Constraint() {};
    
    virtual void update(const real& dt) = 0;
    
    void initilizeSolve();
    
    real k;
    real lambda;
};

class DistanceConstraint : public Constraint
{
public:
    DistanceConstraint(Particle& a, Particle& b, const real& k, const real& d) : a(a), b(b), Constraint(k), d(d) {};
    ~DistanceConstraint() {};
    
    void update(const real& dt);
    
    Particle& a;
    Particle& b;
    real d;
};

class FixedConstraint : public Constraint
{
public:
    FixedConstraint(Particle& p, const glm::vec3& pos, const real& k) : p(p), pos(pos), Constraint(k) {};
    ~FixedConstraint() {};
    
    void update(const real& dt);
    
    Particle& p;
    vec3 pos;
};

#endif
