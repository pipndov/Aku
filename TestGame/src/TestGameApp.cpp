#include <Aku.h>

class TestGameApp : public Aku::Application
{
public:
	TestGameApp() 
	{

	}

	~TestGameApp()
	{

	}
};

Aku::Application* Aku::CreateApplication()
{
	return new TestGameApp();
}