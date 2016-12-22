#include <iostream>

#include "string.h"

int main() {
	const char *str = "Hallo WeWelt";
	const char *str2 = "Welt";

	const char *str3 = "HalloWWelt";
	const char *str4 = "erlt";

	const char *res = nullptr;
	const char *res2 = nullptr;

	std::cout << String::memchr(String::memchr(str3, 'W'), 'e') << std::endl;
	if ((res = String::strstr(str, str2)) != nullptr)
		std::cout << res << std::endl;
	if ((res2 = String::strstr(str3, str4)) != nullptr)
		std::cout << res2 << std::endl;

	return 0;
}
