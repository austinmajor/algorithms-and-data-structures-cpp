#include <queue>
#include <map>
#include <string>

#include "huffman.h"

// Public Member Functions

std::map<char, std::string> bst::Huffman::charToCodes() {
	std::map<char, std::string> m;

	this->_constructCharToCodes(this->_head, "", m);

	return m;
}

std::map<std::string, char> bst::Huffman::codesToChar() {
	std::map<std::string, char> m;

	this->_constructCodesToChar(this->_head, "", m);

	return m;
}

// Private Member Functions

void bst::Huffman::_constructCharToCodes(bst::Node* root, std::string code, std::map<char, std::string>& fm) { 
    if (!root) return;

    if (root->getData() != nullptr) {
	    fm.insert(std::make_pair(root->getDataValue(), code));
    }
  
    this->_constructCharToCodes(root->getLeft(), code + "0", fm);
    this->_constructCharToCodes(root->getRight(), code + "1", fm);
}

void bst::Huffman::_constructCodesToChar(bst::Node* root, std::string code, std::map<std::string, char>& m) { 
    if (!root) return;

    if (root->getData() != nullptr) {
	    m.insert(std::make_pair(code, root->getDataValue()));
    }
  
    this->_constructCodesToChar(root->getLeft(), code + "0", m);
    this->_constructCodesToChar(root->getRight(), code + "1", m);
}

// Constructors

bst::Huffman::Huffman(char symbols[], int frequencies[], int size) {
	std::priority_queue<bst::Node*, std::vector<bst::Node*>, bst::compare> trees;

	for(int i = 0; i < size; i++) {
		trees.push(new bst::Node(&symbols[i], frequencies[i]));
	}

	bst::Node* left;
	bst::Node* right;
	bst::Node* internal;

	int joinedFrequencies;

	// Iterate until there is one tree (one head node)
	while(trees.size() != 1) {
		left = trees.top();
		trees.pop();

		right = trees.top();
		trees.pop();

		joinedFrequencies = left->getFreq() + right->getFreq();

		// internal has a nullptr as the character because it is an internal node,
		// not a leaf node.
		internal = new bst::Node(nullptr, joinedFrequencies, left, right);

		trees.push(internal);
	}

	// Set the head node of the tree to the master node.
	this->_head = trees.top();
}
