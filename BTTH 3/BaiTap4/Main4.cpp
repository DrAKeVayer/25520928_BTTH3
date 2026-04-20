#include "Header4.h"

int main() {
	SetConsoleOutputCP(65001);
	Array ds;
	cout << "Nhập số lượng phần tử: ";
	int n; cin >> n;
	ds.Nhap(n);
	cout << "Mảng ban đầu: " << '\n';
	ds.Xuat();
	int a = ds.FindSmallestOdd();
	int b = ds.FindLargestPrime();
	cout << "Nhap số x cần đếm: ";
	int x; cin >> x;
	cout << "x xuất hiện " << ds.CountX(x) << " lần" << '\n';
	if (ds.CheckIncrease()) {
		cout << "Mảng này tăng dần" << '\n';
	}
	else {
		cout << "Mảng này không tăng dần" << '\n';
	}
	if (a != 0) {
		cout << "Số lẻ nhỏ nhất là " << a << '\n';
	}
	else {
		cout << "Mảng không có số lẻ" << '\n';
	}
	if (b != -1) {
		cout << "Số nguyên tố lớn nhất là " << b << '\n';
	}
	else {
		cout << "Mảng không có số nguyên tố" << '\n';
	}
	ds.SortAsc(0, n - 1);
	cout << "Mảng sắp xếp tăng dần (Quick sort): " << '\n';
	ds.Xuat();
	ds.SortDes(0, n - 1);
	cout << "Mảng sắp xếp giảm dần (Quick sort): " << '\n';
	ds.Xuat();
	return 0;
}