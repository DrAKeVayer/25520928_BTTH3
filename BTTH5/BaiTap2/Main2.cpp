#include "Header2.h"

int main() {
	SetConsoleOutputCP(65001);
	DsGiaoDich ds;
	cout << "1: Đất, 2: Nhà, 3: Chung cư, Khác: Exit" << '\n';
	int action;
	while (true) {
		cin >> action;
		GiaoDich* g;
		if (action == 1) {
			g = new GiaoDichDat();
			cin >> *g;
		}
		else if (action == 2) {
			g = new GiaoDichNha();
			cin >> *g;
		}
		else if (action == 3) {
			g = new GiaoDichChungCu();
			cin >> *g;
		}
		else break;
		ds.Input(g);
	}
	ds.PrintDs();
}