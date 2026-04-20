#include "Header6.h"
string Candidate::getMa() const {
	return Ma;
}

string Candidate::getHVTen() const {
	return HVTen;
}

int Candidate::getDSinh() const {
	return DSinh;
}

int Candidate::getTSinh() const {
	return TSinh;
}

int Candidate::getNSinh() const {
	return NSinh;
}

double Candidate::getToan() const {
	return Toan;
}

double Candidate::getVan() const {
	return Van;
}

double Candidate::getAnh() const {
	return Anh;
}

double Candidate::getTong() const {
	return Tong;
}

void CandidateList::Input() {
	cout << "Nhập số thí sinh: ";
	int n; cin >> n;
	string Ma;
	string HVTen;
	int DSinh;
	int TSinh;
	int NSinh;
	double Toan;
	double Van;
	double Anh;
	cd.clear();
	cout << "Kí hiệu: " << '\n' << "1: Mã số" << '\n' << "2: Họ và tên" << '\n' << "3: Ngày - Tháng - Năm sinh" << '\n' << "4: Điểm Toán - Văn - Anh" << '\n';
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "1: ";
		cin >> Ma;
		cout << '\n' << "2: ";
		cin.ignore();
		getline(cin >> ws, HVTen);
		cout << '\n' << "3: ";
		cin >> DSinh >> TSinh >> NSinh;
		cout << '\n' << "4: ";
		cin >> Toan >> Van >> Anh;
		Candidate c(Ma, HVTen, DSinh, TSinh, NSinh, Toan, Van, Anh, 0);
		cd.push_back(c);
	}
}
void CandidateList::PrintCD(const Candidate& c) const {
	cout << "Mã thí sinh: " << c.getMa() << '\n';
	cout << "Họ và tên: " << c.getHVTen() << '\n';
	cout << "Ngày tháng năm sinh: " << c.getDSinh() << "/" << c.getTSinh() << "/" << c.getNSinh() << '\n';
	cout << "Điểm toán văn anh: " << c.getToan() << " - " << c.getVan() << "/" << c.getAnh() << '\n';
	cout << "Tổng điểm: " << c.getTong();
	cout << '\n';
}
void CandidateList::PrintCDList() {
	for (int i = 0; i < cd.size(); i++) {
		PrintCD(cd[i]);
	}
}
void CandidateList::Sort(int low, int high) {
	if (low >= high) return;
	int pivot = cd[low + (high - low) / 2].getTong();
	int i = low;
	int j = high;

	while (i <= j) {
		while (cd[i].getTong() > pivot) i++;
		while (cd[j].getTong() < pivot) j--;
		if (i <= j) {
			swap(cd[i], cd[j]);
			i++;
			j--;
		}
	}
	sorted = true;
	if (low < j) Sort(low, j);
	if (i < high) Sort(i, high);
}
void CandidateList::List15() {
	bool found = false;
	cout << '\n' << "Danh sánh thí sinh tổng điểm lớn hơn 15: " << '\n';
	for (int i = 0; i < cd.size(); i++) {
		if (cd[i].getTong() > 15.0) {
			PrintCD(cd[i]);
			found = true;
		}
	}
	if (!found) cout << "Không có ai có tổng điểm lớn hơn 15." << '\n';
}
void CandidateList::PrintMax() {
	if (sorted) {
		double max = cd[0].getTong();
		int i = 0;
		while (cd[i].getTong() == max) {
			PrintCD(cd[i]);
			i++;
			if (i == cd.size()) break;
		}
	}
	else {
		Sort(0, cd.size() - 1);
		PrintMax();
	}
}
int CandidateList::getSize() const {
	return cd.size();
}