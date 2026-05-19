#include "Header2.h"

GiaoDich::GiaoDich(string ma, int d, int m, int y, long long dg, double dt) : MaGD(ma), D(d), T(m), N(y), DonGia(dg), DienTich(dt) {}
long long GiaoDich::getTien() const {
	return Tien;
}
int GiaoDich::getT() const {
	return T;
}
int GiaoDich::getN() const {
	return N;
}

void GiaoDich::Input(istream& is) {
	cout << "Mã GD: "; getline(is >> ws, MaGD);
	cout << "Ngày tháng năm GD: "; is >> D >> T >> N;
	cout << "Đơn giá: "; is >> DonGia;
	cout << "Diện tích: "; is >> DienTich;
}

istream& operator>>(istream& is, GiaoDich& gd) {
	gd.Input(is);
	return is;
}

GiaoDichDat::GiaoDichDat(string ma, int d, int m, int y, long long dg, double dt, char type) : GiaoDich(ma, d, m, y, dg, dt), type(type) {
	TinhTien();
}

void GiaoDichDat::Input(istream& is) {
	GiaoDich::Input(is);
	cout << "Loại đất (A/B/C): "; is >> type;
	TinhTien();
}

void GiaoDichDat::TinhTien() {
	if (type == 'B' || type == 'C') {
		Tien = DonGia * DienTich;
	}
	else if (type == 'A') {
		Tien = DonGia * DienTich * 1.5;
	}
}

void GiaoDichDat::Print() {
	cout << "Mã giao dịch: " << MaGD << '\n';
	cout << "Ngày tháng năm giao dịch: " << D << "/" << T << "/" << N << '\n';
	cout << "Đơn giá: " << DonGia << "đ" << '\n';
	cout << "Diện tích: " << DienTich << '\n';
	cout << "Loại đất: " << type << '\n';
	cout << "Thành tiền: " << Tien << "đ" << '\n';
}

int GiaoDichDat::getLoai() const {
	return Dat;
}

GiaoDichNha::GiaoDichNha(string ma, int d, int m, int y, long long dg, double dt, char type, string dc) : GiaoDich(ma, d, m, y, dg, dt), type(type), DiaChi(dc) {
	TinhTien();
}

void GiaoDichNha::Input(istream& is) {
	GiaoDich::Input(is);
	cout << "Loại nhà (A = Cao cấp/B = thường): "; is >> type;
	cout << "Địa chỉ: "; getline(is >> ws, DiaChi);
	TinhTien();
}

void GiaoDichNha::TinhTien() {
	if (type == 'A') {
		Tien = DonGia * DienTich;
	}
	else if (type == 'B') {
		Tien = DonGia * DienTich * 0.9;
	}
}

void GiaoDichNha::Print() {
	cout << "Mã giao dịch: " << MaGD << '\n';
	cout << "Ngày tháng năm giao dịch: " << D << "/" << T << "/" << N << '\n';
	cout << "Đơn giá: " << DonGia << "đ" << '\n';
	cout << "Diện tích: " << DienTich << '\n';
	cout << "Loại nhà: ";
	if (type == 'A') cout << "Cao cấp" << '\n';
	else cout << "Thường" << '\n';
	cout << "Địa chỉ: " << DiaChi << '\n';
	cout << "Thành tiền: " << Tien << "đ" << '\n';
}

int GiaoDichNha::getLoai() const {
	return Nha;
}

GiaoDichChungCu::GiaoDichChungCu(string ma, int d, int m, int y, long long dg, double dt, string mc, int t) : GiaoDich(ma, d, m, y, dg, dt), MaCan(mc), Tang(t) {
	TinhTien();
}

void GiaoDichChungCu::Input(istream& is) {
	GiaoDich::Input(is);
	cout << "Mã căn: "; getline(is >> ws, MaCan);
	cout << "Tầng số: "; is >> Tang;
	TinhTien();
}

void GiaoDichChungCu::TinhTien() {
	if (Tang == 1) {
		Tien = DonGia * DienTich * 2;
	}
	else if (Tang >= 15) {
		Tien = DonGia * DienTich * 1.2;
	}
	else Tien = DonGia * DienTich;
}

void GiaoDichChungCu::Print() {
	cout << "Mã giao dịch: " << MaGD << '\n';
	cout << "Ngày tháng năm giao dịch: " << D << "/" << T << "/" << N << '\n';
	cout << "Đơn giá: " << DonGia << "đ" << '\n';
	cout << "Diện tích: " << DienTich << '\n';
	cout << "Tầng số: " << Tang << '\n';
	cout << "Mã căn: " << MaCan << '\n';
	cout << "Thành tiền: " << Tien << "đ" << '\n';
}

int GiaoDichChungCu::getLoai() const {
	return ChungCu;
}

void DsGiaoDich::Input(GiaoDich* g) {
	if (g) {
		gd.push_back(g);
		int Loai = g->getLoai();
		if (Loai == Dat) DatCount++;
		else if (Loai == Nha) NhaCount++;
		else if (Loai == ChungCu) {
			ChungCuCount++;
			TongTien += g->getTien();
		}
	}
}

void DsGiaoDich::Avg() {
	AvgTien = (double)TongTien / ChungCuCount;
}

void DsGiaoDich::PrintDs() {
	Avg();
	cout << "Có tổng cộng " << DatCount << " giao dịch đất" << '\n';
	cout << "Có tổng cộng " << NhaCount << " giao dịch nhà" << '\n';
	cout << "Có tổng cộng " << ChungCuCount << " giao dịch chung cư" << '\n';
	cout << "Trung bình thành tiền chung cư là: " << AvgTien << "đ" << '\n';
	cout << "Giao dịch nhà có giá trị cao nhất là: " << '\n';
	GiaoDich* MaxNha = nullptr;
	for (auto& a : gd) {
		if (dynamic_cast<GiaoDichNha*>(a)) {
			if (!MaxNha) MaxNha = a;
			else if (a->getTien() > MaxNha->getTien()) MaxNha = a;
		}
	}
	if (MaxNha) MaxNha->Print();
	cout << "Giao dịch trong tháng 12 năm 2024 là: " << '\n';
	for (auto& a : gd) {
		if (a->getT() == 12 && a->getN() == 2024) {
			a->Print();
		}
	}
}