#include "Header1.h"

int main() {
	SetConsoleOutputCP(65001);
	DsNhanVien ds;
	int n, m;
	cout << "Nhập số nhân viên sản xuất: ";
	cin >> n;
	cout << "Nhập số nhân viên văn phòng: ";
	cin >> m;
	cout << "Nhập nhân viên sản xuất theo thứ tự: Tên, ngày, tháng, năm (sinh), lương cơ bản, số sản phẩm" << '\n';
	for (int i = 0; i < n; i++) {
		string ten;
		int d, m, y, lcb, sp;
		getline(cin >> ws, ten);
		cin >> d >> m >> y >> lcb >> sp;
		NhanVienSX* n = new NhanVienSX(ten, d, m, y, lcb, sp);
		ds.Input(n);
	}
	cout << "Nhập nhân viên văn phòng theo thứ tự: Tên, ngày, tháng, năm (sinh), số ngày làm" << '\n';
	for (int i = 0; i < m; i++) {
		string ten;
		int d, m, y, nl;
		getline(cin >> ws, ten);
		cin >> d >> m >> y >> nl;
		NhanVienVP* n = new NhanVienVP(ten, d, m, y, nl);
		ds.Input(n);
	}
	ds.PrintNVList();
	return 0;
}
