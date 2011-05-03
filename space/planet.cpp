#include "space/planet.h"

Planet::Planet(const PlanetType Type, const Vector2<double>& Position, const double Radius)
	: Body(Position, Radius), m_Type(Type)
{
	
}

Planet::~Planet()
{
	
}

void Planet::Update(const Timestep Delta)
{
	Body::Update(Delta);	
}

void Planet::Draw(sf::RenderTarget& Target)
{
	Body::Draw(Target);
}

