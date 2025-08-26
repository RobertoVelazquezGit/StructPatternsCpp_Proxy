
#include <iostream>

#include "Employee.h"
#include "RepoProxy.h"
#include "Repository.h"

// Only one of them
//#define ENABLE_WITHOUT_PROTECTION_PROXY
#define ENABLE_WITH_PROTECTION_PROXY

int main()
{
#ifdef ENABLE_WITHOUT_PROTECTION_PROXY
	try {
		Repository repo{ R"(./)" };
		Employee e1{ "Umar", "Manager" };
		Employee e2{ "Ayaan", "Programmer" };
		Employee e3{ "Raihaan", "Architect" };

		repo.SetUser(&e2);
		repo.CreateFile("data.txt");

		repo.UpdateFile("data.txt");
		//repo.DeleteFile("data.txt");
		repo.ViewFile("data.txt");
	}
	catch (std::exception& ex) {
		std::cout << "[Exception]" << ex.what() << std::endl;
	}
#endif

#ifdef ENABLE_WITH_PROTECTION_PROXY
	try {
		RepoProxy repo{ R"(./)" };
		repo.SetAuthorizedList({ "Manager", "Architect" });
		Employee e1{ "Umar", "Manager" };
		Employee e2{ "Ayaan", "Programmer" };
		Employee e3{ "Raihaan", "Architect" };

		//repo.SetUser(&e2);  // programamer not authorized to create a file
		repo.SetUser(&e1);
		repo.CreateFile("data.txt");

		repo.UpdateFile("data.txt");
		repo.DeleteFile("data.txt");
		//repo.ViewFile("data.txt");
	}
	catch (std::exception& ex) {
		std::cout << "[Exception]" << ex.what() << std::endl;
	}
#endif

}

