#include<iostream>
#include<vector>
#include"Thisinh.hpp"
#include"ThiSinhKhoiA.hpp"
#include"ThiSinhKhoiB.hpp"
#include"ThiSinhKhoiC.hpp"
#include"TuyenSinh.hpp"
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
