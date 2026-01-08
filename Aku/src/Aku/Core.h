#pragma once

#ifdef AKU_PLATFORM_WINDOWS
	#ifdef AKU_BUILD_DLL
		#define AKU_API __declspec(dllexport)
	#else
		#define AKU_API __declspec(dllimport)
	#endif
#else
	#error AKU only supports Windows!
#endif