#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

class Candidate {
protected:
	string Ma;
	string HVTen;
	int DSinh;
	int TSinh;
	int NSinh;
	double Toan;
	double Van;
	double Anh;
	double Tong;
public:
	Candidate(string _M = "0", string _t = "0", int _d = 0, int _m = 0, int _y = 0, double _T = 0, double _V = 0, double _A = 0, double _S = 0) :
		Ma(_M), HVTen(_t), DSinh(_d), TSinh(_m), NSinh(_y), Toan(_T), Van(_V), Anh(_A), Tong(_S) {
		Tong = Toan + Van + Anh;
	}
	string getMa() const;
	string getHVTen() const;
	int getDSinh() const;
	int getTSinh() const;
	int getNSinh() const;
	double getToan() const;
	double getVan() const;
	double getAnh() const;
	double getTong() const;
};

class CandidateList {
protected:
	vector<Candidate> cd;
	bool sorted = false;
public:
	void Input();
	void PrintCD(const Candidate& c) const;
	void PrintCDList();
	void Sort(int low, int high);
	void List15();
	void PrintMax();
	int getSize() const;
};