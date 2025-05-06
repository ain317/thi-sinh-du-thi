
#ifndef THISINHKHOIB_H
#define THISINHKHOIB_H
#include "Thisinh.hpp"
#include <iostream>
class ThiSinhKhoiB : public ThiSinh { // lớp ThiSinhKhoiB kế thừa lớp ThiSinh
    public:
        void hienThi() const override {
            ThiSinh::hienThi();
            cout << ", Khoi thi: B (Toan, Hoa, Sinh)" << endl;
        }
    };
    #endif