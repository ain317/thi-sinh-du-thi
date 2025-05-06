#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ThiSinh {
protected:            // hàm để kế thừa
    string soBaoDanh;
    string hoTen;
    string diaChi;
    int mucUuTien;

public:
    ThiSinh() {}
    ThiSinh(string sbd, string ht, string dc, int uutien){
        soBaoDanh = sbd;
        hoTen = ht;
        diaChi = dc;
        mucUuTien = uutien;
        }

    virtual void nhap() { //void là hàm không trả về giá trị, virtual là hàm ảo không thể sử dụng ngoài class, có thể kế thừa và ghi đè        
        cout << "Nhap so bao danh: ";
        getline(cin, soBaoDanh);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap muc uu tien: ";
        cin >> mucUuTien;
        cin.ignore(); // cin.ignore là bỏ qua giá trị nhập vào
    }

    virtual void hienThi() const {
        cout << "So bao danh: " << soBaoDanh << ", Ho ten: " << hoTen
             << ", Dia chi: " << diaChi << ", Muc uu tien: " << mucUuTien;
    }

    string getSoBaoDanh() const {
        return soBaoDanh;
    }

    virtual ~ThiSinh() {} //~ là hàm huỷ
};

class ThiSinhKhoiA : public ThiSinh { //lớp ThisinhKhoiA kế thừa lớp ThiSinh
public:
    void hienThi() const override { //override là ghi đè, const là lệnh cố định các giá trị
        ThiSinh::hienThi();
        cout << ", Khoi thi: A (Toan, Ly, Hoa)" << endl;
    }
};

class ThiSinhKhoiB : public ThiSinh { // lớp ThiSinhKhoiB kế thừa lớp ThiSinh
public:
    void hienThi() const override {
        ThiSinh::hienThi();
        cout << ", Khoi thi: B (Toan, Hoa, Sinh)" << endl;
    }
};

class ThiSinhKhoiC : public ThiSinh {
public:
    void hienThi() const override {
        ThiSinh::hienThi();
        cout << ", Khoi thi: C (Van, Su, Dia)" << endl;
    }
};

class TuyenSinh {
private:
    vector<ThiSinh*> danhSach;  //vector là kiểu danh sách là mảng không cố định là mảng động, *> là con trỏ chỉ đến danhSach

public:
    void themThiSinh() {
        int chon;
        cout << "Chon khoi thi (1: A, 2: B, 3: C): ";
        cin >> chon;
        cin.ignore();

        ThiSinh* ts = nullptr; //nullptr là con trỏ cố định
        if (chon == 1)
            ts = new ThiSinhKhoiA();
        else if (chon == 2)
            ts = new ThiSinhKhoiB();
        else if (chon == 3)
            ts = new ThiSinhKhoiC();

        if (ts) {
            ts->nhap();
            danhSach.push_back(ts);
        }
    }

    void hienThiThongTin() {
        for (auto ts : danhSach) { // auto là gắn trực tiếp giá trị của ts thành giá trị của danh sách. Hoạt động như vòng for
            ts->hienThi();
        }
    }

    void timKiemTheoSBD() {
        string sbd;
        cout << "Nhap so bao danh can tim: ";
        getline(cin, sbd);

        for (auto ts : danhSach) {
            if (ts->getSoBaoDanh() == sbd) {
                ts->hienThi();
                return;
            }
        }
        cout << "Khong tim thay thi sinh co SBD: " << sbd << endl;
    }

    ~TuyenSinh() {
        for (auto ts : danhSach)
            delete ts;
    }
};

int main() {
    TuyenSinh ts;
    int luaChon;

    while (true){// vòng lặp vô tận không cần điều kiện
     
        cout << "\n_____ MENU _____\n";
        cout << "1. Them thi sinh\n";
        cout << "2. Hien thi thong tin thi sinh\n";
        cout << "3. Tim kiem theo so bao danh\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();
       
        if(luaChon == 1){
                ts.themThiSinh();
        } else if(luaChon == 2){
                ts.hienThiThongTin();
        } else if(luaChon ==  3){        
         
                ts.timKiemTheoSBD();
        } else if(luaChon == 4){     
         
                cout << "Thoat chuong trinh.\n";
            break;
        } else {
                cout << "Lua chon khong hop le.\n";
        }

    }

    return 0;
}
