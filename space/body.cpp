#include "space/body.h"

Body::Body(const Vector2<double>& Position, const double Radius, Body* Parent)
	: m_Position(Position), m_Radius(Radius), m_Parent(Parent)
{
}

Vector2<double> Body::GetRelativePosition( void )
{
	return m_Position;
}

Vector2<double> Body::GetAbsolutePosition( void )
{
	Vector2<double> Result = Vector2<double> (m_Position.X, m_Position.Y);
	Body* Current = this->m_Parent;
	
	while( Current )
	{
		Result = Result + Current->m_Position;
		Current = Current->m_Parent;
	}
	
	return Result;
}

void Body::Update(const Timestep Delta)
{
	for( std::list<Body*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i )
		(*i)->Update(Delta);
}

void Body::Draw(sf::RenderTarget& Target)
{
	for( std::list<Body*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i )
		(*i)->Draw(Target);
}

