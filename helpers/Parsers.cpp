#include "Parsers.hpp"

#include <iomanip>

int Parser<int>::parse(std::istream& is) {
	int out;

	is >> out;

	return out;
}

double Parser<double>::parse(std::istream& is) {
	double out;

	is >> out;

	return out;
}

std::string Parser<std::string>::parse(std::istream& is) {
	std::string out;

	is >> std::quoted(out);

	return out;
}
