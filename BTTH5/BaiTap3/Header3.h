#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

enum Loai {
	DH = 1,
	CD = 2
};

class SinhVien {
protected:
	string MSSV;
	string Ten;
	string DiaChi;
	int TongTin;
	double DTB;
	bool Dau;
public:
	SinhVien(string mssv = "", string ten = "", string dc = "", int tt = 0, double dtb = 0, bool dau = false);
	virtual void Input(istream& is);
	friend istream& operator>>(istream& is, SinhVien& sv);
	virtual void setDau() = 0;
	virtual int getLoai() = 0;
	virtual void Print() const = 0;
	double getDTB();
	bool getDau();
};

class SinhVienCD : public SinhVien {
private:
	double DTTT;
public:
	SinhVienCD(string mssv = "", string ten = "", string dc = "", int tt = 0, double dtb = 0, bool dau = false, double dttt = 0);
	void Input(istream& is) override;
	void setDau() override;
	int getLoai() override;
	void Print() const override;
};

class SinhVienDH : public SinhVien {
private:
	string TenLV;
	double DiemLV;
public:
	SinhVienDH(string mssv = "", string ten = "", string dc = "", int tt = 0, double dtb = 0, bool dau = false, string tlv = "", double dlv = 0);
	void Input(istream& is) override;
	void setDau() override;
	int getLoai() override;
	void Print() const override;
};

class DsSinhVien {
private:
	vector<SinhVien*> sv;
	int DHCount;
	int CDCount;
public:
	void Input(SinhVien* s);
	void PrintDs();
	void PrintTN();
	void PrintSpe();
};