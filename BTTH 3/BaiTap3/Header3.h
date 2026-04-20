#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

enum SoSanh {
	NHOHON = -1,
	BANG = 0,
	LONHON = 1
};

using ll = long long;

ll gcd(ll a, ll b);

bool isPrime(ll x); //Độ phức tạp sqrt(n)


class PhanSo {
protected:
	ll tu = 0;
	ll mau = 0;
public:
	PhanSo() : tu(0), mau(1) {}
	PhanSo(ll _t, ll _m);
	ll getTu() const;
	ll getMau() const;
	void setTu(ll a);
	void setMau(ll a);
	void RutGon();
	void Print();
};

class DsPhanSo {
protected:
	vector<PhanSo> ps;
	PhanSo Tong;
	PhanSo Max;
	PhanSo Min;
	PhanSo MaxPrime;
	bool hasMaxPrime = false;
public:
	int SoSanh(PhanSo a, PhanSo b);
	void Nhap();
	PhanSo Cong(const PhanSo& a, const PhanSo& b);
	void CongDs();
	void MaxDs();
	void MinDs();
	void MaxPrimeDs();
	void PrintDs();
	void SortAscDs(ll low, ll high);
	void SortDesDs(ll low, ll high);
};