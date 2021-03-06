#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include "precision.h"

class Particle
{
public:
    Particle() : imass(1), friction(1), acc(vec3(0, 0, 0)), vel(vec3(0, 0, 0)), prevpos(vec3(0, 0, 0)), pos(vec3(0, 0, 0)) {};
    Particle(const real& mass, const real& friction, const vec3& pos) : imass(1/mass), friction(friction), acc(vec3(0,0,0)), vel(vec3(0,0,0)), prevpos(pos), pos(pos) {};

    Particle(const Particle& other);

    ~Particle();

    Particle& operator=(const Particle& other);
    
    void initalize(const Particle& p);
    
    void setMass(const real& mass);
    void setImass(const real& imass);
    void teleport(const vec3& pos);
    void setPos(const vec3& pos);
    
    void applyForce(const vec3& force);
    
    void update(const real& dt, const vec3& gravity);
    void apply(const real& dt);

    real imass;
    real friction;
    vec3 acc;
    vec3 vel;
    vec3 prevpos;
    vec3 pos;
};

#endif // PARTICLE_H
