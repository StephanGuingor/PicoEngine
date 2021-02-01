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


#ifdef PS_ENABLE_ASSERTS
	#define PS_ASSERT(x,...) { if ((!(x)) { PS_ERROR("Assertion failed: {0}",__VA_ARGS__); __debugbreak(); } }
	#define PS_CORE_ASSERT(x,...) { if (!(x)) { PS_CORE_ERROR("Assertion failed: {0}",__VA_ARGS__); __debugbreak(); } }

#else
	#define PS_ASSERT(x,...) 
	#define PS_CORE_ASSERT(x,...)
#endif // PS_ENABLE_ASSERTS



#define BIT(x) (1 << x)

#define PS_BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)
