#ifndef LEETCODE_LEETCODE_HPP
#define LEETCODE_LEETCODE_HPP

// I know both of these are terrible practice, but it's what is pre-included by LeetCode.
// You can disable LOCALLY by defining `LEETCODE_DISABLE_AUTO_STD`
#ifndef LEETCODE_DISABLE_AUTO_STD
#include <bits/stdc++.h>

using namespace std;
#endif

// LeetCode specific stuff
#include <string>

#include "ExtraTypes.hpp"

const extern std::string TestCases;

// Helper
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& iterable);

#endif
