#include "Header1.h"

int main() {
	cout << fixed << setprecision(2);
	SetConsoleOutputCP(65001);
	TamGiac tg;
	tg.Nhap();

	int input;

	cout << "Chọn hành động:" << '\n';
	cout << "1. Xuất tam giác" << '\n';
	cout << "2. Phóng to tam giác" << '\n';
	cout << "3. Thu nhỏ tam giác" << '\n';
	cout << "4. Tịnh tiến tam giác" << '\n';
	cout << "5. Quay tam giác" << '\n';
	cout << "9. Exit" << '\n';
	
	do {
		cin >> input;
		
		switch (input) {
			case 1: {
				tg.Xuat();
				break;
			}
			case 2: {
				tg.PhongTo();
				break;
			}
			case 3: {
				tg.ThuNho();
				break;
			}
			case 4: {
				tg.TinhTien();
				break;
			}
			case 5: {
				tg.Quay();
				break;
			}
		}
	} while (input != 9);
	return 0;
}