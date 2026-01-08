#pragma once

#ifdef AKU_PLATFORM_WINDOWS

extern Aku::Application* Aku::CreateApplication();

int main(int argc, char** argv) {
	
	// printf("Aku Engine");
	auto app = Aku::CreateApplication();
	app->Run();
	delete app;
}

#endif