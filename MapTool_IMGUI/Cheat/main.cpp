#include "gui.h"

#include <thread>

int APIENTRY wWinMain(
	_In_		HINSTANCE instance,
	_In_opt_	HINSTANCE previousInstance,
	_In_		PWSTR arguments,
	_In_		int commandShow)
{
	// create gui
	gui::CreateHWindow("Cheat Menu", "Cheat Menu Class");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::exit)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	// destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}