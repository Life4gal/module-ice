export module my.project.logger;

#include <project/macro.hpp>

GSL_DISABLE_WARNING_PUSH

GSL_DISABLE_WARNING(5105) // https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/c5105?view=msvc-170
GSL_DISABLE_WARNING(4005) // https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-1-c4005?view=msvc-170

#ifndef GSL_NO_LOGGER
	import <spdlog/spdlog.h>;
	#define GSL_LOGGER_DO(...) __VA_ARGS__
#else
	#define GSL_LOGGER_DO(...)
#endif

GSL_DISABLE_WARNING_POP

namespace my::project::logger
{
	namespace logger_detail
	{
#ifndef GSL_NO_LOGGER
		template<typename... Args>
		using format_string_t = spdlog::format_string_t<Args...>;
#else
		template<typename... Args>
		struct format_string_t
		{
		};
#endif
	}// namespace logger_detail

	export
	{
		using test_export_type = int;

		template<typename... Args>
		void trace([[maybe_unused]] logger_detail::format_string_t<Args...> fmt, [[maybe_unused]] Args && ... args)
		{
			GSL_LOGGER_DO(spdlog::trace(fmt, std::forward<Args>(args)...);)
		}

		template<typename... Args>
		void debug([[maybe_unused]] logger_detail::format_string_t<Args...> fmt, [[maybe_unused]] Args && ... args)
		{
			GSL_LOGGER_DO(spdlog::debug(fmt, std::forward<Args>(args)...));
		}

		template<typename... Args>
		void info([[maybe_unused]] logger_detail::format_string_t<Args...> fmt, [[maybe_unused]] Args && ... args)
		{
			GSL_LOGGER_DO(spdlog::info(fmt, std::forward<Args>(args)...));
		}

		template<typename... Args>
		void warn([[maybe_unused]] logger_detail::format_string_t<Args...> fmt, [[maybe_unused]] Args && ... args)
		{
			GSL_LOGGER_DO(spdlog::warn(fmt, std::forward<Args>(args)...));
		}

		template<typename... Args>
		void error([[maybe_unused]] logger_detail::format_string_t<Args...> fmt, [[maybe_unused]] Args && ... args)
		{
			GSL_LOGGER_DO(spdlog::error(fmt, std::forward<Args>(args)...));
		}

		template<typename... Args>
		void critical([[maybe_unused]] logger_detail::format_string_t<Args...> fmt, [[maybe_unused]] Args && ... args)
		{
			GSL_LOGGER_DO(spdlog::critical(fmt, std::forward<Args>(args)...));
		}

		// constexpr int logger_fatal_exit_code = -42;

		template<typename... Args>
		void fatal([[maybe_unused]] logger_detail::format_string_t<Args...> fmt, [[maybe_unused]] Args && ... args)
		{
			critical(fmt, std::forward<Args>(args)...);
			// std::exit(logger_fatal_exit_code);
			throw std::runtime_error{"Fatal Error."};
		}
	}
}
