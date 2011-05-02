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
		Vector2<double> GetRelativePosition( void );
		
		// Gets the position, compared to space
		// For example, Moon + Planet + Solar System + Galaxy + Space
		// You should override this for satellites, to take into account
		// its orbit around another body.
		virtual Vector2<double> GetAbsolutePosition( void );
	
	protected:
		Vector2<double> m_Position;
		double m_Radius;
		
		Body* m_Parent;
};

#endif /* INCLUDES_SPACE_BODY_H */

