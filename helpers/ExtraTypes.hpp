#ifndef LEETCODE_EXTRATYPES_HPP
#define LEETCODE_EXTRATYPES_HPP

#include <iostream>

#include "Parsers.hpp"

struct ListNode {
	int val;
	ListNode* next;
	ListNode();
	explicit ListNode(int x);
	ListNode(int x, ListNode* next);

	friend std::ostream& operator<<(std::ostream& os, const ListNode* node);
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode();
	explicit TreeNode(int x);
	TreeNode(int x, TreeNode* left, TreeNode* right);
};

// Parsers
template <>
struct Parser<ListNode*> {
	static ListNode* parse(std::istream& is);
};

#endif
