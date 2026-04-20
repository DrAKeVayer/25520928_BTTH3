#include "Header1.h"

const double PI = acos(-1.0);
const double epsilon = 1e-6;

enum LoaiTamGiac {
	DEU = 1,
	CAN = 2,
	VUONG = 3,
	VUONGCAN = 4,
	THUONG = 5
};

Diem::Diem(double _x, double _y) : x(_x), y(_y) {}

void Diem::Nhap() {
	double a, b;
	cin >> a >> b;
	this->x = a; this->y = b;
}

void Diem::multx(double mult) {
	x *= mult;
}
void Diem::multy(double mult) {
	y *= mult;
}
void Diem::movex(double dis) {
	x += dis;
}
void Diem::movey(double dis) {
	y += dis;
}
double Diem::getx() const {
	return x;
}
double Diem::gety() const {
	return y;
}
void Diem::setx(double a) {
	x = a;
}
void Diem::sety(double a) {
	y = a;
}

TamGiac::TamGiac() {}
void TamGiac::Nhap() {
	diem.clear();
	for (int i = 0; i < 3; i++) {
		cout << '\n' << "Nhap diem " << i + 1 << ":";
		Diem p;
		p.Nhap();
		diem.push_back(p);
	}
	CapNhatCanh();
}
void TamGiac::CapNhatCanh() {
	canh12 = Dodai(diem[0], diem[1]);
	canh13 = Dodai(diem[0], diem[2]);
	canh23 = Dodai(diem[1], diem[2]);
}

void TamGiac::DoDoi() {
	move.clear();
	double nx = (diem[0].getx() + diem[1].getx() + diem[2].getx()) / 3;
	double ny = (diem[0].gety() + diem[1].gety() + diem[2].gety()) / 3;
	TrongTam = Diem(nx, ny);
	for (auto& p : diem) {
		pair<double, double> h;
		h.first = p.getx() - TrongTam.getx();
		h.second = p.gety() - TrongTam.gety();
		move.push_back(h);
	}
}

void TamGiac::DienTich() {
	dtich = 0.5 * fabs(diem[0].getx() * (diem[1].gety() - diem[2].gety()) + diem[1].getx() * (diem[2].gety() - diem[0].gety()) + diem[2].getx() * (diem[0].gety() - diem[1].gety()));
}
void TamGiac::ChuVi() {
	cvi = canh12 + canh13 + canh23;
}
void TamGiac::TinhTien() {
	cout << "Chọn hướng: 1. Trái / 2. Phải / 3. Lên / 4. Xuống";
	int direct; cin >> direct;
	cout << '\n' << "Nhập khoảng cách: ";
	double dis; cin >> dis;
	if (direct == 1) {
		for (auto& p : diem) p.movex(-dis);
	}
	else if (direct == 2) {
		for (auto& p : diem) p.movex(dis);
	}
	else if (direct == 3) {
		for (auto& p : diem) p.movey(dis);
	}
	else if (direct == 4) {
		for (auto& p : diem) p.movey(-dis);
	}
}
void TamGiac::Quay() { //degree counter clockwise, centered (0, 0)
	cout << "Nhập góc quay theo chiều kim đồng hồ (độ): ";
	double angle; cin >> angle;
	angle = angle * PI / 180.0;
	for (auto& p : diem) {
		double nx = p.getx() * cos(angle) - p.gety() * sin(angle);
		double ny = p.getx() * sin(angle) + p.gety() * cos(angle);
		p.setx(nx);
		p.sety(ny);
	}
}

void TamGiac::PhongTo() {
	DoDoi();
	cout << "Nhập hệ số phóng to: ";
	double mult; cin >> mult;
	for (auto& h : move) {
		h.first *= mult;
		h.second *= mult;
	}
	for (int i = 0; i < 3; i++) {
		double nx = TrongTam.getx() + move[i].first;
		double ny = TrongTam.gety() + move[i].second;
		diem[i].setx(nx);
		diem[i].sety(ny);
	}
	CapNhatCanh();
}
void TamGiac::ThuNho() {
	DoDoi();
	cout << "Nhập hệ số thu nhỏ: ";
	double mult; cin >> mult;
	mult = 1 / mult;
	for (auto& h : move) {
		h.first *= mult;
		h.second *= mult;
	}
	for (int i = 0; i < 3; i++) {
		double nx = TrongTam.getx() + move[i].first;
		double ny = TrongTam.gety() + move[i].second;
		diem[i].setx(nx);
		diem[i].sety(ny);
	}
	CapNhatCanh();
}

void TamGiac::Xuat() {
	Loai();
	DienTich();
	ChuVi();
	cout << "Tam giác gồm 3 điểm: A(" << diem[0].getx() << "; " << diem[0].gety()
		<< "), B(" << diem[1].getx() << "; " << diem[1].gety()
		<< "), C(" << diem[2].getx() << "; " << diem[2].gety() << ")" << '\n';
	cout << "Độ dài 3 cạnh lần lượt là: " << canh12 << ", " << canh23 << ", " << canh13 << '\n';
	cout << "Đây là tam giác ";
	if (loai == CAN) cout << "cân" << '\n';
	else if (loai == DEU) cout << "đều" << '\n';
	else if (loai == VUONGCAN) cout << "vuông cân" << '\n';
	else if (loai == VUONG) cout << "vuông" << '\n';
	else if (loai == THUONG) cout << "thường" << '\n';

	cout << "Diện tích là " << dtich << " đơn vị" << '\n';
	cout << "Chu vi là " << cvi << " đơn vị" << '\n';
}

void TamGiac::Loai() {
	if (fabs(canh12 - canh13) < epsilon && fabs(canh12 - canh23) < epsilon) {
		loai = DEU;
		return;
	}
	else if (fabs(canh12 - canh13) < epsilon || fabs(canh23 - canh13) < epsilon || fabs(canh12 - canh23) < epsilon) {
		loai = CAN;
	}
	if (fabs(canh12 * canh12 + canh13 * canh13 - canh23 * canh23) < epsilon ||
		fabs(canh12 * canh12 + canh23 * canh23 - canh13 * canh13) < epsilon ||
		fabs(canh13 * canh13 + canh23 * canh23 - canh12 * canh12) < epsilon
		) {
		if (loai == CAN) loai = VUONGCAN;
		else loai = VUONG;
		return;
	}
	else if (loai == 0) loai = THUONG;
}

double Dodai(Diem a, Diem b) {
	double d = sqrt(pow((b.getx() - a.getx()), 2) + pow((b.gety() - a.gety()), 2));
	return d;
}