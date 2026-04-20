#include "Header8.h"

int SoSanhNgay(int d1, int m1, int y1, int d2, int m2, int y2) {
	if (y1 < y2) return LONHON;
	else if (y1 > y2) return NHOHON;
	else {
		if (m1 < m2) return LONHON;
		else if (m1 > m2) return NHOHON;
		else {
			if (d1 < d2) return LONHON;
			else if (d1 > d2) return NHOHON;
		}
	}
	return BANG;
}

string NhanVienSX::getMa() const {
	return Ma;
}

string NhanVienSX::getHVTen() const {
	return HVTen;
}

int NhanVienSX::getDSinh() const {
	return DSinh;
}

int NhanVienSX::getTSinh() const {
	return TSinh;
}

int NhanVienSX::getNSinh() const {
	return NSinh;
}

int NhanVienSX::getSanPham() const {
	return static_cast<double>(SanPham);
}

int NhanVienSX::getDonGia() const {
	return static_cast<double>(DonGia);
}

int NhanVienSX::getLuong() const {
	return static_cast<double>(Luong);
}

void DsNhanVienSX::Input() {
	cout << "Nhập số nhân viên: ";
	int n; cin >> n;
	string Ma;
	string HVTen;
	int DSinh;
	int TSinh;
	int NSinh;
	int SanPham;
	int DonGia;
	nv.clear();
	TongLuong = 0;
	cout << "Kí hiệu: " << '\n' << "1: Mã số" << '\n' << "2: Họ và tên" << '\n' << "3: Ngày - Tháng - Năm sinh" << '\n' << "4: Số sản phẩm - đơn giá" << '\n';
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "1: ";
		cin >> Ma;
		cout << '\n' << "2: ";
		cin.ignore();
		getline(cin >> ws, HVTen);
		cout << '\n' << "3: ";
		cin >> DSinh >> TSinh >> NSinh;
		cout << '\n' << "4: ";
		cin >> SanPham >> DonGia;
		NhanVienSX c(Ma, HVTen, DSinh, TSinh, NSinh, SanPham, DonGia, 0);
		nv.push_back(c);
		TongLuong += SanPham * DonGia;
	}
}
void DsNhanVienSX::PrintNV(const NhanVienSX& c) const {
	cout << "Mã nhân viên: " << c.getMa() << '\n';
	cout << "Họ và tên: " << c.getHVTen() << '\n';
	cout << "Ngày tháng năm sinh: " << c.getDSinh() << "/" << c.getTSinh() << "/" << c.getNSinh() << '\n';
	cout << "Số sản phẩm, đơn giá: " << c.getSanPham() << " sản phẩm" << " - " << c.getDonGia() << "đ" << '\n';
	cout << "Lương: " << c.getLuong() << "đ" << '\n';
	cout << '\n';
}
void DsNhanVienSX::PrintNVList() {
	for (int i = 0; i < nv.size(); i++) {
		PrintNV(nv[i]);
	}
}
void DsNhanVienSX::SortAscLuong(int low, int high) {
	if (low >= high) return;
	int pivot = nv[low + (high - low) / 2].getLuong();
	int i = low;
	int j = high;

	while (i <= j) {
		while (nv[i].getLuong() < pivot) i++;
		while (nv[j].getLuong() > pivot) j--;
		if (i <= j) {
			swap(nv[i], nv[j]);
			i++;
			j--;
		}
	}
	sortedLuong = true;
	if (low < j) SortAscLuong(low, j);
	if (i < high) SortAscLuong(i, high);
}
void DsNhanVienSX::SortDesAge(int low, int high) {
	if (low >= high) return;
	int mid = low + (high - low) / 2;
	int pD = nv[mid].getDSinh();
	int pM = nv[mid].getTSinh();
	int pY = nv[mid].getNSinh();
	int i = low;
	int j = high;

	while (i <= j) {
		while (SoSanhNgay(nv[i].getDSinh(), nv[i].getTSinh(), nv[i].getNSinh(), pD, pM, pY) == LONHON) i++;
		while (SoSanhNgay(nv[j].getDSinh(), nv[j].getTSinh(), nv[j].getNSinh(), pD, pM, pY) == NHOHON) j--;
		if (i <= j) {
			swap(nv[i], nv[j]);
			i++;
			j--;
		}
	}
	sortedAge = true;
	if (low < j) SortDesAge(low, j);
	if (i < high) SortDesAge(i, high);
}
void DsNhanVienSX::PrintMinLuong() {
	cout << "Nhân viên lương thấp nhất là: " << '\n';
	if (!sortedLuong) SortAscLuong(0, nv.size() - 1);
	int max = nv[0].getLuong();
	int i = 0;
	while (nv[i].getLuong() == max) {
		PrintNV(nv[i]);
		i++;
		if (i == nv.size()) break;
	}
}
void DsNhanVienSX::PrintMaxAge() {
	if (!sortedAge) SortDesAge(0, nv.size() - 1);
	int maxY = nv[0].getNSinh();
	int maxM = nv[0].getTSinh();
	int maxD = nv[0].getDSinh();
	int i = 0;
	while (SoSanhNgay(nv[i].getNSinh(), nv[i].getTSinh(), nv[i].getDSinh(), maxY, maxM, maxD) == BANG) {
		PrintNV(nv[i]);
		i++;
		if (i == nv.size()) break;
	}
}
void DsNhanVienSX::PrintTongLuong() {
	cout << "Tổng lương phải trả cho nhân viên là: " << TongLuong << "đ" << '\n';
}
int DsNhanVienSX::getSize() const {
	return nv.size();
}
