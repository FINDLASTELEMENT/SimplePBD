#include "particle.h"

Particle::Particle(const Particle& other)
{
    this->initalize(other.imass, other.pos);
}

Particle::~Particle()
{
    
}

Particle& Particle::operator=(const Particle& other)
{
    this->initalize(other.imass, other.pos);
    return *this;
}

void Particle::initalize(const real& imass, const glm::vec3& pos)
{
    this->imass = imass;
    this->pos = pos;
}

void Particle::setMass(const real& mass)
{
    imass = 1/mass;
}

void Particle::setImass(const real& imass)
{
    this->imass = imass;
}

void Particle::setPos(const vec3& pos)
{
    this->pos = pos;
}

void Particle::applyForce(const vec3& force)
{
    this->acc += force * imass;
}

void Particle::update(const real& dt)
{
    vel += acc*dt;
    pos += vel*dt;
    acc = vec3(0, 0, 0);
}

