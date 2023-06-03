// Main function for parser test

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define RETURN_SUCCESS 0
#define RETURN_FAILURE 1

#include <iostream>

#ifdef _WIN32			// windows
#include <windows.h>
#include <string>
#include <cstdlib>
#else					// POSIX
#include <stdlib.h>
#include <string.h>
#endif 

import utility;
import parser;

int main(int argc, char* argv[])
{

	// CMD SETTINGS

#ifdef _WIN32					// Windows
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#else							// POSIX
	setlocale(LC_ALL, "Russian");
#endif

	// VARIABLES

	bool isInitSuccess = false;
	bool cmdArgs = false;
	std::string fileName;

	// SETUP

	jinx::clear_screen();

	jinx::get_version();

	std::cout << "\nWorking directory:\n\n";

#ifdef _WIN32					// Windows
	system("dir -R *");
#else							// POSIX
	system("ls -R *");
#endif

	std::cout << "\nLaunched as: ";

	for (int i = 0; i < argc; ++i)
	{
		std::cout << argv[i] << ' ';
	}

	std::cout << "\n\n";

	if (argc == 2)
	{
		cmdArgs = true;
		fileName = argv[1];

	}
	else
	{
		cmdArgs = false;
	}

	std::cout << "\n\n";

	// Manual input if not cmd args
	if (!cmdArgs)
	{
		std::cout << "> Input ini filename for processing: ";
		std::cin >> fileName;
	}

	std::cout << "\nINI file name is: " << fileName << '\n';

	// BODY

	while (!isInitSuccess)
	{		
		isInitSuccess = true;

		try
		{
			jinx::parser parser(fileName);

			std::cout << std::endl;

			std::cout << "> Content created in parser map, printing...\n\n";

			try
			{
				parser.print();
			}
			catch (const jinx::unknown_type& ex)
			{
				std::cout << ex.what();
			}
			catch (...)
			{
				std::cout << "> Unhandled exception!";
			}

			// ACTUAL OPERATIONS

			// auto value = parser.get_value<int>("section.value")
			// exception if no value of that type found, if any

			/*
			test file variable list:

			Section1.var1=5.0
			Section1.var2=какая-то строка
			Section1.var3=значение
			Section2.var1=1
			Section2.значение_2
			Section4.Mode=
			Section4.Vid=

			*/

			std::cout << "\n ----- Test operations and requests -----\n";

			try
			{
				std::cout << "\n\n> Trying get_value<int> Section1.var1";
				auto value = parser.get_value<int>("Section1.var1");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}

			std::cout << std::endl << " ------- ";

			try
			{
				std::cout << "\n\n> Trying get_value<double> Section1.var1";
				auto value = parser.get_value<double>("Section1.var1");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}

			std::cout << std::endl << " ------- ";

			try
			{
				std::cout << "\n\n> Trying get_value<double> Section1.var4";
				auto value = parser.get_value<double>("Section1.var4");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}

			std::cout << std::endl << " ------- ";

			try
			{
				std::cout << "\n\n> Trying get_value<std::string> Section1.var3";
				auto value = parser.get_value<std::string>("Section1.var3");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}

			std::cout << std::endl << " ------- ";

			try
			{
				std::cout << "\n\n> Trying get_value <std::string> Section4.Vid";
				auto value = parser.get_value<std::string>("Section4.Vid");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}		

			std::cout << std::endl << " ------- ";

			try
			{
				std::cout << "\n\n> Trying get_value <std::string> Section3.val1";
				auto value = parser.get_value<std::string>("Section3.val1");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}

			std::cout << std::endl << " ------- ";

			try
			{
				std::cout << "\n\n> Trying get_value<std::string> Section1.var2";
				auto value = parser.get_value<std::string>("Section1.var2");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}			

			std::cout << std::endl << " ------- ";

			try
			{
				std::cout << "\n\n> Trying get_value<unsigned short> Section1.var2";
				auto value = parser.get_value<unsigned short>("Section1.var2");
				std::cout << "\nReturn value: " << value;
			}
			catch (const jinx::data_not_found& ex)
			{
				std::cout << ex.what();
			}
			catch (const jinx::type_mismatch& ex)
			{
				std::cout << ex.what();
			}

			std::cout << "\n\n----------- END -------------\n\n";

		}
		catch (const jinx::file_not_found& ex)
		{
			std::cout << ex.what();
			isInitSuccess = false;
		}
		catch (const jinx::invalid_line& ex)
		{
			std::cout << ex.what();
			isInitSuccess = false;
		}
		catch (const jinx::invalid_section_name& ex)
		{
			std::cout << ex.what();
			isInitSuccess = false;
		}
		catch (const jinx::invalid_variable_name& ex)
		{
			std::cout << ex.what();
			isInitSuccess = false;
		}
		catch (...)
		{
			std::cout << "\n> Unknown Error!\n";
			isInitSuccess = false;
		}

		if (!isInitSuccess)
		{
			fileName.clear();
			std::cout << "\n> Repeat filename input: ";
			std::cin >> fileName;
		}

		std::cout << std::endl;

	} // while (!isInitSuccess)	

	// EXIT

	std::cout << std::endl;

#ifdef _WIN32			// windows
	system("pause");
#else					// POSIX
	std::cout << "Input any key to exit...\n";
	std::cin.get();
#endif 

	return EXIT_SUCCESS;

} // END OF main()