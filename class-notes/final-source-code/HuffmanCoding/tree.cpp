#include "tree.h"
#include "node.h"

// Protected Member Functions

void bst::Tree::_deallocate() {
	delete this->_head;
}

void bst::Tree::_allocate(const bst::Tree& t) {
	bst::Node head = *t._head; 

	this->_head = &head;
}

// Constructors

bst::Tree::Tree() : _head(nullptr) {}
bst::Tree::Tree(bst::Node*& head) : _head(head) {}

// Rule of Three

bst::Tree::~Tree() {
	this->_deallocate();
}

bst::Tree::Tree(const bst::Tree& t) {
	this->_allocate(t);
}

const bst::Tree& bst::Tree::operator=(const Tree& t) {
	if(this != &t) {
		this->_deallocate();
		this->_allocate(t);
	}

	return *this;
}
