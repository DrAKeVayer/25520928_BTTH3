#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

enum SoSanh {
	LONHON = 1,
	BANG = 0,
	NHOHON = -1
};

int SoSanhNgay(int d1, int m1, int y1, int d2, int m2, int y2);

class NhanVien {
protected:
	string HVTen;
	int DSinh;
	int TSinh;
	int NSinh;
	int Luong;
public:
	NhanVien(string ten, int d, int m, int y);
	virtual ~NhanVien() {}
	virtual void Print();
	int getLuong() const;
	int getDSinh() const;
	int getTSinh() const;
	int getNSinh() const;
};

class NhanVienSX : public NhanVien {
protected:
	int LuongCB;
	int SanPham;
public:
	NhanVienSX(string ten, int d, int m, int y, int lcb, int sp);
	void Print() override;
};

class NhanVienVP : public NhanVien {
protected:
	int NgayLam;
public:
	NhanVienVP(string ten, int d, int m, int y, int nl);
	void Print() override;
};

class DsNhanVien {
protected:
	vector<NhanVien*> nv;
	bool sortedAge = false;
	bool sortedLuong = false;
	int TongLuong = 0;
public:
	void Input(NhanVien* n);
	void PrintNVList();
	void SortAscLuongSX(int low, int high);
	void SortDesAgeVP(int low, int high);
};
