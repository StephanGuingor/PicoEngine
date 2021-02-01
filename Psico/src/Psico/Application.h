#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Window.h"
#include "Input.h"
namespace Psico
{
	class PSICO_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};
	// To be defined in client
	Application* CreateApplication();
}


