#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog//sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace Psico
{
	class PSICO_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Sould Wrap in another macro (CORE)

#define PS_CORE_TRACE(...) ::Psico::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PS_CORE_INFO(...) ::Psico::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PS_CORE_WARN(...) ::Psico::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PS_CORE_ERROR(...) ::Psico::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PS_CORE_FATAL(...) ::Psico::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros

#define PS_TRACE(...) ::Psico::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PS_INFO(...) ::Psico::Log::GetClientLogger()->info(__VA_ARGS__)
#define PS_WARN(...) ::Psico::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PS_ERROR(...) ::Psico::Log::GetClientLogger()->error(__VA_ARGS__)
#define PS_FATAL(...) ::Psico::Log::GetClientLogger()->fatal(__VA_ARGS__)

