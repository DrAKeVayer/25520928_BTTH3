#include "Header6.h"

Khach::Khach(string ten, int sl, int dg, double t) : Ten(ten), SL(sl), DG(dg), Tien(t) {
}

string Khach::getTen() {
	return Ten;
}
double Khach::getTien() {
	return Tien;
}

void Khach::OutToFile(ofstream& fileOut) {
	fileOut << Ten << '\n';
	fileOut << fixed << setprecision(0) << Tien << '\n';
}

KhachThuong::KhachThuong(string ten, int sl, int dg, double t) : Khach(ten, sl, dg, t) {
	TinhTien();
}

void KhachThuong::TinhTien() {
	Tien = (SL * DG) * 1.1;
}

KhachThan::KhachThan(string ten, int sl, int dg, double t, int tt) : Khach(ten, sl, dg, t), NamTT(tt) {
	TinhTien();
}
void KhachThan::TinhTien() {
	int KM = max(50, NamTT * 5);
	Tien = double((SL * DG)) * double(100 - KM) / 100 * 1.1;
}

KhachDacBiet::KhachDacBiet(string ten, int sl, int dg, double t) : Khach(ten, sl, dg, t) {
	TinhTien();
}

void KhachDacBiet::TinhTien() {
	Tien = (SL * DG) * 0.5 * 1.1;
}

void DanhSach::InputFromFile() {
	ifstream fileIn("XYZ.INP");
	if (!fileIn.is_open()) return;
	int x, y, z;
	fileIn >> x >> y >> z;

	for (int i = 0; i < x; i++) {
		string ten;
		int SL, DG;
		getline(fileIn >> ws, ten);
		fileIn >> SL >> DG;
		KhachThuong* t = new KhachThuong(ten, SL, DG, 0);
		k.push_back(t);
	}
	for (int i = 0; i < y; i++) {
		string ten;
		int SL, DG, nam;
		getline(fileIn >> ws, ten);
		fileIn >> SL >> DG >> nam;
		KhachThan* t = new KhachThan(ten, SL, DG, 0, nam);
		k.push_back(t);
	}
	for (int i = 0; i < z; i++) {
		string ten;
		int SL, DG;
		getline(fileIn >> ws, ten);
		fileIn >> SL >> DG;
		KhachDacBiet* t = new KhachDacBiet(ten, SL, DG, 0);
		k.push_back(t);
	}
	fileIn.close();
}

void DanhSach::OutputToFile() {
	ofstream fileOut("XYZ.OUT");
	if (!fileOut.is_open()) return;
	ifstream fileIn("XYZ.INP");
	if (!fileIn.is_open()) return;
	int x, y, z;
	fileIn >> x >> y >> z;
	fileOut << x << " " << y << " " << z << '\n';
	for (auto& p : k) {
		p->OutToFile(fileOut);
	}
}