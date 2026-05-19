#include "Header3.h"

SinhVien::SinhVien(string mssv, string ten, string dc, int tt, double dtb, bool dau) :
	MSSV(mssv), Ten(ten), DiaChi(dc), TongTin(tt), DTB(dtb), Dau(dau) {
}

void SinhVien::Input(istream& is) {
	cout << "MSSV: "; getline(is >> ws, MSSV);
	cout << "Họ và tên: "; getline(is >> ws, Ten);
	cout << "Địa chỉ: "; getline(is >> ws, DiaChi);
	cout << "Tổng tín chỉ: "; is >> TongTin;
	cout << "Điểm trung bình: "; is >> DTB;
}

istream& operator>>(istream& is, SinhVien& sv) {
	sv.Input(is);
	return is;
}

double SinhVien::getDTB() {
	return DTB;
}
bool SinhVien::getDau() {
	return Dau;
}

SinhVienCD::SinhVienCD(string mssv, string ten, string dc, int tt, double dtb, bool dau, double dttt) :
	SinhVien(mssv, ten, dc, tt, dtb, dau), DTTT(dttt) {
	setDau();
}

void SinhVienCD::Input(istream& is) {
	SinhVien::Input(is);
	cout << "Điểm thi tốt nghiệp: "; is >> DTTT;
	setDau();
}

void SinhVienCD::setDau() {
	if (TongTin >= 120 && DTB >= 5.0 && DTTT >= 5.0) Dau = true;
	else Dau = false;
}

void SinhVienCD::Print() const {
	cout << "MSSV: " << MSSV << '\n';
	cout << "Họ và tên: " << Ten << '\n';
	cout << "Hệ sinh viên: Cao đẳng" << '\n';
	cout << "Địa chỉ: " << DiaChi << '\n';
	cout << "Tổng tín chỉ: " << TongTin << '\n';
	cout << "Điểm trung bình: " << fixed << setprecision(3) << DTB << '\n';
	cout << "Điểm thi tốt nghiệp: " << DTTT << '\n';
	cout << "Có đậu không? ";
	if (Dau) cout << "Yes!" << '\n';
	else cout << "Nope!" << '\n';
}

int SinhVienCD::getLoai() {
	return CD;
}

SinhVienDH::SinhVienDH(string mssv, string ten, string dc, int tt, double dtb, bool dau, string tlv, double dlv) :
	SinhVien(mssv, ten, dc, tt, dtb, dau), TenLV(tlv), DiemLV(dlv) {
	setDau();
}

void SinhVienDH::Input(istream& is) {
	SinhVien::Input(is);
	cout << "Tên luận văn: "; getline(is >> ws, TenLV);
	cout << "Điểm luận văn: "; is >> DiemLV;
	setDau();
}

void SinhVienDH::setDau() {
	if (TongTin >= 170 && DTB >= 5.0 && DiemLV >= 5.0) Dau = true;
	else Dau = false;
}

void SinhVienDH::Print() const {
	cout << "MSSV: " << MSSV << '\n';
	cout << "Họ và tên: " << Ten << '\n';
	cout << "Hệ sinh viên: Đại học" << '\n';
	cout << "Địa chỉ: " << DiaChi << '\n';
	cout << "Tổng tín chỉ: " << TongTin << '\n';
	cout << "Điểm trung bình: " << fixed << setprecision(3) << DTB << '\n';
	cout << "Tên luận văn: " << TenLV << '\n';
	cout << "Điểm luận văn : " << fixed << setprecision(3) << DiemLV << '\n';
	cout << "Có đậu không? ";
	if (Dau) cout << "Yes!" << '\n';
	else cout << "Nope!" << '\n';
}

int SinhVienDH::getLoai() {
	return DH;
}

void DsSinhVien::Input(SinhVien* s) {
	if (s) {
		sv.push_back(s);
		int Loai = s->getLoai();
		if (Loai == DH && !s->getDau()) DHCount++;
		if (Loai == CD && !s->getDau()) CDCount++;
	}
}

void DsSinhVien::PrintDs() {
	cout << '\n' << "Danh sách tất cả sinh viên: " << '\n';
	for (auto& s : sv) {
		s->Print();
	}
}

void DsSinhVien::PrintTN() {
	cout << '\n' << "Danh sách sinh viên đủ ĐK tốt nghiệp: " << '\n';
	for (auto& s : sv) {
		if (s->getDau()) s->Print();
	}
	cout << "Danh sách sinh viên không đủ ĐK tốt nghiệp: " << '\n';
	for (auto& s : sv) {
		if (!s->getDau()) s->Print();
	}
}

void DsSinhVien::PrintSpe() {
	SinhVien* CDMax = nullptr;
	SinhVien* DHMax = nullptr;
	for (auto& s : sv) {
		if (s->getLoai() == DH) {
			if (!DHMax) DHMax = s;
			else if (s->getDTB() > DHMax->getDTB()) DHMax = s;
		}
		if (s->getLoai() == CD) {
			if (!CDMax) CDMax = s;
			else if (s->getDTB() > CDMax->getDTB()) CDMax = s;
		}
	}
	cout << '\n' << "Sinh viên đại học điểm TB cao nhất: " << '\n';
	if (DHMax) DHMax->Print();
	cout << "Sinh viên cao đẳng điểm TB cao nhất: " << '\n';
	if (CDMax) CDMax->Print();
	cout << "Số sinh viên đại học không đủ ĐK tốt nghiệp: " << DHCount << '\n';
	cout << "Số sinh viên cao đẳng không đủ ĐK tốt nghiệp: " << CDCount << '\n';
}