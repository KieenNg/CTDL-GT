#include <iostream>
using namespace std;

int tong_cac_chu_so(int a){
    if(a < 0){
        return 0;
    }
    if(a < 10){
        return a;
    }
    else {
        return a % 10 + tong_cac_chu_so(a / 10);
    }
}

int main(){
    int x;
    cout << "Nhap vao so x muon tinh: ";
    cin >> x;
    cout << "Tong cac chu so cua x: " << tong_cac_chu_so(x) << endl;
    return 0;
}
