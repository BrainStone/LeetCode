#ifndef LEETCODE_LEETCODE_INC
#define LEETCODE_LEETCODE_INC

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This file is an .inc file and not a .cpp file because we need access the Solution class and the entry point and can't
// forward declare it. The only way to work around this is by just making a .inc file and including it after the
// Solution class.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LEETCODE_PROBLEM_FUNCNAME
#define LEETCODE_PROBLEM_FUNCNAME not_defined
#endif

#ifndef LEETCODE_PROBLEM_RETURNTYPE
#define LEETCODE_PROBLEM_RETURNTYPE int
#endif

#ifndef LEETCODE_PROBLEM_ARGTYPES
#define LEETCODE_PROBLEM_ARGTYPES
#endif

#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

#include "LeetCode.hpp"
#include "Parsers.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& iterable) {
	bool first = true;

	os << '[';

	for (const auto& elem : iterable) {
		if (first) [[unlikely]] {
			first = false;
		} else [[likely]] {
			os << ", ";
		}

		os << elem;
	}

	os << ']';

	return os;
}

template <typename... Ts>
class TestCaseParser {
private:
	std::vector<std::tuple<std::decay_t<Ts>...>> testCases;

public:
	explicit TestCaseParser(const std::string& testCasesStr) {
		std::istringstream tcss{testCasesStr};
		decltype(tcss.peek()) ch;

		// Ensure we're skipping whitespace
		tcss >> std::skipws;

		while (tcss.good()) {
			testCases.push_back(parseTuple<std::decay_t<Ts>...>(tcss));

			// Clear all whitespace
			while (((ch = tcss.peek()) != EOF) && isspace(ch)) {
				tcss.ignore();
			}
		}

		testCases.shrink_to_fit();
	}

	void runTestCases(std::function<LEETCODE_PROBLEM_RETURNTYPE(LEETCODE_PROBLEM_ARGTYPES)> func) {
		const std::size_t length = this->testCases.size();

		for (std::size_t tcase = 0; tcase < length; ++tcase) {
			std::cout << "Test Case " << tcase + 1 << ":\nResult: " << std::apply(func, this->testCases[tcase]) << '\n'
			          << std::endl;
		}
	}
};

int main() {
	TestCaseParser<LEETCODE_PROBLEM_ARGTYPES> parser{TestCases};
	Solution solution;

	parser.runTestCases(std::bind_front(&Solution::LEETCODE_PROBLEM_FUNCNAME, solution));

	return 0;
}

#endif
