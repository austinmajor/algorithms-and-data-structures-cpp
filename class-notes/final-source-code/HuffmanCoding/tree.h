#ifndef TREE_H
#define TREE_H

#include "node.h"

// bst denotes the binary search tree namespace.
namespace bst {

	// Tree represents a binary search tree.
	class Tree {
		protected:
			Node* _head;

			void _deallocate();
			void _allocate(const Tree&);
		public:
			// Constructors
			Tree();
			Tree(Node*&);

			// Rule of Three
			~Tree();
			Tree(const Tree&);
			const Tree& operator=(const Tree&);
	};
};

#endif
