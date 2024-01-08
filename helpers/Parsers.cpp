#include "Parsers.hpp"

int Parser<int>::parse(std::istream& is) {
	int out;

	is >> out;

	return out;
}
