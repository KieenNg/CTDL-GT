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
    if(P == DL.H){ // P la vi tri dau tien => Them vao vi tri dau tien
        InsertBegin(DL,x);
    }
    else {
        newNode->nextR = P;
        newNode->nextL = P->nextL;
        P->nextL = newNode;
        newNode->nextL->nextR = newNode;
    }
}
//them 1 node vao truoc node P 
void InsertAfterP(DLink_list &DL, Node* P, int x){

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

}
