#include "Header4.h"

bool isPrime(int x) {
	if (x <= 1) return false;
	if (x == 2 || x == 3) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

void Array::Nhap(int n) {
	unsigned seed = static_cast<unsigned>(
		chrono::high_resolution_clock::now().time_since_epoch().count()
		);

	mt19937 gen(seed);
	uniform_int_distribution<int> dist(-2147483648, 2147483647);

	ds.clear();
	ds.reserve(n);
	for (int i = 0; i < n; i++) {
		ds.push_back(dist(gen));
	}
}
void Array::Xuat() {
	for (int i = 0; i < ds.size(); i++) {
		cout << ds[i] << ",";
	}
	cout << '\n';
}
int Array::CountX(int x) {
	int count = 0;
	for (int i = 0; i < ds.size(); i++) {
		if (ds[i] == x) count++;
	}
	return count;
}
bool Array::CheckIncrease() {
	for (int i = 0; i < ds.size() - 1; i++) {
		if (ds[i] >= ds[i + 1]) return false;
	}
	return true;
}
int Array::FindSmallestOdd() {
	int smallest = 2147483647;
	bool found = false;
	for (int i = 0; i < ds.size(); i++) {
		if (ds[i] % 2 != 0 && ds[i] <= smallest) {
			smallest = ds[i];
			found = true;
		}
	}
	if (found) return smallest;
	else return 0;
}
int Array::FindLargestPrime() {
	int largest = -1;
	for (int i = 0; i < ds.size(); i++) {
		if (isPrime(ds[i]) && ds[i] > largest) {
			largest = ds[i];
		}
	}
	return largest;
}
void Array::SortAsc(int low, int high) { //Quick sort is used
	if (low >= high) return;
	int pivot = ds[low + (high - low) / 2];
	int i = low;
	int j = high;

	while (i <= j) {
		while (ds[i] < pivot) i++;
		while (ds[j] > pivot) j--;
		if (i <= j) {
			swap(ds[i], ds[j]);
			i++;
			j--;
		}
	}
	if (low < j) SortAsc(low, j);
	if (i < high) SortAsc(i, high);
}
void Array::SortDes(int low, int high) {
	if (low >= high) return;
	int pivot = ds[low + (high - low) / 2];
	int i = low;
	int j = high;

	while (i <= j) {
		while (ds[i] > pivot) i++;
		while (ds[j] < pivot) j--;
		if (i <= j) {
			swap(ds[i], ds[j]);
			i++;
			j--;
		}
	}
	if (low < j) SortDes(low, j);
	if (i < high) SortDes(i, high);
}