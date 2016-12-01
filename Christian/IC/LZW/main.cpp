#include <cstdlib>

#include <iostream>
#include <algorithm>

#include "lzw.h"

int main() {
	std::string to_encode = "01100110011001100110";
	std::string encoded_string = encode_string(to_encode, {"0", "1"});
	std::string decoded_string = decode_string(encoded_string, {"0", "1"});
	encoded_string.erase(std::remove(encoded_string.begin(), encoded_string.end(), ' '), encoded_string.end());
	decoded_string.erase(std::remove(decoded_string.begin(), decoded_string.end(), ' '), decoded_string.end());

	std::cout << "String to encode : " << to_encode << std::endl;
	std::cout << "Encoded String :   " << encoded_string << std::endl;
	std::cout << "Decoded String :   " << decoded_string << std::endl;

	return EXIT_SUCCESS;
}
