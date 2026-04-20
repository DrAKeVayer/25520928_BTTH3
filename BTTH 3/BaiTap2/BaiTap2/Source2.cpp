#include "Header2.h"

const double PI = acos(-1.0);
const double epsilon = 1e-6;

enum LoaiTamGiac {
	DEU = 1,
	THUONG = 0
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

DaGiac::DaGiac() {}
void DaGiac::Nhap() {
	diem.clear();
	cout << "Nhập số điểm > 2: ";
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << '\n' << "Nhap diem " << i + 1 << ":";
		Diem p;
		p.Nhap();
		diem.push_back(p);
	}
	CapNhatCanh();
}
void DaGiac::CapNhatCanh() {
	canh.clear();
	for (int i = 0; i < diem.size() - 1; i++) {
		canh.push_back(Dodai(diem[i], diem[i + 1]));
	}
	canh.push_back(Dodai(diem[0], diem.back()));
}

void DaGiac::DoDoi() {
	move.clear();
	double nx = 0;
	double ny = 0;
	for (int i = 0; i < diem.size(); i++) {
		nx += diem[i].getx();
		ny += diem[i].gety();
	}
	nx /= diem.size();
	ny /= diem.size();
	TrongTam = Diem(nx, ny);
	for (auto& p : diem) {
		pair<double, double> h;
		h.first = p.getx() - TrongTam.getx();
		h.second = p.gety() - TrongTam.gety();
		move.push_back(h);
	}
}

void DaGiac::DienTich() {
	dtich = 0.0;
	for (int i = 0; i < diem.size(); i++) {
		int j = (i + 1) % diem.size();
		dtich += diem[i].getx() * diem[j].gety();
		dtich -= diem[i].gety() * diem[j].getx();
	}
}
void DaGiac::ChuVi() {
	cvi = 0;
	for (int i = 0; i < diem.size(); i++) {
		cvi += canh[i];
	}
}
void DaGiac::TinhTien() {
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
void DaGiac::Quay() { //degree counter clockwise, centered (0, 0)
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

void DaGiac::PhongTo() {
	DoDoi();
	cout << "Nhập hệ số phóng to: ";
	double mult; cin >> mult;
	for (auto& h : move) {
		h.first *= mult;
		h.second *= mult;
	}
	for (int i = 0; i < diem.size(); i++) {
		double nx = TrongTam.getx() + move[i].first;
		double ny = TrongTam.gety() + move[i].second;
		diem[i].setx(nx);
		diem[i].sety(ny);
	}
	CapNhatCanh();
}
void DaGiac::ThuNho() {
	DoDoi();
	cout << "Nhập hệ số thu nhỏ: ";
	double mult; cin >> mult;
	mult = 1 / mult;
	for (auto& h : move) {
		h.first *= mult;
		h.second *= mult;
	}
	for (int i = 0; i < diem.size(); i++) {
		double nx = TrongTam.getx() + move[i].first;
		double ny = TrongTam.gety() + move[i].second;
		diem[i].setx(nx);
		diem[i].sety(ny);
	}
	CapNhatCanh();
}

void DaGiac::Xuat() {
	Loai();
	DienTich();
	ChuVi();
	if (diem.size() == 3) cout << "Tam ";
	else if (diem.size() == 4) cout << "Tứ ";
	else if (diem.size() == 5) cout << "Ngũ ";
	else if (diem.size() == 6) cout << "Lục ";
	else if (diem.size() == 7) cout << "Thất ";
	else if (diem.size() == 8) cout << "Bát ";
	else if (diem.size() == 9) cout << "Cửu ";
	else if (diem.size() == 10) cout << "Thập ";
	else cout << diem.size() << " ";

	cout << " giác gồm " << diem.size() << " điểm: ";
	for (int i = 0; i < diem.size(); i++) {
		cout << "(" << diem[i].getx() << ", " << diem[i].gety() << ") - ";
	}
	cout << '\n' << "Độ dài " << diem.size() << " cạnh lần lượt là: ";
	for (int i = 0; i < canh.size(); i++) {
		cout << canh[i] << ", ";
	}
	cout << '\n' << "Đây là đa giác ";
	if (loai == DEU) cout << "đều" << '\n';
	else cout << "thường" << '\n';

	cout << "Diện tích là " << dtich << " đơn vị" << '\n';
	cout << "Chu vi là " << cvi << " đơn vị" << '\n';
}

void DaGiac::Loai() {
	DoDoi();
	double base = canh[0];
	for (int i = 1; i < canh.size(); i++) {
		if (fabs(canh[i] - base) > epsilon) {
			loai = THUONG;
			return;
		}
	}
	vector<double> disFromCen;
	for (int i = 0; i < diem.size(); i++) {
		disFromCen.push_back(Dodai(TrongTam, diem[i]));
	}
	base = disFromCen[0];
	for (int i = 0; i < disFromCen.size(); i++) {
		if (fabs(disFromCen[i] - base) > epsilon) {
			loai = THUONG;
			return;
		}
	}
	loai = DEU;
}

double Dodai(Diem a, Diem b) {
	double d = sqrt(pow((b.getx() - a.getx()), 2) + pow((b.gety() - a.gety()), 2));
	return d;
}