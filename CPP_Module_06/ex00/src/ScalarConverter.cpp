#include "ScalarConverter.hpp"

Type ScalarConverter::_type = UNKNOWN;

void	ScalarConverter::convert(const string& str)
{
	if (str.empty())
		return;
	parseType(str);
	switch (_type)
	{
		case CHAR:
			convertChar(str);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		case UNKNOWN:
			throw UnknownTypeException();
		default:
			return;
	}
}

void	ScalarConverter::parseType(const string& str)
{
	if (isChar(str))
		_type = CHAR;
	else if (isInt(str))
		_type = INT;
	else if (isFloat(str))
		_type = FLOAT;
	else if (isDouble(str))
		_type = DOUBLE;
	else if (isPseudo(str))
		_type = PSEUDO;
	else
	{
		_type = UNKNOWN;
		return;
	}
	if (overLimit(str))
		throw OverLimitException();
}

bool	ScalarConverter::isPseudo(const string& str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		cout << "char: impossible\n";
		cout << "int: impossible\n";
		cout << "float: " << str << '\n';
		cout << "double: " << str.substr(0, str.size() - 1) << '\n';
	}
	else if (str == "-inf" || str == "+inf" || str == "nan")
	{
		cout << "char: impossible\n";
		cout << "int: impossible\n";
		cout << "float: " << str + 'f' << '\n';
		cout << "double: " << str << '\n';
	}
	else
		return false;
	return true;
}

bool	ScalarConverter::isChar(const string& str)
{
	if (str.size() != 1 || std::isdigit(str[0]) || !std::isprint(str[0]))
		return false;
	else
		return true;
}

bool	ScalarConverter::isInt(const string& str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if (!i && str[i] == '-')
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const string& str)
{
	size_t	size = str.size();
	size_t	pos = str.find('.');
	if (size < 4 || str[size - 1] != 'f' || pos == string::npos || pos == 0 || pos == size - 2 || (pos == 1 && str[0] == '-'))
		return false;
	for (size_t i = 0; i < size - 1; i++)
	{
		if ((!i && str[i] == '-') || (i == pos && str[i] == '.'))
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const string& str)
{
	size_t	size = str.size();
	size_t	pos = str.find('.');
	if (size < 3 || pos == string::npos || pos == 0 || pos == size - 1 || (str[0] == '-' && pos == 1))
		return false;
	for (size_t i = 0; i < size; i++)
	{
		if ((!i && str[i] == '-') || (i == pos && str[i] == '.'))
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::overLimit(const string& str, Type type)
{
	long double	num = strtold(str.c_str(), NULL);
	switch(type)
	{
		case CHAR:
			if (!std::isprint(str[0]))
				return true;
			break;
		case INT:
			if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
				return true;
			break;
		case FLOAT: //min != lowest = -max
			if (std::abs(num) > std::numeric_limits<float>::max() || (num && std::abs(num) < std::numeric_limits<float>::min()))
				return true;
			break;
		case DOUBLE: // min != lowest = -max
			if (std::abs(num) > std::numeric_limits<double>::max() || (num && std::abs(num) < std::numeric_limits<double>::min()))
				return true;
			break;
		default:
			break;
	}
	return false;
}

const char* ScalarConverter::OverLimitException::what() const throw()
{
		return "Value over type limit\n";
}

const char* ScalarConverter::UnknownTypeException::what() const throw()
{
		return "Type isn't CHAR, INT, FLOAT or DOUBLE\n";
}

void	ScalarConverter::convertChar(const string& str)
{
	cout << "char: \'" << str << "\'\n";
	cout << "int: " << static_cast<int>(str[0]) << '\n';
	cout << std::fixed << std::setprecision(1);
	cout << "float: " << static_cast<float>(str[0]) << "f\n";
	cout << "double: " << static_cast<double>(str[0]) << '\n';
}

void	ScalarConverter::convertInt(const string& str)
{
	int num = atoi(str.c_str());
	if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		cout << "char: impossible\n";
	else if (!std::isprint(num))
		cout << "char: Non displayable\n";
	else
		cout << "char: \'" << static_cast<char>(num) << "\'\n";
	cout << "int: " << num << '\n';
	cout << std::fixed << std::setprecision(1);
	cout << "float: " << static_cast<float>(num) << "f\n";
	cout << "double: " << static_cast<double>(num) << '\n';
}

void	ScalarConverter::convertFloat(const string& str)
{
	float	num = strtof(str.c_str(), NULL);
	if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		cout << "char: impossible\n";
	else if (!std::isprint(num))
		cout << "char: Non displayable\n";
	else
		cout << "char: \'" << static_cast<char>(num) << "\'\n";
	if (!overLimit(str, INT))
		cout << "int: " << static_cast<int>(num) << '\n';
	else
		cout << "int: impossible\n";
	cout << std::fixed << std::setprecision(1);
	cout << "float: " << num << "f\n";
	cout << "double: " << static_cast<double>(num) << '\n';
}

void	ScalarConverter::convertDouble(const string& str)
{
	double	num = strtod(str.c_str(), NULL);
	if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		cout << "char: impossible\n";
	else if (!std::isprint(num))
		cout << "char: Non displayable\n";
	else
		cout << "char: \'" << static_cast<char>(num) << "\'\n";
	if (!overLimit(str, INT))
		cout << "int: " << static_cast<int>(num) << '\n';
	else
		cout << "int: impossible\n";
	 cout << std::fixed << std::setprecision(1);
	if (std::abs(num) <= std::numeric_limits<float>::max())
		cout << "float: " << static_cast<float>(num) << "f\n";
	else
		cout << "float: impossible\n";
	cout << "double: " << num << '\n';
}

