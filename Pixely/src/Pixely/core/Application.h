#pragma once

#include "Pixely/core/Core.h"
#include "Pixely/core/Log.h"
#include <string>

#ifdef PIXELY_DIST
int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
#else
int main(int argc, char** argv);
#endif

namespace Pixely {

	struct ApplicationCommandLineArgs {
		int count = 1;
		char** args = nullptr;

		const char* operator[](int index) const {
			PIXELY_ASSERT(index < count, "Called out of bound for Command arg");
			return args[index];
		}
	};

	class Application {
	private:
		static Application* instance;
		bool isRunning = true;

		ApplicationCommandLineArgs commandLineArgs;
		float lastFrameTime = 0.0f;

	public:
		Application(const std::string& name = "Pixely Engine",
			const ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();

		static Application& get() { return *instance; }

		ApplicationCommandLineArgs getCommandLineArgs() { return commandLineArgs; }

	private:
		void run();

#ifdef PIXELY_DIST
		friend int ::wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
#else
		friend int ::main(int argc, char** argv);
#endif
	};

	// To be defined in CLIENT
	Application* createApplication(ApplicationCommandLineArgs args);

}  // namespace Dixel
