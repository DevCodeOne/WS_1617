#include <iostream>

class experiment {
	public :
		void main();
};

void experiment::main() {
	std::cout << "Compiler version : " << __cplusplus << std::endl;
}

int main() {
	experiment e;
	e.main();
	return 0;
}
