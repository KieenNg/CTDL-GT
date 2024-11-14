#include <iostream>
using namespace std;

int tinh_giai_thua(int n){
    if(n == 0) return 1;
    if(n == 1) {
        return 1;
    }
    else {
        return n * tinh_giai_thua(n-1);
    }
}
int tinh_to_hop(int n, int k){
    if(k > n) return 0;
    return (tinh_giai_thua(n)) / (tinh_giai_thua(k) * tinh_giai_thua(n - k));
}

int main(){
    int n = 3;
    cout << tinh_giai_thua(9) << endl;
    cout << tinh_to_hop(9, 6) << endl;
}
