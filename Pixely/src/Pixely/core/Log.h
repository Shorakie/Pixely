#pragma once

#include "Pixely/core/Core.h"

//#pragma warning(push)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
//#pragma warning(pop)

namespace Pixely {

	class Log {
	private:
		static bool initialized;
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

	public:
		static void init();

		static std::shared_ptr<spdlog::logger> getCoreLogger();
		static std::shared_ptr<spdlog::logger> getClientLogger();
	};

}  // namespace Dixel

#ifdef PIXELY_LIB  // core engine macros
#define PIXELY_LOG_TRACE(...)	 ::Pixely::Log::getCoreLogger()->trace(__VA_ARGS__)
#define PIXELY_LOG_INFO(...)	 ::Pixely::Log::getCoreLogger()->info(__VA_ARGS__)
#define PIXELY_LOG_WARN(...)	 ::Pixely::Log::getCoreLogger()->warn(__VA_ARGS__)
#define PIXELY_LOG_ERROR(...)	 ::Pixely::Log::getCoreLogger()->error(__VA_ARGS__)
#define PIXELY_LOG_CRITICAL(...) ::Pixely::Log::getCoreLogger()->critical(__VA_ARGS__)
#else  // client macros
#define PIXELY_LOG_TRACE(...)	 ::Pixely::Log::getClientLogger()->trace(__VA_ARGS__)
#define PIXELY_LOG_INFO(...)	 ::Pixely::Log::getClientLogger()->info(__VA_ARGS__)
#define PIXELY_LOG_WARN(...)	 ::Pixely::Log::getClientLogger()->warn(__VA_ARGS__)
#define PIXELY_LOG_ERROR(...)	 ::Pixely::Log::getClientLogger()->error(__VA_ARGS__)
#define PIXELY_LOG_CRITICAL(...) ::Pixely::Log::getClientLogger()->critical(__VA_ARGS__)
#endif

#if defined(PIXELY_DIST)
#define PIXELY_LOG_LEVEL spdlog::level::off
#else
#define PIXELY_LOG_LEVEL spdlog::level::trace
#endif
