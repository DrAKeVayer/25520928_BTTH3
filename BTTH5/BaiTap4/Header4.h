#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

class NhanVien {
protected:
	string MaNV;
	string HVT;
	int Tuoi;
	string SDT;
	string Email;
	int LCB;
	int Luong;
public:
	NhanVien(string ma = "", string ten = "", int t = 0, string dt = "", string em = "", int lcb = 0, int luong = 0);
	virtual void TinhLuong() = 0;
	virtual void Print();
	int getLuong();
};

class LTV : public NhanVien {
private:
	double OVT;
public:
	LTV(string ma = "", string ten = "", int t = 0, string dt = "", string em = "", int lcb = 0, int luong = 0, double ovt = 0.0);
	void TinhLuong() override;
	void Print() override;
};

class KCV : public NhanVien {
private:
	int Loi;
public:
	KCV(string ma = "", string ten = "", int t = 0, string dt = "", string em = "", int lcb = 0, int luong = 0, int l = 0);
	void TinhLuong() override;
	void Print() override;
};

class DanhSach {
protected:
	vector<NhanVien*> nv;
	double LTB = 0;
public:
	void Input();
	void PrintAll();
	void TinhLTB();
	void PrintSpe();
};