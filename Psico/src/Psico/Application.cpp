#include "pspch.h"
#include "Application.h"
#include "Psico/Log.h"
#include "Psico/Core.h"

#include <glad/glad.h>

namespace Psico
{

	
	

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		PS_CORE_ASSERT(!s_Instance, "Application already exist");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(PS_BIND_EVENT_FN(Application::OnEvent));

	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(PS_BIND_EVENT_FN(Application::OnWindowClose));
					
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{


		while (m_Running)
		{
		
			m_Window->OnUpdate();
			glClearColor(0.3, 0.5, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (auto layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			auto [x, y] = Input::GetMousePosition();
			PS_CORE_TRACE("{0} {1}", x, y);

		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
