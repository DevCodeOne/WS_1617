#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <initializer_list>
#include <iostream>

#include "lzw.h"

std::string encode_string(std::string to_encode, std::initializer_list<std::string> init_directory) {
	int next_key = 0;
	std::map<std::string, int> directory;

	auto init_directory_it = init_directory.begin();

	while (init_directory_it != init_directory.end())
		directory.insert({*init_directory_it++, next_key++});

	auto input_it = to_encode.begin();

	std::string input;
	std::ostringstream encoded_string;

	while (input_it != to_encode.end()) {
		input += *input_it;

		if (directory.find(input) == directory.end()) {
			directory.insert({input, next_key++});
			char new_input = input.back();
			input.pop_back();
			encoded_string << directory[input] << " ";
			input = new_input;
		}

		if (++input_it == to_encode.end())
			encoded_string << directory[input] << " ";
	}

	return encoded_string.str();
}

std::string decode_string(std::string to_decode, std::initializer_list<std::string> init_directory) {
	int next_key = 0;
	std::map<std::string, int> directory;
	std::vector<std::string> decoded_symbols;

	auto init_directory_it = init_directory.begin();

	while (init_directory_it != init_directory.end()) {
		decoded_symbols.push_back(*init_directory_it);
		directory.insert({*init_directory_it, next_key});
		++init_directory_it;
		++next_key;
	}

	std::istringstream to_decode_stream(to_decode);

	int in_character;
	std::string input;
	std::ostringstream decoded_string;

	while (to_decode_stream >> in_character) {
		decoded_string << decoded_symbols[in_character] << " ";

                input += decoded_symbols[in_character][0];
                if (directory.find(input) == directory.end()) {
                    directory.insert({input, next_key++});
                    decoded_symbols.push_back(input);
                    input = decoded_symbols[in_character];
                }

	}

	return decoded_string.str();
}
