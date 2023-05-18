#include "BitcoinExchange.hpp"

  /******************/
 /****** Date ******/
/******************/

Date::Date() : _year(), _month(), _day(), _str() {}

Date::Date(const string& date) {
	_year = atoi(date.substr(0, 4).c_str());
	_month = atoi(date.substr(5, 2).c_str());
	_day = atoi(date.substr(8, 2).c_str());
	_str = date;
}

Date::~Date() {}

Date&	Date::operator=(const Date& other) {
	if (this != &other) {
		_year = other._year;
		_month = other._month;
		_day = other._day;
		_str = other._str;
	}
	return *this;
}

bool	Date::operator==(const Date& other) const {
	return _str == other._str;
}

bool	Date::operator<(const Date& other) const {
	if (_year > other._year)
		return 0;
	else if (_year < other._year)
		return 1;
	else if (_month > other._month)
		return 0;
	else if (_month < other._month)
		return 1;
	return _day < other._day;
}

bool	Date::operator>(const Date& other) const {
	if (_year < other._year)
		return 0;
	else if (_year > other._year)
		return 1;
	else if (_month < other._month)
		return 0;
	else if (_month > other._month)
		return 1;
	return _day > other._day;
}

bool	Date::operator<=(const Date& other) const {
	if (_year < other._year)
		return 1;
	else if (_year > other._year)
		return 0;
	else if (_month < other._month)
		return 1;
	else if (_month > other._month)
		return 0;
	return _day <= other._day;
}

bool	Date::operator>=(const Date& other) const {
	if (_year > other._year)
		return 1;
	else if (_year < other._year)
		return 0;
	else if (_month > other._month)
		return 1;
	else if (_month < other._month)
		return 0;
	return _day >= other._day;
}

string	Date::getStr() const{
	return _str;
}

  /***************************/
 /****** BitcoinExchange ****/
/***************************/

BitcoinExchange::BitcoinExchange(string fileName) : _inputFile(fileName.c_str()), _dataFile("data.csv") {
	if (!_inputFile.is_open() || !_dataFile.is_open()) {
			throw std::ios_base::failure("Error: could not open file.");
	}
	for (int i = 0; getline(_dataFile, _line); i++) {
		if (!i)
			continue;
		Date	date(_line.substr(0, 10));
		float	val = strtof(_line.substr(11).c_str(), NULL);
		// _dataMap.insert(std::make_pair(date, val));
		_dataMap[date] = val;
	}
}

BitcoinExchange::~BitcoinExchange() {
	if (_inputFile.is_open())
		_inputFile.close();
	if(_dataFile.is_open())
		_dataFile.close();
}

void	BitcoinExchange::process() {
	for (int i = 0; getline(_inputFile, _line); i++) {
		if (!i && _line == "date | value") {
			continue;
		} else if (_line.size() < 14  || !isValidDate()) {
			cerr << "Error: bad input => " + _line << '\n';
		} else if (isValidVal()){
			_inputDate = Date(_line.substr(0, 10));
			_inputVal = strtof(_line.substr(13).c_str(), NULL);
			cout << _inputDate.getStr() << " => " << _inputVal << " = " << operation() << '\n';
		}
	}
}

float	BitcoinExchange::operation() {
	map<Date, float>::iterator	it = _dataMap.begin();
	while (it->first <= _inputDate && it != _dataMap.end()) {
		it++;
	}
	if (it != _dataMap.begin() )
		it--;
	return it->second * _inputVal;
}

bool	BitcoinExchange::isValidDate() const {
	if (_line.substr(10, 3) != " | ") // separador apos data
		return 0;
	for (int i = 0; _line[i]; i++) {
		if ((i == 4 || i == 7) && _line[i] != '-') // hifen da data
			return 0;
		else if (i < 10 && i != 4 && i != 7 && !isdigit(_line[i])) // data nao for digit
			return 0;
	}
	int	year = atoi(_line.substr(0, 4).c_str());
	int	month = atoi(_line.substr(5, 2).c_str());
	int	day = atoi(_line.substr(8, 2).c_str());
	if (year < 0 || month < 1 || month > 12 || day < 1)
		return 0;
	int	daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1])
		return 0;
	return 1;
}

 // To be a leap year, the year number must be divisible by four – except for end-of-century years, which must be divisible by 400. This means that the year 2000 was a leap year, although 1900 was not. 2024, 2028, 2032 and 2036 are all leap years.
bool	BitcoinExchange::isLeapYear(int year) const {
	if (year % 100 == 0) {
		if (year % 400 == 0)
			return 1;
		return 0;
	} else if (year % 4 == 0)
		return 1;
	return 0;
}

bool	BitcoinExchange::isValidVal() const{
	if (isInt(_line.substr(13)) || isFloat(_line.substr(13)) || isFloatf(_line.substr(13))) {
		if (strtold(_line.substr(13).c_str(), NULL) < 0) {
			cerr << "Error: not a positive number.\n";
			return 0;
		}
		else if (strtold(_line.substr(13).c_str(), NULL) > 1000) {
			cerr << "Error: too large a number.\n";
			return 0;
		}
		return 1;
	}
	return 0;
}

bool	BitcoinExchange::isInt(const string& str) const{
	if (!str.size())
		return 0;
	for (size_t i = 0; str[i]; i++) {
		if (!i && str[i] == '-')
			continue;
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

bool	BitcoinExchange::isFloatf(const string& str) const{ // float com f
	size_t	size = str.size();
	size_t	pos = str.find('.');
	if (size < 4 || str[size - 1] != 'f' || pos == string::npos || pos == 0 || pos == size - 2 || (pos == 1 && str[0] == '-'))
		return 0;
	for (size_t i = 0; i < size - 1; i++) {
		if ((!i && str[i] == '-') || (i == pos && str[i] == '.'))
			continue;
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

bool	BitcoinExchange::isFloat(const string& str) const{
	size_t	size = str.size();
	size_t	pos = str.find('.');
	if (size < 3 || pos == string::npos || pos == 0 || pos == size - 1 || (str[0] == '-' && pos == 1))
		return 0;
	for (size_t i = 0; i < size; i++) {
		if ((!i && str[i] == '-') || (i == pos && str[i] == '.'))
			continue;
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}
