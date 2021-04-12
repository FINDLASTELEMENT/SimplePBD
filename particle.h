#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include "precision.h"

using namespace glm;
class Particle
{
public:
    Particle() : imass(1), acc(vec3(0, 0, 0)), vel(vec3(0, 0, 0)), pos(vec3(0, 0, 0)) {};
    Particle(const real& mass, const vec3& pos) : imass(1/mass), pos(pos) {};

    Particle(const Particle& other);

    ~Particle();

    Particle& operator=(const Particle& other);
    
    void initalize(const real& imass, const vec3& pos);
    
    void setMass(const real& mass);
    void setImass(const real& imass);
    void setPos(const vec3& pos);
    
    void applyForce(const vec3& force);
    
    void update(const real& dt);

    real imass;
    vec3 acc;
    vec3 vel;
    vec3 pos;
};

#endif // PARTICLE_H
