#pragma once

#include "Pixely/core/Core.h"
#include "Pixely/core/Application.h"
#include <stdlib.h>

#ifdef PIXELY_PLATFORM_WINDOWS

extern Pixely::Application* Pixely::createApplication(Pixely::ApplicationCommandLineArgs args);

#ifdef PIXELY_DIST
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	int argc = __argc;
	char** argv = __argv;
#else
int main(int argc, char** argv) {
#endif
	Pixely::Log::init();

	auto app = Pixely::createApplication({ argc, argv });
	app->run();
	delete app;
}

#endif
