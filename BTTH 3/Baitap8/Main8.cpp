#include "Header8.h"

int main() {
	SetConsoleOutputCP(65001);
	DsNhanVienSX nv;
	nv.Input();
	int p;
	cout << "1. Xuất danh sách" << '\n';
	cout << "2. Xuất nhân viên lương thấp nhất" << '\n';
	cout << "3. Xuất tổng lương phải trả" << '\n';
	cout << "4. Xuất nhân viên cao tuổi nhất" << '\n';
	cout << "5. Xuất danh sách tăng dần theo lương" << '\n';
	cout << "0. Exit" << '\n';
	do {
		cin >> p;
		if (p == 1) {
			nv.PrintNVList();
		}
		else if (p == 2) {
			nv.PrintMinLuong();
		}
		else if (p == 3) {
			nv.PrintTongLuong();
		}
		else if (p == 4) {
			nv.PrintMaxAge();
		}
		else if (p == 5) {
			nv.SortAscLuong(0, nv.getSize() - 1);
			nv.PrintNVList();
		}
	} while (p != 0);

	return 0;
}