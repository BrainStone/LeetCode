#ifndef LEETCODE_PARSERS_HPP
#define LEETCODE_PARSERS_HPP

#include <istream>
#include <tuple>
#include <vector>

// Forward declaration
template <typename T>
T parse(std::istream& is);

// Helper struct
template <typename T>
struct Parser {
	static T parse(std::istream& is);
};

// Specialization for int
template <>
struct Parser<int> {
	static int parse(std::istream& is);
};

// Specialization for std::vector
template <typename T>
struct Parser<std::vector<T>> {
	static std::vector<T> parse(std::istream& is) {
		std::vector<T> out;
		decltype(is.get()) read_char;

		while (is.get() != '[')
			;

		do {
			out.push_back(Parser<T>::parse(is));

			do {
				read_char = is.get();
			} while ((read_char != ',') && (read_char != ']'));
		} while (read_char != ']');

		return out;
	}
};

// Usage
template <typename T>
T parse(std::istream& is) {
	return Parser<T>::parse(is);
}

// Tuple Parsing
template <typename... Ts>
struct ParseHelper;

template <typename T, typename... Rest>
struct ParseHelper<T, Rest...> {
	static std::tuple<T, Rest...> parseTuple(std::istream& is) {
		const std::tuple<T> first{parse<T>(is)};
		const std::tuple<Rest...> rest{ParseHelper<Rest...>::parseTuple(is)};

		return std::tuple_cat(first, rest);
	}
};

template <>
struct ParseHelper<> {
	static std::tuple<> parseTuple(std::istream& is [[maybe_unused]]) {
		return std::tuple<>{};
	}
};

template <typename... Ts>
std::tuple<Ts...> parseTuple(std::istream& is) {
	return ParseHelper<Ts...>::parseTuple(is);
}

#endif
