#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class InfixToPostfix {
public:
	string postfix;

	int Prec(char op) {															//determines priority of the operator
		if (op == '+' || op == '-') {
			return 1;
		}
		if (op == '*' || op == '/') {
			return 2;
		}
		return 0;
	}

	void Convert(const string& infix) {
		stack<char> operators;													//create stack for operators
		postfix = "";															//clear postfix string
		for (char c : infix) {													//for each character in the input
			if (isalnum(c)) {													//if c is an alpha character
				postfix += c;													//append character to postfix string
			}
			else if (c == '(') {												//else if c = '('
				operators.push(c);												//push c onto stack
			}
			else if (c == ')') {												//else if c = ')'
				if (!operators.empty()) {										//if stack is not empty
					while (operators.top() != '(') {							//while top of stack does not equal '('
						postfix += operators.top();								//append top of operators to postfix
						operators.pop();										//pop operators
					}
					operators.pop();											//pop '('
				}
			}
			else if (c == ' ') {												//else if c = ' '
				continue;														//continue to next character
			}
			else {																//else
				while (!operators.empty() && Prec(c) <= Prec(operators.top())) {//while operators is not empty
					postfix += operators.top();									//append top of operators to postfix
					operators.pop();											//pop operators
				}
				operators.push(c);												//push string operator onto stack
			}
		}
		while (!operators.empty()) {											//while stack is not empty
			postfix += operators.top();											//append remaining operators to postfix
			operators.pop();													//pop operators
		}
	}
};
