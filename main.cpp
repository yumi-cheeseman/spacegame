#include <SFML/System.hpp>
#include <iostream>

#include "common.h"

int main(int argc, char** argv)
{
	#ifdef PLATFORM_WINDOWS
		std::cout << "Hello, Windows." << std::endl;
	#else
		#ifdef PLATFORM_LINUX
			std::cout << "Hello, Linux." << std::endl;
		#endif
	#endif
	
    return 0;
}

