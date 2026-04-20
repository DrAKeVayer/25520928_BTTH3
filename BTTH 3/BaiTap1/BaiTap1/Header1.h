#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

class Diem {
protected:
	double x;
	double y;
public:
	Diem() = default;
	Diem(double _x, double _y);
	void Nhap();

	void multx(double mult);
	void multy(double mult);
	void movex(double dis);
	void movey(double dis);
	double getx() const;
	double gety() const;
	void setx(double a);
	void sety(double a);
};

class TamGiac {
protected:
	vector<Diem> diem;
	double dtich = 0;
	double cvi = 0;
	int loai = 0;
	double canh12 = 0;
	double canh13 = 0;
	double canh23 = 0;
	Diem TrongTam;
	vector<pair<double, double>> move;
public:
	TamGiac();
	void Nhap();
	void CapNhatCanh();
	void DoDoi();

	void DienTich();
	void ChuVi();
	void TinhTien();
	void Quay(); //degree clockwise
	void PhongTo();
	void ThuNho();
	void Xuat();

	void Loai();
};

double Dodai(Diem a, Diem b);