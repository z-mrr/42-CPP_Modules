#ifndef SCALARCONVERTER_CPP
#define SCALARCONVERTER_CPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

using std::string;
using std::cout;

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	UNKNOWN
};

class ScalarConverter
{
public:
	static void	convert(const string&);



private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	ScalarConverter&	operator=(const ScalarConverter&);

	static void			parseType(const string&);
	static bool 		isPseudo(const string&);
	static bool			isChar(const string&);
	static bool			isInt(const string&);
	static bool			isFloat(const string&);
	static bool			isDouble(const string&);
	static bool			overLimit(const string&, Type type = _type);
	static void			convertChar(const string&);
	static void			convertInt(const string&);
	static void			convertFloat(const string&);
	static void			convertDouble(const string&);

	static Type			_type;

	class	OverLimitException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class	UnknownTypeException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
