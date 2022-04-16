#include <Pixely.h>
#include <imgui/imgui.h>
#include <glm/glm.hpp>

#define SANDBOX_VERSION "0.1.0"

class Sandbox : public Pixely::Application {
public:
	Sandbox(Pixely::ApplicationCommandLineArgs args)
		: Pixely::Application(std::string("Sandbox ") + SANDBOX_VERSION, args) {
		PIXELY_LOG_INFO("Running version: {}", SANDBOX_VERSION);
	}

	~Sandbox() override { PIXELY_LOG_INFO("Bye"); }
};

Pixely::Application* Pixely::createApplication(ApplicationCommandLineArgs args) { return new Sandbox(args); }
