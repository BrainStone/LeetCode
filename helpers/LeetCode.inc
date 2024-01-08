#ifndef LEETCODE_LEETCODE_INC
#define LEETCODE_LEETCODE_INC

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
#include <tuple>
#include <vector>

#include "LeetCode.hpp"

template <typename... Ts>
class TestCaseParser {
private:
	std::vector<std::tuple<std::decay_t<Ts>...>> testCases;

public:
	explicit TestCaseParser(std::string_view testCasesStr) {
		;
	}

	void runTestCases(std::function<LEETCODE_PROBLEM_RETURNTYPE(LEETCODE_PROBLEM_ARGTYPES)> func) {
		const std::size_t length = this->testCases.size();

		for (std::size_t tcase = 0; tcase < length; ++tcase) {
			std::cout << "Test Case " << tcase + 1 << ":\nResult: " << std::apply(func, this->testCases[tcase]);
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
