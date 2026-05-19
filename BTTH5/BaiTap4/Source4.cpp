#include "Header4.h"

NhanVien::NhanVien(string ma, string ten, int t, string dt, string em, int lcb, int luong) : MaNV(ma), HVT(ten), Tuoi(t), SDT(dt), Email(em), LCB(lcb), Luong(luong) {}

void NhanVien::Print() {
	cout << '\n' << "Ma nhan vien: " << MaNV;
	cout << '\n' << "Ho va ten: " << HVT;
	cout << '\n' << "Tuoi: " << Tuoi;
	cout << '\n' << "SDT: " << SDT;
	cout << '\n' << "Email: " << Email;
	cout << '\n' << "Luong co ban: " << LCB;
}

int NhanVien::getLuong() {
	return Luong;
}

LTV::LTV(string ma, string ten, int t, string dt, string em, int lcb, int luong, double ovt) : NhanVien(ma, ten, t, dt, em, lcb, luong), OVT(ovt) {
	TinhLuong();
}

void LTV::Print() {
	NhanVien::Print();
	cout << '\n' << "So gio overtime: " << OVT;
	cout << '\n' << "Luong: " << Luong;
}

void LTV::TinhLuong() {
	Luong = LCB + OVT * 200000;
}

KCV::KCV(string ma, string ten, int t, string dt, string em, int lcb, int luong, int l) : NhanVien(ma, ten, t, dt, em, lcb, luong), Loi(l) {
	TinhLuong();
}
void KCV::Print() {
	NhanVien::Print();
	cout << '\n' << "So loi: " << Loi;
	cout << '\n' << "Luong: " << Luong;
}

void KCV::TinhLuong() {
	Luong = LCB + Loi * 50000;
}

void DanhSach::Input() {
	cout << "So nhan vien: ";
	int n; cin >> n;
	int TongLuong = 0;
	for (int i = 0; i < n; i++) {
		cout << "Loai: 1: LCV, 2: KCV: ";
		int loai; cin >> loai;
		string MaNV;
		string HVT;
		int Tuoi;
		string SDT;
		string Email;
		int LCB;
		getline(cin >> ws, MaNV);
		getline(cin >> ws, HVT);
		cin >> Tuoi;
		getline(cin >> ws, SDT);
		getline(cin >> ws, Email);
		cin >> LCB;
		if (loai == 1) {
			double ovt;
			cin >> ovt;
			LTV* t = new LTV(MaNV, HVT, Tuoi, SDT, Email, LCB, 0, ovt);
			nv.push_back(t);
		}
		if (loai == 2) {
			int loi;
			cin >> loi;
			KCV* t = new KCV(MaNV, HVT, Tuoi, SDT, Email, LCB, 0, loi);
			nv.push_back(t);
		}
	}
}

void DanhSach::PrintAll() {
	cout << '\n' << "DANH SACH TAT CA NHAN VIEN" << '\n';
	for (auto& n : nv) {
		n->Print();
	}
}
void DanhSach::TinhLTB() {
	int TongLuong = 0;
	for (auto& n : nv) {
		TongLuong += n->getLuong();
	}
	LTB = (double)TongLuong / nv.size();
}
void DanhSach::PrintSpe() {
	TinhLTB();
	cout << '\n' << "DANH SACH NHAN VIEN LUONG < LTB: " << '\n';
	for (auto& n : nv) {
		if (n->getLuong() < LTB) n->Print();
	}
	NhanVien* maxLTV = nullptr;
	NhanVien* minKCV = nullptr;
	NhanVien* maxNV = nullptr;
	NhanVien* minNV = nullptr;
	for (auto& n : nv) {
		if (LTV* ltv = dynamic_cast<LTV*>(n)) {
			if (!maxLTV || ltv->getLuong() > maxLTV->getLuong()) {
				maxLTV = ltv;
			}
		}
		else if (KCV* kcv = dynamic_cast<KCV*>(n)) {
			if (!minKCV || kcv->getLuong() < minKCV->getLuong()) {
				minKCV = kcv;
			}
		}
		if (!maxNV) maxNV = n;
		else if (n->getLuong() > maxNV->getLuong()) maxNV = n;
		if (!minNV) minNV = n;
		else if (n->getLuong() < minNV->getLuong()) minNV = n;
	}
	cout << '\n' << "LTV LUONG CAO NHAT: " << '\n';
	maxLTV->Print();
	cout << '\n' << "KCV LUONG THAP NHAT: " << '\n';
	minKCV->Print();
	cout << '\n' << "NHAN VIEN LUONG CAO NHAT: " << '\n';
	maxNV->Print();
	cout << '\n' << "NHAN VIEN LUONG THAP NHAT: " << '\n';
	minNV->Print();
}