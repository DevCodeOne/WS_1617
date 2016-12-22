#include <iostream>

#include "string.h"

void String::replace(std::string& s, const std::string& what, const std::string& with) {
    auto pos = s.find(what);
    if (pos != std::string::npos) {
        s.replace(pos, what.length(), with);
    }
}

size_t String::strlen(const char *str) {
	const char *it = str;
	while(*it) ++it;

	return it - str;
}

int String::hash(const char *str) {
	const char *it = str;
	int hash = 0;

	while(*it) {
		hash = 31 * hash + *it;
		++it;
	}
	
	return hash;
}

const char *String::memchr(const char *str, char value) {
	if (!str)
		return nullptr;

	const char *it = str;
	while(*it && *it != value) {	
		++it;
	}

	return *it == value ? it : nullptr;
}

const char *String::strstr(const char *search_in, const char *search_for) {
	if (!search_in || !search_for) 
		return nullptr;

	const char *it = search_in;
	bool found = false;

	while(*it) {	
		if (*it == *search_for) {
			const char *it_cpy = it;
			const char *it2 = search_for;
			found = true;
			while (*it_cpy && *it2) {
				if (*it_cpy != *it2) {
					found = false;	
					break;
				}

				++it_cpy;
				++it2;
			}
		}

		if (found) 
			break;

		++it;
	}

	return found ? it : nullptr;
}
