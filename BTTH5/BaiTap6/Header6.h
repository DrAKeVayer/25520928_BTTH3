#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>
#include <fstream>

using namespace std;

class Khach {
protected:
	string Ten;
	int SL;
	int DG;
	double Tien;
public:
	Khach(string ten = "", int sl = 0, int dg = 0, double t = 0);
	virtual void TinhTien() = 0;
	string getTen();
	double getTien();
	void OutToFile(ofstream& fileOut);
};

class KhachThuong : public Khach {
public:
	KhachThuong(string ten = "", int sl = 0, int dg = 0, double t = 0);
	void TinhTien() override;
};
class KhachThan : public Khach {
private:
	int NamTT;
public:
	KhachThan(string ten = "", int sl = 0, int dg = 0, double t = 0, int tt = 0);
	void TinhTien() override;
};
class KhachDacBiet : public Khach {
public:
	KhachDacBiet(string ten = "", int sl = 0, int dg = 0, double t = 0);
	void TinhTien() override;
};

class DanhSach {
private:
	vector<Khach*> k;
public:
	void InputFromFile();
	void OutputToFile();
};