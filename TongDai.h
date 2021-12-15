#ifndef TONGDAI_H
#define TONGDAI_H

#include "include.h"

using namespace std;

class TongDai{
    private: 
        LinkedList<string> ls;
    public :
        TongDai() = default;

        ~TongDai() = default;

        void caiDatDanhSach();
        bool kiemTraSoDienThoai();
};
#endif