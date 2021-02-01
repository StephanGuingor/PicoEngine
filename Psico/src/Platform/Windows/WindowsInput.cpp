#include "pspch.h"
#include "WindowsInput.h"
#include "Psico/Application.h"
#include <GLFW/glfw3.h>

namespace Psico
{
	// should check if nullptr;
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());
	
		int state = glfwGetKey(window, keycode);
		return state & (GLFW_PRESS | GLFW_REPEAT);
	}
	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}
	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}
	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{

		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos,&yPos);
		return { (float)xPos,(float)yPos };
	}
}
