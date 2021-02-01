#include <Psico.h>

class MyLayer : public Psico::Layer
{
public:
	MyLayer()
		: Layer("Stephy")
	{}

	void OnUpdate() override
	{


	}


	void OnEvent(Psico::Event& event) override
	{
		PS_TRACE("{0}", event);
	
	}
};

class Sandbox : public Psico::Application
{
public:
	Sandbox()
	{
		PushLayer(new MyLayer());
		PushOverlay(new Psico::ImGuiLayer());
		__mm256;
		__asm {
			vmovaps ymm0, ymmword[eax]
			vmovaps ymm1, ymmword[ebx]
			vmaddps ymm0, ymm1, ymm0[ebx]
			vmovaps ymmword[ecx], ymm0
		};
	}

	~Sandbox()
	{

	}


};

Psico::Application* Psico::CreateApplication()
{
	return new Sandbox();
}