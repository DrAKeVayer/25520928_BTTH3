#include "Header3.h"

int main() {
	SetConsoleOutputCP(65001);
	DsSinhVien ds;
	cout << "1: Đại học, 2: Cao đẳng, Khác: Exit" << '\n';
	int action;
	while (true) {
		cin >> action;
		SinhVien* g;
		if (action == 1) {
			g = new SinhVienDH();
			cin >> *g;
		}
		else if (action == 2) {
			g = new SinhVienCD();
			cin >> *g;
		}
		else break;
		ds.Input(g);
	}
	ds.PrintDs();
	ds.PrintTN();
	ds.PrintSpe();
}