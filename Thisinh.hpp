#ifndef THISINH_H
#define THISINH_H
#include <iostream>
using namespace std;

class ThiSinh {

    
    
    
    
    protected:
        string soBaoDanh;
        string hoTen;
        string diaChi;
        int mucUuTien;
    
    public:
        ThiSinh() {}
        ThiSinh(string sbd, string ht, string dc, int uutien)
            : soBaoDanh(sbd), hoTen(ht), diaChi(dc), mucUuTien(uutien) {}
    
        virtual void nhap() {
            cout << "Nhap so bao danh: ";
            getline(cin, soBaoDanh);
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap dia chi: ";
            getline(cin, diaChi);
            cout << "Nhap muc uu tien: ";
            cin >> mucUuTien;
            cin.ignore();
        }
    
        virtual void hienThi() const {
            cout << "So bao danh: " << soBaoDanh << ", Ho ten: " << hoTen
                 << ", Dia chi: " << diaChi << ", Muc uu tien: " << mucUuTien;
        }
    
        string getSoBaoDanh() const {
            return soBaoDanh;
        }
    
        virtual ~ThiSinh() {}
    };
    #endif