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
	_startTime = clock();
	// sortList();
	_endTime = clock();
}

PmergeMe::~PmergeMe() {

	double duration = static_cast<double>(_endTime - _startTime) / (CLOCKS_PER_SEC / 1000000);
	cout << "Time to process a range of " << _n << " elements with std::" << _type << " : " << duration << " us\n";
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	static_cast<void>(other);
	return *this;
}

void	PmergeMe::printCnt(vector<int>& cnt) const{
	if (cnt.empty()) {
		return ;
	}
	for (vector<int>::iterator	it = cnt.begin(); it != cnt.end(); it++) {
		cout << *it;
		if (it + 1 != cnt.end()) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
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

//key = val to store in right position
//j = index ate onde ja esta sorted
vector<int>	PmergeMe::insertionSortVector(vector<int>& cnt) {
	int n = cnt.size();
	for (int i = 1; i < n; i++) {
		int key = cnt[i];
		int j = i - 1;
		while (j >= 0 && cnt[j] > key) {
			cnt[j + 1] = cnt[j];
			j--;
		}
		cnt[j + 1] = key;
	}
	return cnt;
}
