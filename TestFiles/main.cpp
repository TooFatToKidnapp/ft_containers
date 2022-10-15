#include "./utils.hpp"

void header(std::string container) {

	std::string header = GREEN + container + " TESTS: " + CLEAR + "press enter to continue\n";
	int width = 100 - (header.length() / 2);

	cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;
	cout << std::setw(width) << header << std::endl;
	cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;

}

void print_title(std::string title, std::string sub) {
	cout << "\n";
	cout << YELLOW << title << ": " << CLEAR << sub << "\n\n";
}


int main() {

	header("VECTOR");
	while (std::cin.get() != '\n') {}
	vector_tests();
	cout << std::endl;
	header("STACK");
	while (std::cin.get() != '\n') {}
	stack_tests();
	cout << std::endl;
	header("MAP");
	while (std::cin.get() != '\n') {}
	map_tests();
	cout << std::endl;
	header("SET");
	while (std::cin.get() != '\n') {}
	set_tests();
	cout << std::endl;
}
