#pragma once

#include "Psico/Layer.h"
#include <Psico\Events\MouseEvent.h>
#include <Psico\Events\KeyEvent.h>
#include <Psico\Application.h>


namespace Psico
{
	class PSICO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		
		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		float m_Time = 0.0f;
		bool m_BlockEvents = true;
	private:
		void SetPsicoTheme();
	};
}


