#include "particle.h"
#include <cstdio>

Particle::Particle(const Particle& other)
{
    this->initalize(other);
}

Particle::~Particle()
{
    
}

Particle& Particle::operator=(const Particle& other)
{
    this->initalize(other);
    return *this;
}

void Particle::initalize(const Particle& p)
{
    this->imass = p.imass;
    this->prevpos = p.prevpos;
    this->friction = p.friction;
    this->pos = p.pos;
    this->vel = p.vel;
    this->acc = p.acc;
}

void Particle::setMass(const real& mass)
{
    imass = 1/mass;
}

void Particle::setImass(const real& imass)
{
    this->imass = imass;
}

void Particle::teleport(const vec3& pos)
{
    this->prevpos = pos;
    this->pos = pos;
}

void Particle::setPos(const vec3& pos)
{
    this->pos = pos;
}

void Particle::applyForce(const vec3& force)
{
    this->acc += force * imass;
}

void Particle::update(const real& dt, const vec3& gravity)
{
    prevpos = pos;
    vel += dt*(acc+gravity)*friction;
    pos += vel*dt;
    
    acc = vec3(0, 0, 0);
}

void Particle::apply(const real& dt)
{
    vel = (pos - prevpos)/dt;
    //vel *= pow(friction, dt);
}

