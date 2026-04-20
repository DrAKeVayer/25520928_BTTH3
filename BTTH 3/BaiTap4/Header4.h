#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <chrono>
#include <random>
#include <windows.h>

using namespace std;

bool isPrime(int x);


class Array {
protected:
	vector<int> ds;
public:
	Array() {};
	void Nhap(int n);
	void Xuat();
	int CountX(int x);
	bool CheckIncrease();
	int FindSmallestOdd();
	int FindLargestPrime();
	void SortAsc(int low, int high);
	void SortDes(int low, int high);
};