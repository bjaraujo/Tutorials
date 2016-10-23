
#include <iostream>
#include <string>
#include <regex>

void main() {

	std::string str;

	while (true) {

		std::cin >> str;
		//std::regex e("abc.", std::regex_constants::icase);      // '.' Any character except new line
		//std::regex e("abc?", std::regex_constants::icase);      // '?' Zero or preceding character
		//std::regex e("abc*", std::regex_constants::icase);      // '*' Zero or more preceding character
		//std::regex e("abc+", std::regex_constants::icase);      // '+' One or more preceding character
		//std::regex e("ab[cd]*", std::regex_constants::icase);   // '[]' Any character inside brackets
		std::regex e("ab[^cd]*", std::regex_constants::icase);    // '[]' Any character not inside brackets

		bool match = std::regex_match(str, e);

		std::cout << (match ? "Matched" : "Not matched") << std::endl;

	}

}