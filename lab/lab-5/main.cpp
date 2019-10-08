#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>

std::string removeStrings(std::string input) {
	std::stringstream ss;

	for(char c : input) {
		if(c != ' ') {
			ss << c;
		}
	}

	return ss.str();
}

int opPrecedence(char c) {
	switch(c) {
		case '^':
			return 4;
		case '*':
			return 3;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 0;
		default:
			return -1;
	}
}

std::string InfixToPostfix(std::string infix) {
	std::stringstream ss;
	std::stack<char> st;
	infix = removeStrings(infix);

	for(char c : infix) {
		if(isdigit(c)) {
			ss << c;
		} else {
			// Open parenthesis
			if(c == '(') st.push(c);
			else if(c == ')') {
				// Close parenthesis

				while(true) {
					if(st.top() == '(') {
						st.pop();
						break;
					}

					ss << st.top();
					st.pop();
				}
			} else {
				// Operands

				if(st.size() == 0 || st.top() == '(') st.push(c);
				else if(opPrecedence(c) > opPrecedence(st.top())) st.push(c);
				else {
					while(st.size() > 0 && opPrecedence(st.top()) >= opPrecedence(c)) {
						ss << st.top();
						st.pop();
					}
					st.push(c);
				}
			}
		}
	}

	while(st.size() > 0) {
		ss << st.top();
		st.pop();
	}

	return ss.str();
}

int main () {
	std::string firstExample = "3 * 4 + 5";
	std::string secondExample = "3 + 4 * 5";
	std::string thirdExample = "(3 + 4) * (5 + 6)";

	std::cout << firstExample << " -> " << InfixToPostfix(firstExample) << std::endl;
	std::cout << secondExample << " -> " << InfixToPostfix(secondExample) << std::endl;
	std::cout << thirdExample << " -> " << InfixToPostfix(thirdExample) << std::endl;
}
