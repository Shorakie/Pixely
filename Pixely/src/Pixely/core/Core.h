#pragma once
#include "PlatformDetection.h"

#ifdef PIXELY_DEBUG
#if defined(PIXELY_PLATFORM_WINDOWS)
#define PIXELY_DEBUGBREAK() __debugbreak()
#elif defined(PIXELY_PLATFORM_LINUX)
#include <signal.h>
#define PIXELY_DEBUGBREAK() raise(SIGTRAP)
#else
#define PIXELY_DEBUGBREAK()
#endif
#define PIXELY_ENABLE_ASSERTS
#else
#define PIXELY_DEBUGBREAK()
#endif

#define PIXELY_BIND_EVENT_FN(func) \
	[this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }

#ifdef PIXELY_ENABLE_ASSERTS
#define PIXELY_ASSERT(x, ...)              \
		if (!bool(x)) {                    \
			PIXELY_LOG_ERROR(__VA_ARGS__); \
			__debugbreak();                \
		}
#else
#define PIXELY_ASSERT(x, ...)
#endif	// !ENABLE_ASSERTS
