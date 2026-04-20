#include "Header3.h"
ll gcd(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

bool isPrime(ll x) {
	if (x <= 1) return false;
	if (x == 2 || x == 3) return true;
	if (x % 2 == 0) return false;
	for (long long i = 3; i * i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

PhanSo::PhanSo(ll _t, ll _m) : tu(_t), mau(_m) {
	if (_m < 0) {
		mau = -mau;
		tu = -tu;
	}
}

ll PhanSo::getTu() const {
	return tu;
}
ll PhanSo::getMau() const {
	return mau;
}
void PhanSo::setTu(ll a) {
	tu = a;
}
void PhanSo::setMau(ll a) {
	mau = a;
}
void PhanSo::RutGon() {
	ll g = gcd(tu, mau);
	tu /= g;
	mau /= g;
}

void PhanSo::Print() {
	cout << tu << "/" << mau;
}

void DsPhanSo::Nhap() {
	ps.clear();
	int n;
	cout << "Nhập số phân số: " << '\n';
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll t, m;
		cout << "Nhập tử cho phân số " << i+1 << ": " << '\n';
		cin >> t;
		cout << "Nhập mẫu: " << '\n';
		cin >> m;
		PhanSo p(t, m);
		ps.push_back(p);
	}
}

PhanSo DsPhanSo::Cong(const PhanSo& a, const PhanSo& b) {
	ll g = gcd(a.getMau(), b.getMau());
	ll ntu = a.getTu() * (b.getMau() / g) + b.getTu() * (a.getMau() / g);
	ll nmau = a.getMau() * (b.getMau() / g);
	PhanSo res(ntu, nmau);
	res.RutGon();
	return res;
}

void DsPhanSo::CongDs() {
	Tong = ps[0];
	for (int i = 1; i < ps.size(); i++) {
		Tong = Cong(Tong, ps[i]);
	}
}

int DsPhanSo::SoSanh(PhanSo a, PhanSo b) { //nhận tham trị trực tiếp vì luôn phải tạo object để rút gọn nếu không thay đổi object ban đầu
	a.RutGon();
	b.RutGon();
	ll x = a.getTu() * b.getMau();
	ll y = a.getMau() * b.getTu();
	if (x < y) return NHOHON;
	else if (x == y) return BANG;
	else return LONHON;
}

void DsPhanSo::MaxDs() {
	Max = ps[0];
	for (int i = 1; i < ps.size(); i++) {
		if (SoSanh(Max, ps[i]) == NHOHON) Max = ps[i];
	}
}

void DsPhanSo::MinDs() {
	Min = ps[0];
	for (int i = 1; i < ps.size(); i++) {
		if (SoSanh(Min, ps[i]) == LONHON) Min = ps[i];
	}
}

void DsPhanSo::MaxPrimeDs() {
	ll max = -1;
	for (int i = 0; i < ps.size(); i++) {
		if ((isPrime(ps[i].getTu()) && ps[i].getTu() > max) || ((isPrime(ps[i].getTu()) && ps[i].getTu() == max) && SoSanh(ps[i], MaxPrime) == LONHON)) {
			max = ps[i].getTu();
			MaxPrime = ps[i];
		}
	}
	if (max != - 1) {
		hasMaxPrime = true;
	}
}

void DsPhanSo::PrintDs() {
	MaxDs();
	MinDs();
	MaxPrimeDs();
	CongDs();
	cout << "Danh sách phân số ban đầu: " << '\n';
	for (int i = 0; i < ps.size(); i++) {
		ps[i].Print();
		cout << " | ";
	}
	cout << '\n' << "Phân số lớn nhất: ";
	Max.Print();
	cout << '\n' << "Phân số nhỏ nhất: ";
	Min.Print();
	if (hasMaxPrime){
		cout << '\n' << "Phân số có tử số là số nguyên tố lớn nhất: ";
		MaxPrime.Print();
	}
	else {
		cout << "Không có phân số có tử là số nguyên tố";
	}
	SortAscDs(0, ps.size() - 1);
	cout << '\n' << "Phân số được sorted tăng dần: " << '\n';
	for (int i = 0; i < ps.size(); i++) {
		ps[i].Print();
		cout << " | ";
	}
	SortDesDs(0, ps.size() - 1);
	cout << '\n' << "Phân số được sorted giảm dần: " << '\n';
	for (int i = 0; i < ps.size(); i++) {
		ps[i].Print();
		cout << " | ";
	}
}

void DsPhanSo::SortAscDs(ll low, ll high) { //Quick sort is used
	if (low >= high) return;
	PhanSo pivot = ps[low + (high - low) / 2];
	int i = low;
	int j = high;

	while (i <= j) {
		while (SoSanh(ps[i], pivot) == NHOHON) i++;
		while (SoSanh(ps[j], pivot) == LONHON) j--;
		if (i <= j) {
			swap(ps[i], ps[j]);
			i++;
			j--;
		}
	}
	if (low < j) SortAscDs(low, j);
	if (i < high) SortAscDs(i, high);
}

void DsPhanSo::SortDesDs(ll low, ll high) {
	if (low >= high) return;
	PhanSo pivot = ps[low + (high - low) / 2];
	int i = low;
	int j = high;
	
	while (i <= j) {
		while (SoSanh(ps[i], pivot) == LONHON) i++;
		while (SoSanh(ps[j], pivot) == NHOHON) j--;
		if (i <= j) {
			swap(ps[i], ps[j]);
			i++;
			j--;
		}
	}
	if (low < j) SortDesDs(low, j);
	if (i < high) SortDesDs(i, high);
}