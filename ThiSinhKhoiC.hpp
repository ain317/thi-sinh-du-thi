
#ifndef THISINHKHOIC_H
#define THISINHKHOIC_H
#include "Thisinh.hpp"
#include <iostream>
class ThiSinhKhoiC : public ThiSinh {
    public:
        void hienThi() const override {
            ThiSinh::hienThi();
            cout << ", Khoi thi: C (Van, Su, Dia)" << endl;
        }
    };
    #endif