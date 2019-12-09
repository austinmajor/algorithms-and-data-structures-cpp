#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <map>
#include <string>

#include "tree.h"
#include "node.h"

// bst denotes the binary search tree namespace.
namespace bst {

	// Huffman represents a specific type of binary search tree, which
	// explains why it is a child of the Tree class.
	class Huffman : public Tree {
		private:
			// Hide default constructor
			Huffman();

			// Private Member Functions
			void _constructCharToCodes(Node*, std::string, std::map<char, std::string>&);
			void _constructCodesToChar(Node*, std::string, std::map<std::string, char>&);
		public:
			// Constructor
			Huffman(char[], int[], int);

			// Public Member Functions
			std::map<char, std::string> charToCodes();
			std::map<std::string, char> codesToChar();
	};
};

#endif
