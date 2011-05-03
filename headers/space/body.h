#ifndef INCLUDES_SPACE_BODY_H
#define INCLUDES_SPACE_BODY_H

#include "common.h"
#include "math/vector2.h"

// The base class for everything that is in space that isn't alive:
// Like asteroids, suns, planets, moons, etc.
class Body
{
	public:
		Body(const Vector2<double>& Position, const double Radius, Body* Parent = 0);
		virtual ~Body() { }
		
		// Relative to its parents.
		Vector2<double> GetPosition( void );
		
		// Gets the position, compared to space.
		Vector2<double> GetAbsolutePosition( void );

		//Returns the parent
		Body* GetParent(void);
		
		//Update
		virtual void Tick(void);
	
	protected:
		Vector2<double> m_Position;
		double m_Radius;
		
		Body* m_Parent;
};

#endif /* INCLUDES_SPACE_BODY_H */

