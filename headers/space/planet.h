#ifndef INCLUDES_SPACE_PLANET_H
#define INCLUDES_SPACE_PLANET_H

#include "common.h"
#include "space/body.h"

enum PlanetType
{
	PlanetType_Habbitable = 0,
	PlanetType_Gaseous,
	PlanetType_Frozen,
	PlanetType_Lava,
	PlanetType_Invalid
};

class Planet : public Body
{
	public:
		Planet(const PlanetType Type, const Vector2<double>& Position, const double Radius);
		~Planet();

		void Update(const Timestep Delta);
		void Draw(sf::RenderTarget& Target);
		
	protected:
		PlanetType m_Type;
};

#endif /* INCLUDES_SSYTEM_H */

