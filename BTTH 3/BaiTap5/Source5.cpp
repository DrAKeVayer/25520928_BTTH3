#include "Header5.h"
int DonThuc::getMu() const {
	return soMu;
}
double DonThuc::getHeSo() const {
	return heSo;
}
void DonThuc::setHeSo(double a) {
	heSo = a;
}

DaThuc::DaThuc(int n) {
	dt.clear();
	for (int i = 0; i <= n; i++) {
		DonThuc dont(i, 0);
		dt.push_back(dont);
	}
}
void DaThuc::Nhap(int n) {
	cout << '\n' << "Nhập hệ số đa thức từ bậc " << "n" << " đến 0" << '\n';
	for (int i = n; i >= 0; i--) {
		double m; cin >> m;
		dt[i].setHeSo(m);
	}
}
DaThuc DaThuc::operator+(const DaThuc& other) {
	DaThuc sum(-1);
	const DaThuc& Long = (dt.size() >= other.dt.size()) ? *this : other;
	const DaThuc& Short = (dt.size() >= other.dt.size()) ? other : *this;
	int i = 0;
	while (i < Short.dt.size()) {
		sum.dt.push_back(DonThuc(i, Long.dt[i].getHeSo() + Short.dt[i].getHeSo()));
		i++;
	}
	while (i < Long.dt.size()) {
		sum.dt.push_back(Long.dt[i]);
		i++;
	}
	return sum;
}
DaThuc DaThuc::operator-(const DaThuc& other) {
	DaThuc sum(-1);
	const DaThuc& Long = (dt.size() >= other.dt.size()) ? *this : other;
	const DaThuc& Short = (dt.size() >= other.dt.size()) ? other : *this;
	int i = 0;
	while (i < Short.dt.size()) {
		sum.dt.push_back(DonThuc(i, dt[i].getHeSo() - other.dt[i].getHeSo()));
		i++;
	}
	while (i < Long.dt.size()) {
		if (&Long == this) {
			sum.dt.push_back(Long.dt[i]);
			i++;
		}
		else {
			sum.dt.push_back(DonThuc(i, - Long.dt[i].getHeSo()));
			i++;
		}
	}
	return sum;
}

void DaThuc::Xuat() {
	bool printedFirst = false;
	for (int i = dt.size() - 1; i >= 0; i--) {
		double h = dt[i].getHeSo();
		if (h == 0) continue;
		else if (!printedFirst && h > 0) {
			cout << h;
			printedFirst = true;
		}
		else if (h < 0) {
			cout << "-" << abs(h);
			printedFirst = true;
		}
		else if (printedFirst && h > 0) {
			cout << "+" << h;
		}
		int m = dt[i].getMu();
		if (m == 1) {
			cout << "x";
		}
		else if (m == 0) continue;
		else if (m > 0) {
			cout << "x^" << m;
		}
	}
	cout << '\n';
}
double DaThuc::TinhGiaTri(double x) {
	double sum = 0.0;
	for (int i = 0; i < dt.size(); i++) {
		sum += dt[i].getHeSo()* pow(x, dt[i].getMu());
	}
	return sum;
}