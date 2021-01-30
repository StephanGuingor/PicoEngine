#pragma once

#ifdef PS_PLATFORM_WINDOW

extern Psico::Application* Psico::CreateApplication();

int main(int argc,char** argv)
{
	Psico::Log::Init();
	int a = 5;
	PS_CORE_WARN("Hello World! {0}", a);

	auto app = Psico::CreateApplication();
	app->Run();
	delete app;
}

#endif
