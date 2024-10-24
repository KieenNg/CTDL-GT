#include<iostream>
using namespace std;

// tong so nguyen tu 1 den n
long Sum(int n){
    if(n == 1) return 1;
    else{
        return n + Sum(n-1);
    }
}

int so_nho_nhat(int arr[], int left, int right){
    if(left == right){
        return  arr[left];
    }
    int mid = (left + right)/2;
    int min_left = so_nho_nhat(arr,left,mid);
    int min_right = so_nho_nhat(arr,mid,right);
    

}

// tim uoc chung lon nhat 2 so nguyen duong
int UCLN(int a, int b){
    if(b == 0){
        return a;
    }
    else {
        return UCLN(b, a % b);
    }
}

int tong_cac_chu_so(int n){
    if(n < 10){
        return n;
    }
    else {
        return n % 10 + tong_cac_chu_so(n / 10);
    }
}
int main(){ 
    cout << UCLN(20, 5) << endl;
    cout << tong_cac_chu_so(99) << endl;
}