#include "TongDai.h"
#include "fstream"

using namespace std;

void TongDai::caiDatDanhSach(){
    ifstream fin;
    fin.open("TongDai.txt", ios::in);

    string line;
    while(getline(fin,line)){
        ls.insert(line);
    }
}

bool TongDai::kiemTraSoDienThoai(string sdt){
    size_t index = ls.findEle(sdt);
    if(index == -1)
        return false;
    else 
        return true;
}