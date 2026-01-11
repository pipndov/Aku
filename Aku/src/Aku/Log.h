#pragma once
#pragma warning(push)
#pragma warning(disable:4251)

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include "Core.h"


namespace Aku {
	class AKU_API Log
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

// Core Log Macros
#define AKU_CORE_ERROR(...)    ::Aku::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AKU_CORE_WARN(...)     ::Aku::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AKU_CORE_INFO(...)     ::Aku::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AKU_CORE_TRACE(...)    ::Aku::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AKU_CORE_FATAL(...)    ::Aku::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define AKU_ERROR(...)         ::Aku::Log::GetClientLogger()->error(__VA_ARGS__)
#define AKU_WARN(...)          ::Aku::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AKU_INFO(...)          ::Aku::Log::GetClientLogger()->info(__VA_ARGS__)
#define AKU_TRACE(...)         ::Aku::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AKU_FATAL(...)         ::Aku::Log::GetClientLogger()->fatal(__VA_ARGS__)




