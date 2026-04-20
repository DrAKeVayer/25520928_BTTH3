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

class NhanVienSX {
protected:
	string Ma;
	string HVTen;
	int DSinh;
	int TSinh;
	int NSinh;
	int SanPham;
	int DonGia;
	int Luong;
public:
	NhanVienSX(string _M = "0", string _t = "0", int _d = 0, int _m = 0, int _y = 0, int _SP = 0, int _DG = 0, int _L = 0)
		: Ma(_M), HVTen(_t), DSinh(_d), TSinh(_m), NSinh(_y), SanPham(_SP), DonGia(_DG), Luong(_L) {
		Luong = SanPham * DonGia;
	}
	string getMa() const;
	string getHVTen() const;
	int getDSinh() const;
	int getTSinh() const;
	int getNSinh() const;
	int getSanPham() const;
	int getDonGia() const;
	int getLuong() const;
};

class DsNhanVienSX {
protected:
	vector<NhanVienSX> nv;
	bool sortedAge = false;
	bool sortedLuong = false;
	int TongLuong = 0;
public:
	void Input();
	void PrintNV(const NhanVienSX& c) const;
	void PrintNVList();
	void SortAscLuong(int low, int high);
	void SortDesAge(int low, int high);
	void PrintMinLuong();
	void PrintMaxAge();
	void PrintTongLuong();
	int getSize() const;
};