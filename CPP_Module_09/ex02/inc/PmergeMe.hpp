#ifndef _PMERGEME_
#define _PMERGEME_

#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <ctime>
#include <iomanip>

using std::cout;
using std::cerr;
using std::string;
using std::numeric_limits;
using std::vector;
using std::list;

class PmergeMe {
public:
	PmergeMe(vector<int>&);
	PmergeMe(list<int>&);
	~PmergeMe();

	template <typename C>
	void			printCnt(const C& cnt);
	vector<int>		mergeSortVector(vector<int>&);
	vector<int>		mergeVector(vector<int>&, vector<int>&);
	vector<int>		insertionSortVector(vector<int>&);
	list<int>		mergeSortList(list<int>&);
	list<int>		mergeList(list<int>&, list<int>&);
	list<int>		insertionSortList(list<int>&);

private:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe&	operator=(const PmergeMe&);

	clock_t		_startTime;
	clock_t		_endTime;
	string		_type;
	int			_n;
};

#endif
