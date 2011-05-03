#include "space/body.h"

Body::Body(const Vector2<double>& Position, const double Radius, Body* Parent)
	: m_Position(Position), m_Radius(Radius), m_Parent(Parent)
{
}

Vector2<double> Body::GetPosition( void )
{
	return m_Position;
}

Body* Body::GetParent( void )
{
	return m_Parent;
}

Vector2<double> Body::GetAbsolutePosition( void )
{
	Vector2<double> result = m_Position;
	Body* current = GetParent();
	while(current!=NULL)
	{
		result += current->GetPosition();
		current = current->GetParent();
	}
	
	return result;
}

void Body::Tick(void)
{
}
