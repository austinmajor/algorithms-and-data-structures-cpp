// 20191104_bst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
	int data; 
	Node* left; 
	Node* right; 
	Node(int num) : data(num), left(nullptr), right(nullptr) {}
};

using NodePtr = Node *; 

void pre_order(Node* root) {
	if (root) {
		std::cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(Node* root) {
	if (root) {
		in_order(root->left);
		std::cout << root->data << " ";
		in_order(root->right);
	}
}

void post_order(Node* root) {
	if (root) {
		post_order(root->left);
		post_order(root->right);
		std::cout << root->data << " ";
	}
}


void insert1(NodePtr& p, int val) {
	if (!p) {
		p = new Node(val);
		return;
	}

	if (p->data < val)
		insert1(p->right, val);
	else if (p->data > val)
		insert1(p->left, val);

	// when data == val, return implicitly
}

NodePtr insert2(NodePtr& p, int val) {
	if (!p) 
		return new Node(val);

	if (p->data < val)
		p->right = insert2(p->right, val);
	else if (p->data > val)
		p->left = insert2(p->left, val);
	
	return p; 
}

bool search1(NodePtr p, int val) {
	if (!p)
		return false; 
	if (p->data < val)
		return search1(p->right, val);
	else if (p->data > val)
		return search1(p->left, val);

	return true; 
}

NodePtr search2(NodePtr p, int val) {
	if (!p)
		return nullptr;
	if (p->data < val)
		return search2(p->right, val);
	else if (p->data > val)
		return search2(p->left, val);

	return p;
}


int largestLeft(NodePtr p);



NodePtr del(NodePtr& p, int num) {
	// target not found 
	if (!p) {
		std::cerr << "Target not found. " << std::endl;
		return nullptr;
	}

	if (num < p->data) {
		p->left = del(p->left, num);
	}
	else if (num > p->data) {
		p->right = del(p->right, num);
	}
	else {		// on the node to be del 
		if (p->left == nullptr && p->right == nullptr) {	// case: when the node is a leaf node
			delete p;
			return nullptr;
		}
		else if (p->left == NULL) {		// case: when the node has right child node
			Node* temp = p->right;
			delete p;
			return temp;
		}
		else if (p->right == NULL) {	// case: when the node has left child node 
			Node* temp = p->left;
			delete p;
			return temp;
		}
		else {							// when the node has two child nodes
			p->data = largestLeft(p->left);
			p->left = del(p->left, p->data);
		}
	} 
	return p;
}

// pre-condition: p is not NULL; 
int largestLeft(NodePtr p) {
	if (!p) {
		std::cerr << "nullptr passed to largetstLeft(). " << std::endl;
		exit(1);
	}
	
	int result = p->data;	
	while (p) {
		result = p->data;
		p = p->right;
	}
	return result;
}




int main()
{
	NodePtr root = nullptr; 
	int values[14] = { 11, 6, 8, 19, 4, 10, 5, 17, 43, 49, 31, 2, 7, 42 };

	for(int i : values)
		insert1(root, i);

	/*pre_order(root);
	std::cout << "\n";
	in_order(root);
	std::cout << "\n";
	post_order(root);
	std::cout << "\n";
*/


	//NodePtr root2 = nullptr; 
	//int values2[] = { 5, 1, 10, 6 };
	//for (int i : values2)
	//	root2 = insert2(root2, i);

	//in_order(root2);

	using std::cout;
	using std::endl;

	cout << search1(root, 18) << endl; 
	cout << search1(root, 7) << endl;

	cout << search2(root, 18) << endl;
	cout << search2(root, 7) << endl;

	del(root, 11);
	in_order(root);
	std::cout << "\n";

	del(root, 2);
	in_order(root);
	std::cout << "\n";

	del(root, 49);
	in_order(root);
	std::cout << "\n";

	del(root, 100);
	in_order(root);
	std::cout << "\n";


}

