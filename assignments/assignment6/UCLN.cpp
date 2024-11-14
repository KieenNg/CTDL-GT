#include <iostream>
using namespace std;

int UCLN(int a, int b){
    if(b == 0){
        return a;
    }
    else {
        return UCLN(b, a % b);
    }
}

int main(){
    int a = 20;
    int b = 15;
    cout << "UCLN cua 2 so a, b:\n";
    cout << UCLN(a, b) << endl;
    return 0;
}
