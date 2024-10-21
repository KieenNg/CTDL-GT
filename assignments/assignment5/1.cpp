#include <cstddef>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* nextL;
    Node* nextR;
};

typedef Node* Pnode;

struct DLink_list{
    Node* H;
    Node* T;
};

// tao danh sach
void InitList(DLink_list &DL){
    DL.H = DL.T = NULL;
    return;
}

//kiem tra danh sach rong
int IsEmpty(DLink_list &DL){
    return (DL.H == NULL && DL.T == NULL);
}

//them node vao dau danh sach 
void InsertBegin(DLink_list &DL, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(IsEmpty(DL)){
        DL.H = DL.T = newNode;
        return;
    }
    else {
        newNode->nextR = DL.H;
        DL.H->nextL = newNode;
        DL.H = newNode;
        return;
    }

}
//them node vao cuoi danh sach 
void InsertEnd(DLink_list &DL, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(IsEmpty(DL)){
        DL.H = DL.T = newNode;
        return;
    }
    else {
        newNode->nextL = DL.T;
        DL.T->nextR = newNode;
        DL.T = newNode;
        return;
    }
}

//them 1 node vao truoc node P 
void InsertBeforeP(DLink_list &DL, Node* P, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(IsEmpty(DL)){
        DL.H = DL.T = newNode;
    }
    if (P == NULL) {
        cout << "P khong hop le!\n";
        return;
    }
    if(P == DL.H){ // P la vi tri dau tien => InsertBegin
        InsertBegin(DL,x);
        return;
    }
    else {
        newNode->nextR = P;
        newNode->nextL = P->nextL;
        P->nextL = newNode;
        newNode->nextL->nextR = newNode;
        return;
    }
}
//them 1 node vao truoc node P 
void InsertAfterP(DLink_list &DL, Node* P, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(IsEmpty(DL)){
        DL.H = DL.T = new Node;
        return;
    }
    if(P == NULL){
        return;
    }
    if(P == DL.T){ // P la vi tri cuoi cung => InsertEnd
        InsertEnd(DL, x);
        return;
    }
}
// Tim node P co gia tri x
Node* SearchNode(DLink_list &DL, int x){
    if(IsEmpty(DL)){
        cout << "List is Empty\n";
        return NULL;
    }
    else { 
        Node* temp = DL.H;
        while (temp != DL.T) {
            if(temp->data == x) return temp;
            temp = temp->nextR;
        }
        if(DL.T->data == x) return DL.T;
        return NULL;
    }
    
}
// Them 1 node vao truoc node gia tri k 
void InsertBeforeK(DLink_list &DL, int k, int x){
    Node* temp = SearchNode(DL, k);
    InsertBeforeP(DL, temp, x);
    return;
}
//Them 1 node vao sau node gia tri k
void InsertAfterK(DLink_list &DL, int k, int x){
    Node* temp = SearchNode(DL, k);
    InsertAfterP(DL, temp, x);
}
// xoa node dau tien 
void DeleteBegin(DLink_list &DL){
    if(IsEmpty(DL)){
        cout << "List is Empty\n";
        return;
    }
    if (DL.H == DL.T) { //list co 1 node 
        delete DL.H;
        DL.H = DL.T = NULL;
    }
    else {
        Node* temp = DL.H;
        DL.H = temp->nextR;
        DL.H->nextL = NULL;
        delete temp;
        return;
    }
}
//xoa node cuoi cung 
void DeleteEnd(DLink_list &DL){ 
    if(IsEmpty(DL)){
        cout << "List is Empty\n";
        return;
    }
    if (DL.H == DL.T) { //list co 1 node 
        delete DL.H;
        DL.H = DL.T = NULL;
    }
    else {
        Node* temp = DL.T;
        DL.T = temp->nextL;
        DL.T->nextR = NULL;
        delete temp;
        return;
    }
}
//xoa node P
void DeleteP(DLink_list &DL, Node* P){
    if(IsEmpty(DL)){
        cout << "List is Empty\n";
        return;
    }
    if(P == NULL){
        return;
    }
    if(P == DL.H){
        DeleteBegin(DL);
        return;
    }
    if(P == DL.T){
        DeleteEnd(DL);
        return;
    }
    else {
        P->nextL->nextR = P->nextR;
        P->nextR->nextL = P->nextL;
        delete P;
        return;
    }
}
//hien thi cac phan tu trong danh sach 
void Display(DLink_list &DL){
    if(IsEmpty(DL)){
        cout << "List is Empty\n";
        return;
    }
    else {
        Node* temp = DL.H;
        cout << "Cac phan tu trong danh sach la:\n";
        while(temp != NULL){
            cout << temp->data << "\t";
            temp = temp->nextR;
        }
        cout << "\n";
    }
}

int main(){
    DLink_list DL;
    InitList(DL);
    Display(DL);
    InsertBegin(DL, 3);
    InsertBegin(DL, 4);
    Display(DL);
    InsertEnd(DL, 5);
    Display(DL);
    InsertAfterK(DL, 5, 6);
    Display(DL);
    InsertBeforeK(DL, 3, 7);
    Display(DL);
    DeleteBegin(DL);
    Display(DL);
    DeleteEnd(DL);
    Display(DL);
}
