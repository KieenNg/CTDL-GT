#include <iostream>
#include <string.h>
using namespace std;

int UCLN(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int tong_cac_chu_so(int n){
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

void dao_chuoi_ky_tu(char *str){
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start ++;
        end --;
    }
}

int tinh_giai_thua(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result = result * i;
    }
    return result;
}

int tinh_to_hop(int n, int k){
    int temp = 1;
    for(int i = 0; i < k; i++){
        temp = temp * (n-i);
    }
    int result = temp / tinh_giai_thua(k);
    return result;
}

void cap_so_cong(int m, int n, int d){
    for(int i = 0; i < n; i++){
        cout << m << "\t";
        m = m + d;
    }
    cout << "\n";
    return;
}

int main(){
    cout << UCLN(5, 15) << endl;
    cout << tong_cac_chu_so(98) << endl;
    char str[] = "Nguyen Kien";
    dao_chuoi_ky_tu(str);
    cout << str << endl;
    cout << tinh_giai_thua(5) << endl;
    cout << tinh_to_hop(21, 5) << endl;
    cap_so_cong(6, 9, 4);
}
