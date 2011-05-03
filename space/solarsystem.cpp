#include "space/solarsystem.h"

void
SolarSystem::GenerateSolarSystem()
{
	sf::Randomizer::SetSeed(time(0));
	
	//produce a random number between -10 and 10
	float RandomNumber = 20 * sf::Randomizer::Random(0.0f, 1.0f) - 10;
	
	float Product = 0.9 * (100 - (RandomNumber * RandomNumber)); //For use in circle equation
	
	//turn this number into something between 0 and 20, with a big
	//bias towards 10 area
	float CalcPlanets;
	
	if (RandomNumber > 0) //we get a float value between 10 and 20
	{
	 	CalcPlanets = 20 -  sqrt(Product);
	}
	else // we get a float value between 0 and 10
	{
		CalcPlanets = 0 + sqrt(Product);
	}
	
	
	int NumberOfPlanets = (int)CalcPlanets; //can only have an integer number of planets between 1 and 19
	if (NumberOfPlanets < 1)
	{
		NumberOfPlanets = 1;
	}
	if (NumberOfPlanets > 19)
	{
		NumberOfPlanets = 19;
	}


	sf::Image * PerlinNoise = new sf::Image(100, 1000);
	//Make a strip of perlin noise, go alone finding largish black spots
	//distance from origin determines distance of planets
	//if need be we can generate more strip of perlin
	
	
	
	int Oct = 5; //???
	int PSeed = 20; //rand()
	PerlinNoise::Generate(*PerlinNoise, Oct, 1.0 /*irrelevant*/, 1.0 /*irrelevant*/, PSeed);
	
	//take a snapshot of the top of the image, to work out what the sun will be

}
