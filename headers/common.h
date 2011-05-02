#ifndef INCLUDES_COMMON_H
#define INCLUDES_COMMON_H

// Try and autodetect the platform
#ifdef _WIN32
	#define PLATFORM_WINDOWS
#else
	#if defined(__GNUC__) && __GNUC__ >= 4
		#define PLATFORM_LINUX
	#endif
#endif

#endif /* INCLUDES_COMMON_H */

