#ifdef NO_INCLUDE_DIR
#include "tmr_logger.h"
#else
#include "tmr/tmr_logger.h"
#endif

#include <iostream>

void _default_print_debug(const std::string &msg)
{
	std::cout << "\033[0;90m[DEBUG] " << msg << "\033[0m\n"; //gray
}
void _default_print_info(const std::string &msg)
{
	std::cout << "[ INFO] " << msg << "\n";
}
void _default_print_warn(const std::string &msg)
{
	std::cout << "\033[0;33m[ WARN] " << msg << "\033[0m\n"; //yellow
}
void _default_print_error(const std::string &msg)
{
	std::cout << "\033[0;31m[ERROR] " << msg << "\033[0m\n"; //red
}
void _default_print_fatal(const std::string &msg)
{
	std::cout << "\033[0;31m[FATAL] " << msg << "\033[0m\n"; //red
}

namespace tmr
{

logger & logger::ref()
{
	static logger _logger;
	return _logger;
}
logger::logger()
{
	setup_level(level::INFO);
	setup_debug(_default_print_debug);
	setup_info( _default_print_info);
	setup_warn( _default_print_warn);
	setup_error(_default_print_error);
	setup_fatal(_default_print_fatal);
}

}