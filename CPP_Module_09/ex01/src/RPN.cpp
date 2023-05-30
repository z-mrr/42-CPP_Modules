#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const char* input) : _exp(input) {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& other) {
	static_cast<void>(other);
	return *this;
}

TokenType	RPN::tokenType(char c) const {
	if (std::isdigit(c))
		return DIGIT;
	else if (c == '+' || c == '-' || c == '*' || c == '/')
		return OPERATOR;
	else if (c == ' ')
		return SPACE;
	else
		return INVALID;
}

void	RPN::validate(unsigned int i) const {
	if (tokenType(_exp[i]) == INVALID)
		throw std::invalid_argument("Error");
	else if (!i) { // primeiro
		if (tokenType(_exp[i]) != DIGIT)
			throw std::invalid_argument("Error");
		else if (tokenType(_exp[i + 2]) != DIGIT)
			throw std::invalid_argument("Error");
	} else if (i == _exp.size() - 1) { // ultimo
		if (tokenType(_exp[i]) != OPERATOR)
			throw std::invalid_argument("Error");
		else if (tokenType(_exp[i - 1]) != SPACE)
			throw std::invalid_argument("Error");
	} else if (tokenType(_exp[i]) != SPACE && tokenType(_exp[i + 1]) != SPACE)
		throw std::invalid_argument("Error");
}

int	RPN::process() {
	for (unsigned int i = 0; _exp[i]; i++) {
		validate(i);
		if (tokenType(_exp[i]) == DIGIT)
			_op.push(_exp[i] - '0');
		else if(tokenType(_exp[i]) == OPERATOR) {
			int	op2 = _op.top();
			_op.pop();
			int	op1 = _op.top();
			_op.pop();
			if (_exp[i] == '+')
				_op.push(op1 + op2);
			else if (_exp[i] == '-')
				_op.push(op1 - op2);
			else if (_exp[i] == '/')
				_op.push(op1 / op2);
			else if (_exp[i] == '*')
				_op.push(op1 * op2);
		}
	}
	return _op.top();
}

// Start with an empty stack to hold the operands.
// Read the expression from left to right, one token at a time.
// If the token is an operand (a number), push it onto the stack.
// If the token is an operator, pop the top two operands from the stack.
// Apply the operator to the operands in the order they were popped (the second popped operand is the left-hand side, and the first popped operand is the right-hand side).
// Push the result of the operation back onto the stack.
// Repeat steps 3 to 6 until all tokens have been processed.
// The final result will be the only value remaining on the stack.
