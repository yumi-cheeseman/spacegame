#ifndef INCLUDES_PNOISE_H
#define INCLUDES_PNOISE_H

#include "common.h"

#include <SFML/Graphics.hpp>

namespace PerlinNoise
{
	extern void Generate( sf::Image &Image, const int Octaves, const double Zoom, const double Persistence, const int Seed = 57 );
}

#endif /* INCLUDES_PNOISE_H */

