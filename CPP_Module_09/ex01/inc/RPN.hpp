#ifndef _RPN_
#define _RPN_

#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>

using std::string;
using std::stack;
using std::cout;

enum	TokenType {
	DIGIT,
	OPERATOR,
	SPACE,
	INVALID
};

class RPN {
public:
	RPN(const char* input);
	~RPN();

	TokenType	tokenType(char) const;
	void		validate(unsigned int) const;
	int	process();

private:
	RPN();
	RPN(const RPN&);
	RPN&	operator=(const RPN&);

	stack<int>	_op;
	string		_exp;
};

#endif
