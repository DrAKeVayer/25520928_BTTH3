#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

class DonThuc {
protected:
	int soMu;
	double heSo;
public:
	DonThuc(int _m = 0, double _h = 0) : soMu(_m), heSo(_h) {}
	int getMu() const;
	double getHeSo() const;
	void setHeSo(double a);

};

class DaThuc {
protected:
	vector<DonThuc> dt;
public:
	DaThuc() {}
	DaThuc(int n);
	void Nhap(int n);
	DaThuc operator+(const DaThuc& other);
	DaThuc operator-(const DaThuc& other);
	void Xuat();
	double TinhGiaTri(double x);
};
