#ifndef THISINH_H
#define THISINH_H
#include <iostream>
#include <sstream>
using namespace std;
bool CheckName( string a){
    stringstream  cw(a);
    string cn;
    while( cw >> cn){
        for ( char Ktra : cn){
            if (!isalpha(Ktra)){
                return false;
            }
        }
    }
    return true;
}

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

            while (true){

        
    
        
                cout << "Nhap ho ten: ";
        
                getline(cin, hoTen);
                if(CheckName(hoTen)){
                    break;
                }else{
                    continue;
                }
            }
          
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
    
    #endif