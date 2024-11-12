#include <iostream>
using namespace std;

void HNTower(char A, char B, char C, int N){
    if(N == 1){
        cout << A << "---->" << B << endl;
    }
    else
    {
        HNTower(A, C, B, N-1);
        HNTower(A, B, C, 1);
        HNTower(C, B, A, N-1);
    }
    

}

int main(){
    HNTower('A', 'B', 'C', 3);
    
}