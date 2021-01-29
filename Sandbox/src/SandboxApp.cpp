#include <Psico.h>
class Sandbox : public Psico::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Psico::Application* Psico::CreateApplication()
{
	return new Sandbox();
}