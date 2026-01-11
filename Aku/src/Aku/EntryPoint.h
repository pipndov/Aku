#pragma once

#ifdef AKU_PLATFORM_WINDOWS

extern Aku::Application* Aku::CreateApplication();


int main(int argc, char** argv) {
	
	Aku::Log::Init();
	AKU_CORE_WARN("Initialized Log!");
	int a = 5;
	AKU_INFO("Hello! Var={0}", a);

	// printf("Aku Engine");
	auto app = Aku::CreateApplication();
	app->Run();
	delete app;
}

#endif