#include "pixelypch.h"

#include "Pixely/core/Log.h"
#include "Pixely/core/Application.h"

#include <GLFW/glfw3.h>

namespace Pixely {
	Application* Application::instance;
	Application::Application(const std::string& name, const ApplicationCommandLineArgs args) : commandLineArgs(args) {
		PIXELY_ASSERT(!instance, "Application is already initialized");
		instance = this;
	}

	Application::~Application() {}

	void Application::run() {
		ZoneScopedN("Application loop");
		while (isRunning) {
			float time = (float)glfwGetTime();
			float timestep = time - lastFrameTime;
			lastFrameTime = time;
			FrameMark;
		}
	}
}  // namespace Dixel
