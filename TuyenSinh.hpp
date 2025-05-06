#ifndef TUYENSINH_H
#define TUYENSINH_H
#include "Thisinh.hpp"
#include <iostream>
#include<vector>
#include "ThiSinhKhoiA.hpp"
#include "ThiSinhKhoiB.hpp"
#include "ThiSinhKhoiC.hpp"
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
    #endif