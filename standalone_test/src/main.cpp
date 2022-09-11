#define USE_MODULE 1

/*
 * NOTE:
 * It looks like spdlog is not compatible with the latest format, which causes some conversions of format_string to fail, so we let spdlog use the built-in format.
 *
 * If headers are used, everything works as expected.
 *
 * If modules are used, and let spdlog use external (our provided) format, and don't use format_string (eg info("hello world")), compile will cause ICE.
 * If modules are used, and let spdlog use internal format, compiler will report `error LNK2019: unresolved external symbol __imp_MapViewOfFileNuma2`(from `MapViewOfFile2`), even info("hello world").
 */

#if USE_MODULE
// module
import my.project.logger;
using namespace my::project::logger;
using type_exist = test_export_type;
#else
// header
#include <spdlog/spdlog.h>
using namespace spdlog;
#endif

int main()
{
	info("int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
}
