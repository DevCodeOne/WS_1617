#include <iostream>

class experiment {
	public : 
		static void main() {
			std::cout << "Compiler version : " << __cplusplus << std::endl;
		}
};

int main() {
	experiment::main();
	return 0;
}
