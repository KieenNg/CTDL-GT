#include <iostream>
using namespace std;

void cap_so_cong(int m, int n, int d){
    if(n <= 0) {
        return;
    }
    else {
        cout << m << "\t";
        cap_so_cong(m + d, n - 1, d);
    }
}
int main(){
    cout << "Day cap so cong: ";
    cap_so_cong(5, 9, 2);
    cout << "\n";
}
