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

// 64 meters to the pixel
#define PIXELS_METER_RATIO 64

#ifndef NULL
#define NULL 0
#endif

#endif /* INCLUDES_COMMON_H */

