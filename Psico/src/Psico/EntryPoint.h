#pragma once

#ifdef PS_PLATFORM_WINDOW

extern Psico::Application* Psico::CreateApplication();

int main(int argc,char** argv)
{
	auto app = Psico::CreateApplication();
	app->Run();
	delete app;
}

#endif
