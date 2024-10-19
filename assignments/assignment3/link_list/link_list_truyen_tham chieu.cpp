#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};
typedef Node* Pnode;
typedef Node* LinkedList;

// khởi tạo danh sách
void InitList(LinkedList &H){
    H = NULL;
}

// kiểm tra danh sách rỗng
int IsEmpty(LinkedList &H){
    return (H == NULL);
}

//thêm phần tử vào đầu danh sách
void insertBegin(LinkedList &H, int x){
    Pnode Q = new Node;
    Q -> info = x;
    Q -> next = H;
    H = Q;
}

//bổ sung node vào cuối danh sách
void insertAfter(LinkedList &H, int x){
    Pnode Q = new Node;
    Q -> info = x;
    if (IsEmpty(H)){
        Q -> next = NULL;
        H = Q;
    }
    Pnode P = H;
    while (P -> next != NULL){
        Q -> next = NULL;
        P -> next = Q;
    }
}

// hàm tìm node P có giá trị bằng x
Pnode Search (LinkedList &H, int x){
    Pnode P = H;
    while (P != NULL){
        if(P -> info == x) return P;
        else P = P -> next;
    }
    return NULL;
}

//thêm 1 node mới vao sau node P
void insertAfterP(LinkedList &H, Pnode P, int x){
    Pnode Q = new Node;
    Q -> info = x;
    if(IsEmpty(H)){
        Q -> next = H;
        H -> next = Q;
    }
    else {
        if(P == NULL) return;
        else {
            Q -> next = P -> next;
            P -> next = Q;
        }
    }
}

// bổ sung x vào sau phần tử K
// => Gộp 2 hàm Search va insertAfterP
void InsertXAfterK(LinkedList &H, int K, int x){
    Pnode P = Search(H, K);
    insertAfterP(H, P, x);
}

//bổ sung x vào trước node K
void insertBeforeK(LinkedList &H, Pnode K, int x){
    Pnode Q = new Node;
    Q -> info = x;
    if(IsEmpty(H)){
        Q -> next = NULL;
        H = Q;
    }
    Pnode P = H;
    while (P -> next = K){
        Q->next = K;
        P->next = Q;
    }
} 
// bổ sung x vào sau phần tử K
// => Gộp 2 hàm Search va insertAfterP
void InsertXBeforeK(LinkedList &H, int K, int x){
    Pnode P = Search(H, K);
    insertBeforeK(H, P, x);
}

// đếm số phần tử trong danh sách
int Count(LinkedList &H){
    int count = 0;
    Pnode P = H;
    while (P != NULL){
        P = P -> next;
        count++;
    }
    cout << "So phan tu trong danh sach la: " << count << endl;
    return count;
}
// hàm tính trung bình
float Average(LinkedList &H){
    int Quantity = 0;
    int Sum;
    Pnode P = H;
    while (P != NULL){
        Sum += P -> info;
        Quantity ++;
        P = P -> next;
    }
    return (Sum / Quantity);
}
// in các phần tử trong danh sách ra màn hình
void HienThi(LinkedList &H){
    cout << " \nHien thi danh sach: \n";
    Pnode P = H;
    while (P != NULL)
    {
        cout << P -> info << "\t";
        P = P -> next;
    }
}
int main (){
    LinkedList H;
    InitList(H);
    insertBegin (H, 11);
    insertBegin (H, 21);
    insertBegin (H, 31);
    insertBegin (H, 51);
    HienThi(H);
    Pnode P = Search(H, 21);
    insertAfterP(H, P, 99);
    HienThi(H);
    InsertXAfterK(H,31, 34);
    HienThi(H);
    Count(H);
    
}
