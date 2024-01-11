#include "ExtraTypes.hpp"

ListNode::ListNode() : val(0), next(nullptr) {}

ListNode::ListNode(int x) : val(x), next(nullptr) {}

ListNode::ListNode(int x, ListNode* next) : val(x), next(next) {}

std::ostream& operator<<(std::ostream& os, const ListNode* node) {
	bool first = true;

	os << '[';

	while (node != nullptr) [[likely]] {
		if (first) [[unlikely]] {
			first = false;
		} else [[likely]] {
			os << ", ";
		}

		os << node->val;

		node = node->next;
	}

	os << ']';

	return os;
}

// Parsers
ListNode* Parser<ListNode*>::parse(std::istream& is) {
	ListNode* out = nullptr;
	ListNode* current = nullptr;
	ListNode* tmp;
	decltype(is.get()) read_char;

	while (is.get() != '[')
		;

	do {
		tmp = new ListNode(Parser<int>::parse(is));

		if (out == nullptr) [[unlikely]] {
			out = tmp;
		} else {
			current->next = tmp;
		}

		current = tmp;

		do {
			read_char = is.get();
		} while ((read_char != ',') && (read_char != ']'));
	} while (read_char != ']');

	return out;
}
