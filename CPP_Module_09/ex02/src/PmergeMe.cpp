#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::PmergeMe(vector<int>& cnt) : _type("vector"), _n(cnt.size()) {
	cout << "Before: ";
	printCnt(cnt);
	_startTime = clock();
	cnt = mergeSortVector(cnt);
	_endTime = clock();
	cout << "After:  ";
	printCnt(cnt);
}

PmergeMe::PmergeMe(list<int>& cnt) : _type("list"), _n(cnt.size()) {
	// cout << "Before: ";
	// printCnt(cnt);
	_startTime = clock();
	cnt = mergeSortList(cnt);
	_endTime = clock();
	// cout << "After:  ";
	// printCnt(cnt);
}

PmergeMe::~PmergeMe() {
	double duration = static_cast<double>(_endTime - _startTime) / (CLOCKS_PER_SEC / 1000000);
	cout << "Time to process a range of " << _n << " elements with std::" << std::setw(6) << std::left << _type << " : " << duration << " us\n";
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	static_cast<void>(other);
	return *this;
}

template <typename C>
void	PmergeMe::printCnt(const C& cnt) {
	if (cnt.empty()) {
		throw std::out_of_range("Error");
	}
	typename C::const_iterator it = cnt.begin();
	for (; it != --cnt.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << *it << "\n";
}

vector<int>	PmergeMe::mergeSortVector(vector<int>& cnt) {
	int n = cnt.size();
	if (n <= 20) {
		return insertionSortVector(cnt);
	}
	vector<int>	cntOne;
	vector<int> cntTwo;
	for (int i = 0; i < n; i++) {
		if (i < n / 2) {
			cntOne.push_back(cnt[i]);
		} else {
			cntTwo.push_back(cnt[i]);
		}
	}
	cntOne = mergeSortVector(cntOne);
	cntTwo = mergeSortVector(cntTwo);
	return mergeVector(cntOne, cntTwo);
}

// vector.erase(it) invalida os iterators que vem depois
vector<int>	PmergeMe::mergeVector(vector<int>& cntA, vector<int>& cntB) {
	vector<int>	cntC;
	while (!cntA.empty() && !cntB.empty()) {
		if (cntA[0] > cntB[0]) {
			cntC.push_back(cntB[0]);
			cntB.erase(cntB.begin());
		} else {
			cntC.push_back(cntA[0]);
			cntA.erase(cntA.begin());
		}
	}
	while (!cntA.empty()) {
		cntC.push_back(cntA[0]);
		cntA.erase(cntA.begin());
	}
	while (!cntB.empty()) {
		cntC.push_back(cntB[0]);
		cntB.erase(cntB.begin());
	}
	return cntC;
}

//val = val para o qual vamos procurar posicao certa
//j = index ate onde ja esta sorted
vector<int>	PmergeMe::insertionSortVector(vector<int>& cnt) {
	int n = cnt.size();
	for (int i = 1; i < n; i++) {
		int	val = cnt[i];
		int	j = i - 1;
		while (j >= 0 && cnt[j] > val) { //arranja espaço nos vals ja sorted para o novo val
			cnt[j + 1] = cnt[j];
			j--;
		}
		cnt[j + 1] = val;
	}
	return cnt;
}

list<int>	PmergeMe::mergeSortList(list<int>& cnt) {
	int n = cnt.size();
	if (n <= 20) {
		return insertionSortList(cnt);
	}
	list<int> cntOne;
	list<int> cntTwo;
	int i = 0;
	for (list<int>::iterator it = cnt.begin(); it != cnt.end(); ++it, ++i) {
		if (i < n / 2) {
			cntOne.push_back(*it);
		} else {
			cntTwo.push_back(*it);
		}
	}
	cntOne = mergeSortList(cntOne);
	cntTwo = mergeSortList(cntTwo);
	return mergeList(cntOne, cntTwo);
}

list<int>	PmergeMe::mergeList(list<int>& cntA, list<int>& cntB) {
	list<int> cntC;
	while (!cntA.empty() && !cntB.empty()) {
		if (cntA.front() > cntB.front()) {
			cntC.push_back(cntB.front());
			cntB.pop_front();
		} else {
			cntC.push_back(cntA.front());
			cntA.pop_front();
		}
	}
	while (!cntA.empty()) {
		cntC.push_back(cntA.front());
		cntA.pop_front();
	}
	while (!cntB.empty()) {
		cntC.push_back(cntB.front());
		cntB.pop_front();
	}
	return cntC;
}

list<int>	PmergeMe::insertionSortList(list<int>& cnt) {
	list<int>::iterator it = cnt.begin();
	++it;
	while (it != cnt.end()) {
		int val = *it;
		list<int>::iterator j = it;
		list<int>::iterator prev = j;
		--prev;
		while (j != cnt.begin() && *prev > val) {
			*j = *prev;
			--j;
			--prev;
		}
		*j = val;
		++it;
	}
	return cnt;
}
