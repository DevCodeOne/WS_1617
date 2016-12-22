#pragma once

#include <string>

class String {
public:
    static void replace(std::string& s, const std::string& what, const std::string& with);
    static size_t strlen(const char *str); 
    static const char *memchr(const char *str, char value);
    static const char *strstr(const char *search_in, const char *search_for);
    static int hash(const char *str);
};
