// Utility functions for main header

module;

// INCLUDES

#include "cfg.h"
#include <iostream>

#ifdef _WIN32
#include <string>
#else // POSIX
#include <string.h>
#endif

export module utility;

namespace jinx
{
	/*
	Очистка экрана консоли
	*/
	export void clear_screen()
	{
#ifdef _WIN32
		std::system("cls");
#else
		// Assume POSIX
		std::system("clear");
#endif
	} // END OF clear_screen()

	/*
	Печать версий ПО
	*/
	export void get_version()

	{
		std::cout << " ----------------------------- INI PARSER ------------------------------\n";
		std::cout << "|     TEST VER: " << cfg::_VERSION << "                                                       |\n";
		std::cout << "|   PARSER VER: " << cfg::_PARSERVERSION << "                                                       |\n";
		std::cout << " -----------------------------------------------------------------------\n";
	}

} // END OF NAMESPACE