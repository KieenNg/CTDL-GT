#include <iostream>
#include <string.h>
using namespace std;

void dao_cuoi_ky_tu(char *str, int start, int end){
    if(start >= end){
        return;
    }
    // hoan doi ky tu dau va cuoi
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    dao_cuoi_ky_tu(str, start + 1, end - 1);
}

int main(){
    char str[] = "Hello world!";
    dao_cuoi_ky_tu(str, 0, strlen(str) - 1);
    cout << str << endl;
}
