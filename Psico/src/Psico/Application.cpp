#include "pspch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Psico/Log.h"

namespace Psico
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		WindowResizeEvent e(1280, 720);
		PS_TRACE(e);

		while (true);
	}
}
