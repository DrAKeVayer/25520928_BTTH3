#include "Header6.h"

int main() {
	SetConsoleOutputCP(65001);
	CandidateList cd;
	cd.Input();
	cd.Sort(0, cd.getSize() - 1);
	cd.List15();
	cout << '\n' << "Danh sách thí sinh xếp theo tổng điểm thấp dần: " << '\n';
	cd.PrintCDList();
	cout << '\n' << "Thí sinh cao điểm nhất: ";
	cd.PrintMax();
	return 0;
}