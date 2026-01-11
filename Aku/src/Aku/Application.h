#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Aku {
	class AKU_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}



