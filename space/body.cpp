#include "space/body.h"

Body::Body(const Vector2<double>& Position, const double Radius, Body* Parent)
	: m_Position(Position), m_Radius(Radius), m_Parent(Parent)
{
}

