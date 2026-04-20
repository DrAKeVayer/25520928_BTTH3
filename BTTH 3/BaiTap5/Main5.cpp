#include "Header5.h"

int main() {
	SetConsoleOutputCP(65001);
	cout << "Nhập bậc đa thức 1 để khởi tạo: " << '\n';
	int n; cin >> n;
	DaThuc dt1(n);
	dt1.Nhap(n);
	cout << "Nhập bậc đa thức 2 để khởi tạo: " << '\n';
	int m; cin >> m;
	DaThuc dt2(m);
	dt2.Nhap(m);
	cout << "Đa thức 1 hiện tại: ";
	dt1.Xuat();
	cout << "Đa thức 2 hiện tại: ";
	dt2.Xuat();
	cout << "Đa thức 1 + đa thức 2: ";
	DaThuc DtSum = dt1 + dt2;
	DtSum.Xuat();
	cout << "Đa thức 1 - đa thức 2: ";
	DaThuc DtSub = dt1 - dt2;
	DtSub.Xuat();
	cout << "Nhập x để tính giá trị đa thức 1: ";
	double x; cin >> x;
	cout << dt1.TinhGiaTri(x);
	return 0;
}