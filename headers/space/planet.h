#ifndef INCLUDES_SPACE_PLANET_H
#define INCLUDES_SPACE_PLANET_H

#include "common.h"
#include "space/body.h"

class Planet : public Body
{
	public:
		Planet(int seed = -1);
		~Planet();
};

#endif /* INCLUDES_SSYTEM_H */

