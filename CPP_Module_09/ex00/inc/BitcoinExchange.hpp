#ifndef _BITCOINEXCHANGE_
#define _BITCOINEXCHANGE_

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <exception>
#include <string>
#include <iomanip>

using std::cout;
using std::cerr;
using std::string;
using std::ifstream;
using std::map;
using std::isdigit;

class Date {
public:
	Date();
	Date(const Date&);
	Date(const string&);
	~Date();

	Date&	operator=(const Date&);
	bool	operator==(const Date&) const;
	bool	operator<(const Date&) const;
	bool	operator>(const Date&) const;
	bool	operator<=(const Date&) const;
	bool	operator>=(const Date&) const;

	string	getStr() const;

private:
	int		_year, _month, _day;
	string	_str;
};

class BitcoinExchange {
public:
	BitcoinExchange(string);
	~BitcoinExchange();
	void	process();

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);

	float	operation();
	string	nextDate(string);
	bool	isValidDate() const;
	bool	isLeapYear(int) const;
	bool	isValidVal() const;
	bool	isInt(const string&) const;
	bool	isFloatf(const string&) const;
	bool	isFloat(const string&) const;

	Date				_inputDate;
	float				_inputVal;
	string				_line;
	ifstream			_inputFile, _dataFile;
	map<Date, float>	_dataMap;
};


#endif
