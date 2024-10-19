#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertBegin(Node* &last, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(last == NULL){
        last = newNode;
        last->next = last; //last->next = newNode;
    }
    else {
        newNode->next = last->next;
        last->next = newNode;
    }
}
void insertAfterP(Node* &last,Pnode P, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(last == NULL){
        last = newNode;
        last ->next = newNode;
        return; //co the thoat luon
    }
    if(P == NULL){
        return;
    }
    if(P == last){
        P->next = newNode;
        newNode->next = last->next;
        last = newNode;
    }
    else{
        newNode->next = P->next;
        P->next = newNode;
    }
}

Node* searchNode(Node* last, int x){
    Node* ptr = last->next; // phan tu dau la last->next
    while(ptr != last){
        if(ptr->data == x){
            return ptr;
        }
        ptr = ptr->next;
    }
    if(last->data == x){
        return last;
    }
    return NULL;
}

void hienThi(Node* last){
    if(last == NULL){
        cout << "Danh sach rong\n";
    }
    else{
        Node* ptr = last->next;
        while(ptr != last){
            cout << ptr.data ;
            ptr = ptr->next;
        }
        //in ra cai cuoi cung vi vong while ko duyet phan tu cuoi
        cout << last->data;
    }
}

void deleteBegin(Node* &last){
    if(last == NULL){
        return;
    }
    if(last == last-> next){ //co 1 phan tu
        delete last;
        last = NULL;
    }
    else{
        Node* ptr = last->next;
        last = ptr->next;
        delete ptr;

    }
}

void deleteNodeP(Node* last, Node* P){
    if(last == NULL){
        return;
    }
    if(P == NULL){
        return;
    }
    if(P == last && last == last->next){
        delete P;
        last = NULL;
    }
    else{
        Node* ptr = last->next;
        while (ptr->next != P){
            ptr = ptr->next;
            ptr->next = P->next;
            delete P;
        }
    }
    if(P == last){
        Node* ptr = last->next;
        while(ptr->next != P){
            ptr = ptr-> next;
        }
        ptr->next = last->next;
        delete P;
        last = ptr;
    }
}

int main(){
    Node* last = NULL;
    insertBegin(last, 11);
    insertBegin(last, 22);
    insertBegin(last, 33);
    insertBegin(last, 44);

    hienThi(last);

    //bo sung 55 vao sau 33
    Node* tmp - searchNode(last, 33);
    insertAfterP(last, tmp, 55);
    hienThi(last);

}