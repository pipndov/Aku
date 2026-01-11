#include "akpch.h"
#include "Application.h"

#include "Aku/Events/ApplicationEvent.h"
#include "Aku/Log.h"

namespace Aku {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		AKU_TRACE(e);
		
		while (true);
	}
}