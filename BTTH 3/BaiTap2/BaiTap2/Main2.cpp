#include "Header2.h"

int main() {
	cout << fixed << setprecision(2);
	SetConsoleOutputCP(65001);
	DaGiac dg;
	dg.Nhap();

	int input;

	cout << "Chọn hành động:" << '\n';
	cout << "1. Xuất đa giác" << '\n';
	cout << "2. Phóng to đa giác" << '\n';
	cout << "3. Thu nhỏ đa giác" << '\n';
	cout << "4. Tịnh tiến đa giác" << '\n';
	cout << "5. Quay đa giác" << '\n';
	cout << "9. Exit" << '\n';

	do {
		cin >> input;

		switch (input) {
		case 1: {
			dg.Xuat();
			break;
		}
		case 2: {
			dg.PhongTo();
			break;
		}
		case 3: {
			dg.ThuNho();
			break;
		}
		case 4: {
			dg.TinhTien();
			break;
		}
		case 5: {
			dg.Quay();
			break;
		}
		}
	} while (input != 9);
	return 0;
}