#include<iostream>
using namespace std;

// hàm tìm ước chung lớn nhất
int UCLN(int a, int b){
    if(b == 0){
        return a;
    }
    else {
        return UCLN(b, a % b);
    }
}
// hàm tính tổng các chữ số nguyên dương
int tong_cac_chu_so(int n){
    if(n<0) return 0;
    if(n < 10){
        return n;
    }
    else {
        return n % 10 + tong_cac_chu_so(n / 10);
    }
}
int main(){ 
    // uoc chung lon nhat
    cout << UCLN(20, 5) << endl;
    //tong cac chu so
    cout << tong_cac_chu_so(99) << endl;
}