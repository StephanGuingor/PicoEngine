#include "pspch.h"
#include "LayerStack.h"

// If someone pops layer it will not be deleted

namespace Psico
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();

	}

	LayerStack::~LayerStack()
	{

	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		// if you pop overlay?               // m_LayerInsert.end()?
		auto it = std::find(m_Layers.begin(), m_LayerInsert, layer);
		if (it != m_LayerInsert)
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_LayerInsert, m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
}

