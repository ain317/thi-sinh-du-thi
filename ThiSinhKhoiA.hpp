#ifndef THISINHKHOIA_H
#define THISINHKHOIA_H
#include "Thisinh.hpp"
#include <iostream>
using namespace std;
class ThiSinhKhoiA : public ThiSinh { //lớp ThisinhKhoiA kế thừa lớp ThiSinh
    public:
        void hienThi() const override { //override là ghi đè, const là lệnh cố định các giá trị
            ThiSinh::hienThi();
            cout << ", Khoi thi: A (Toan, Ly, Hoa)" << endl;
        }
    };
    #endif