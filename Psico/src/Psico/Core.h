#pragma once


#ifdef PS_PLATFORM_WINDOW
	#ifdef PS_BUILD_DLL
		#define PSICO_API _declspec(dllexport)
	#else
		#define PSICO_API _declspec(dllimport)
	#endif
#else
	#error Psico only supports windows
#endif
