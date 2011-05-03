#ifndef INCLUDES_SPACE_SOLARSYSTEM_H
#define INCLUDES_SPACE_SOLARSYSTEM_H


#include "common.h"
#include "space/body.h"
#include "planet.h"
#include "math/vector2.h"

//all for use in generating the solar system
#include <SFML/Graphics.hpp>
#include "pnoise/pnoise.h"
#include <cmath>

class SolarSystem: public Body
{
public:

	//solar systems are generated at initialisation
	//of game, but star and planets not generated until
	//space ship is close enough.
	SolarSystem(const Vector2<double>& Position, const double Radius);
	//:Body(Position, Radius, Galaxy){} 
	

	~SolarSystem(){/*delete kids*/}
	
	//This function is called when spaceship close enough 
	//uses perlin noise to work out the layout of the solar
	//system
	void GenerateSolarSystem();

	//do we want moving solar systems? if so, will take
	//quite a bit of effort + research to do it properly
	virtual void Update(const Timestep Delta);
	
	//Draw solar system. Implemented so it draws the solar
	//system, and if close enough/in correct view, will draw 
	//children (planets/star)
	virtual void Draw(sf::RenderTarget& Target);

protected:
private:
	Body * Star;
};

#endif

