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
	Dat = 1,
	Nha = 2,
	ChungCu = 3
};

class GiaoDich {
protected:
	string MaGD;
	int D;
	int T;
	int N;
	long long DonGia;
	long long Tien = 0;
	double DienTich;
public:
	GiaoDich(string ma = "", int d = 1, int m = 1, int y = 1, long long dg = 1, double dt = 1);
	virtual ~GiaoDich() {}
	virtual void Input(istream& is);
	friend istream& operator>>(istream& is, GiaoDich& gd);
	virtual void TinhTien() = 0;
	virtual void Print() = 0;
	long long getTien() const;
	int getT() const;
	int getN() const;
	virtual int getLoai() const = 0;
};

class GiaoDichDat : public GiaoDich {
protected:
	char type;
public:
	GiaoDichDat(string ma = "", int d = 1, int m = 1, int y = 1, long long dg = 1, double dt = 1, char type = 'a');
	void Input(istream& is) override;
	void TinhTien() override;
	void Print() override;
	int getLoai() const override;
};
// type A = cao cap
// type B = thuong
class GiaoDichNha : public GiaoDich {
protected:
	char type;
	string DiaChi;
public:
	GiaoDichNha(string ma = "", int d = 1, int m = 1, int y = 1, long long dg = 1, double dt = 1, char type = 'a', string dc = "");
	void Input(istream& is) override;
	void TinhTien() override;
	void Print() override;
	int getLoai() const override;
};

class GiaoDichChungCu : public GiaoDich {
protected:
	string MaCan;
	int Tang;
public:
	GiaoDichChungCu(string ma = "", int d = 1, int m = 1, int y = 1, long long dg = 1, double dt = 1, string mc = "", int t = 1);
	void Input(istream& is) override;
	void TinhTien() override;
	void Print() override;
	int getLoai() const override;
};


class DsGiaoDich {
protected:
	vector<GiaoDich*> gd;
	
	long long TongTien;
	double AvgTien;
	int DatCount = 0;
	int NhaCount = 0;
	int ChungCuCount = 0;
public:
	void Input(GiaoDich* g);
	void Avg();
	void PrintDs();
};