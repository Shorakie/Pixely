#include "pixelypch.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Pixely {

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;
	bool Log::initialized = false;

	void Log::init() {
		if (initialized)
			return;
		else
			initialized = true;

		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Dixel.log", true));

		logSinks[0]->set_pattern("%^[%l] %T@%n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		coreLogger = std::make_shared<spdlog::logger>("CORE", begin(logSinks), end(logSinks));
		spdlog::register_logger(coreLogger);
		coreLogger->set_level(PIXELY_LOG_LEVEL);
		coreLogger->flush_on(PIXELY_LOG_LEVEL);

		clientLogger = std::make_shared<spdlog::logger>("CLIENT", begin(logSinks), end(logSinks));
		spdlog::register_logger(clientLogger);
		clientLogger->set_level(PIXELY_LOG_LEVEL);
		clientLogger->flush_on(PIXELY_LOG_LEVEL);
	}

	std::shared_ptr<spdlog::logger> Log::getCoreLogger() {
		if (initialized)
			return coreLogger;
		else
			throw "Core Logger is not loaded";
	}

	std::shared_ptr<spdlog::logger> Log::getClientLogger() {
		if (initialized)
			return clientLogger;
		else
			throw "Client Logger is not loaded";
	}
}  // namespace Dixel
