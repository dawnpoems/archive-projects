#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
	
	if (argc != 4) {
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::string outputFilename = filename + ".replace";

	std::ifstream file(filename.c_str());
	
	if (s1.empty()) {
		std::cout << "string to replace cannot be empty" << std::endl;
		return (1);
	}
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	std::ofstream output(outputFilename.c_str());
	if (!output.is_open()) {
		std::cout << "Error creating output file" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(file, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		output << line << std::endl;
	}

	file.close();
	output.close();
	return (0);
}
