#include "node.h"

// Private Member Functions

void bst::Node::_deallocate() {
	delete this->_left;
	delete this->_right;
}

void bst::Node::_allocate(const bst::Node& n) {
	bst::Node left = *n._left;
	bst::Node right = *n._right;

	this->_left = &left;
	this->_right = &right;
}

// Constructors

bst::Node::Node() : _data(nullptr), _freq(0), _left(nullptr), _right(nullptr) {}
bst::Node::Node(char* c, int f) : _data(c), _freq(f), _left(nullptr), _right(nullptr) {}
bst::Node::Node(char* c, int f, bst::Node* l, bst::Node* r) : _data(c), _freq(f), _left(l), _right(r) {}

// Rule of Three

bst::Node::~Node() {
	this->_deallocate();
}

bst::Node::Node(const bst::Node& n) {
	this->_allocate(n);
}

const bst::Node& bst::Node::operator=(const bst::Node& n) {
	if(this != &n) {
		this->_deallocate();
		this->_allocate(n);
	}

	return *this;
}

// Getters and Setters

char* bst::Node::getData() {
	return this->_data;
}

void bst::Node::setData(char* c) {
	this->_data = c;
}

int bst::Node::getFreq() {
	return this->_freq;
}

void bst::Node::setFreq(int f) {
	this->_freq = f;
}

bst::Node* bst::Node::getLeft() {
	return this->_left;
}

void bst::Node::setLeft(bst::Node* l) {
	this->_left = l;
}

bst::Node* bst::Node::getRight() {
	return this->_right;
}

void bst::Node::setRight(bst::Node* r) {
	this->_right = r;
}

// Public Member Functions

char bst::Node::getDataValue() {
	return *this->_data;
}

bool bst::Node::hasLeft() {
	return this->_left != nullptr;
}

bool bst::Node::hasRight() {
	return this->_right != nullptr;
}

bool bst::Node::isLeaf() {
	return (this->hasLeft() && this->hasRight());
}
