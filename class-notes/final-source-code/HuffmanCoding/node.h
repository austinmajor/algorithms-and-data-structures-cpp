#ifndef NODE_H
#define NODE_H

// bst denotes the binary search tree namespace.
namespace bst {

	// Node represents a node in a binary search tree.
	class Node {
		private:
			char* _data;
			int _freq;
			Node* _left;
			Node* _right;

			void _deallocate();
			void _allocate(const Node&);
		public:
			// Constructors
			Node();
			Node(char*, int);
			Node(char*, int, Node*, Node*);

			// Rule of Three
			~Node();
			Node(const Node&);
			const Node& operator=(const Node&);

			// Getters and Setters
			char* getData();
			void setData(char*);
			int getFreq();
			void setFreq(int);
			Node* getLeft();
			void setLeft(Node*);
			Node* getRight();
			void setRight(Node*);

			// Member Functions
			char getDataValue();
			
			bool hasLeft();
			bool hasRight();
			bool isLeaf();
	};

	// compare allows the usage of priority_queue to order nodes according
	// to frequencies.
	struct compare {
		bool operator()(Node* left, Node* right) {
			return (left->getFreq() > right->getFreq());
		}
	};
};

#endif

