#include "space/planet.h"

Planet::Planet(int seed) : Body()
{
}

Planet::~Planet()
{
	Body::~Body();
}