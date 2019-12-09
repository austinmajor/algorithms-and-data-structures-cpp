// George Shaw
// g829g576
// Huffman Encoding

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "huffman.h"

int main() {
	std::map<char, int> freqMap;

	char ch;
	std::ifstream original = std::ifstream("alice.txt");

	if(!original.is_open()) {
		std::cerr << "error: unable to open alice.txt." << std::endl;
		return 1;
	}

	while(original >> std::noskipws >> ch) {
		// Look for character in map.
		std::map<char, int>::iterator itr = freqMap.find(ch);

		// If character is not found, add it and continue.
		if(itr == freqMap.end()) {
			freqMap.insert(std::make_pair(ch, 1));
			continue;
		}

		// Found element, increase its frequency by one.
		itr->second = itr->second + 1;
	}

	// Translate map into character and integer arrays.
	int size = freqMap.size();
	char symbols[size];
	int frequencies[size];

	int index = 0;
	for(std::map<char, int>::iterator itr = freqMap.begin(); itr != freqMap.end(); itr++) {
		symbols[index] = itr->first;
		frequencies[index] = itr->second;

		index++;
	}

	bst::Huffman h = bst::Huffman(symbols, frequencies, size);
	std::map<char, std::string> charToCodeMap = h.charToCodes();

	for(std::map<char, std::string>::iterator itr = charToCodeMap.begin(); itr != charToCodeMap.end(); itr++) {
		switch(itr->first) {
			case '\a':  std::cout << "\\a";      break;
			case '\b':  std::cout << "\\b";      break;
			case '\f':  std::cout << "\\f";      break;
			case '\n':  std::cout << "\\n";      break;
			case '\r':  std::cout << "\\r";      break;
			case '\t':  std::cout << "\\t";      break;
			case '\v':  std::cout << "\\v";      break;
			case '\\':  std::cout << "\\\\";     break;
			case '\'':  std::cout << "\\'";      break;
			case '\"':  std::cout << "\\\"";     break;
			case '\?':  std::cout << "\\\?";     break;
			default:    std::cout << itr->first; break;
		}

		std::cout << ": " << itr->second << std::endl;
	}

	std::fstream encoded = std::fstream("alice.encoded", std::ios::in | std::ios::out | std::ios::trunc);

	if(!encoded.is_open()) {
		std::cerr << "error creating or opening/truncating alice.encoded" << std::endl;
		return 1;
	}

	// Reset file pointer of the original file to the beginning
	original.clear();
	original.seekg(0, std::ios::beg);

	while(original >> std::noskipws >> ch) {
		encoded << charToCodeMap.find(ch)->second;
	}

	original.close();

	std::ofstream decoded = std::ofstream("alice.decoded", std::ios::trunc);
	
	// Reset file pointer of the encoded file to the beginning
	encoded.clear();
	encoded.seekg(0, std::ios::beg);

	std::map<std::string, char> codeToCharMap = h.codesToChar();
	std::map<std::string, char>::const_iterator probe;
	std::string currentCode = "";

	while(encoded >> ch) {
		currentCode += ch;

		probe = codeToCharMap.find(currentCode);
		if(probe != codeToCharMap.end()) {
			decoded << probe->second;
			currentCode = "";
		}
	}

	decoded.close();

	return 0;
}
