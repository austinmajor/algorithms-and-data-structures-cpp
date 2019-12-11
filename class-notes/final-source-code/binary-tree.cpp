// 20191028_binaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

struct Node {
	char ch;
	Node* left;
	Node* right;
	Node(char ch) : ch(ch), left(nullptr), right(nullptr) {}
};

void pre_order(Node* root) {
	if (root) {
		std::cout << root->ch << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(Node* root) {
	if (root) {
		in_order(root->left);
		std::cout << root->ch << " ";
		in_order(root->right);
	}
}

void post_order(Node* root) {
	if (root) {
		post_order(root->left);
		post_order(root->right);
		std::cout << root->ch << " ";
	}
}

int main()
{
	Node* root = new Node('A');

	root->left = new Node('B');
	root->right = new Node('C');

	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->left = new Node('F');
	root->right->right = new Node('G');

	in_order(root);
	std::cout << "\n";
}
