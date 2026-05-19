#include "Header1.h"

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

NhanVien::NhanVien(string ten, int d, int m, int y) : HVTen(ten), DSinh(d), TSinh(m), NSinh(y) {}

void NhanVien::Print() {}
int NhanVien::getLuong() const {
	return Luong;
}
int NhanVien::getDSinh() const {
	return DSinh;
}

int NhanVien::getTSinh() const {
	return TSinh;
}

int NhanVien::getNSinh() const {
	return NSinh;
}

NhanVienSX::NhanVienSX(string ten, int d, int m, int y, int lcb, int sp) : NhanVien(ten, d, m, y), LuongCB(lcb), SanPham(sp) {
	Luong = LuongCB + SanPham * 5000;
}

void NhanVienSX::Print() {
	cout << "Họ và tên: " << HVTen << '\n';
	cout << "Loại nhân viên: NV Sản xuất" << '\n';
	cout << "Ngày tháng năm sinh: " << DSinh << "/" << TSinh << "/" << NSinh << '\n';
	cout << "Lương cơ bản: " << LuongCB << "đ" << '\n';
	cout << "Số sản phẩm: " << SanPham << '\n';
	cout << "Lương: " << Luong << "đ" << '\n';
}

NhanVienVP::NhanVienVP(string ten, int d, int m, int y, int nl) : NhanVien(ten, d, m, y), NgayLam(nl) {
	Luong = NgayLam * 100000;
}

void NhanVienVP::Print() {
	cout << "Họ và tên: " << HVTen << '\n';
	cout << "Loại nhân viên: NV Văn Phòng" << '\n';
	cout << "Ngày tháng năm sinh: " << DSinh << "/" << TSinh << "/" << NSinh << '\n';
	cout << "Số ngày làm: " << NgayLam << " ngày" << '\n';
	cout << "Lương: " << Luong << "đ" << '\n';
}

void DsNhanVien::Input(NhanVien* n) {
	nv.push_back(n);
	sortedAge = false;
	sortedLuong = false;
	TongLuong += n->getLuong();
}

void DsNhanVien::PrintNVList() {
	cout << "Danh sách tất cả nhân viên: " << '\n';
	for (int i = 0; i < nv.size(); i++) {
		nv[i]->Print();
	}
	SortAscLuongSX(0, nv.size() - 1);
	cout << "Nhân viên sản xuất lương thấp nhất: " << '\n';
	for (int i = 0; i < nv.size(); i++) {
		if (dynamic_cast<NhanVienSX*>(nv[i])) {
			nv[i]->Print();
			break;
		}
	}
	SortDesAgeVP(0, nv.size() - 1);
	cout << "Nhân viên văn phòng cao tuổi nhất: " << '\n';
	for (int i = 0; i < nv.size(); i++) {
		if (dynamic_cast<NhanVienVP*>(nv[i])) {
			nv[i]->Print();
			break;
		}
	}
	cout << "Tổng lương công ti phải trả: " << TongLuong << "đ" << '\n';
}

void DsNhanVien::SortAscLuongSX(int low, int high) {
	if (low >= high) return;
	int pivot = nv[low + (high - low) / 2]->getLuong();
	int i = low;
	int j = high;

	while (i <= j) {
		while (nv[i]->getLuong() < pivot) i++;
		while (nv[j]->getLuong() > pivot) j--;
		if (i <= j) {
			swap(nv[i], nv[j]);
			i++;
			j--;
		}
	}
	sortedLuong = true;
	if (low < j) SortAscLuongSX(low, j);
	if (i < high) SortAscLuongSX(i, high);
}
void DsNhanVien::SortDesAgeVP(int low, int high) {
	if (low >= high) return;
	int mid = low + (high - low) / 2;
	int pD = nv[mid]->getDSinh();
	int pM = nv[mid]->getTSinh();
	int pY = nv[mid]->getNSinh();
	int i = low;
	int j = high;

	while (i <= j) {
		while (SoSanhNgay(nv[i]->getDSinh(), nv[i]->getTSinh(), nv[i]->getNSinh(), pD, pM, pY) == LONHON) i++;
		while (SoSanhNgay(nv[j]->getDSinh(), nv[j]->getTSinh(), nv[j]->getNSinh(), pD, pM, pY) == NHOHON) j--;
		if (i <= j) {
			swap(nv[i], nv[j]);
			i++;
			j--;
		}
	}
	sortedAge = true;
	if (low < j) SortDesAgeVP(low, j);
	if (i < high) SortDesAgeVP(i, high);
}
