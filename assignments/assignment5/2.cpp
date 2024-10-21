#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
//khoi tao node last
void createList(Node* &last){
    last = NULL;
    return;
}
//kiem tra list empty
int IsEmpty(Node* &last){
    return last == NULL;
}
//them 1 node vao dau
void InsertBegin(Node* &last, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(IsEmpty(last)){
        last = newNode;
        last->next = last;
        return;
    }
    else {
        newNode->next = last->next;
        last->next = newNode;
        return;
    }
}
//them 1 node vao sau node P
void insertAfterP(Node* &last, Node* P, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(IsEmpty(last)){
        cout << "List is Empty\n";
        return;
    }
    if(P == NULL){
        return;
    }
    if(P == last){ //chi co last 
        InsertBegin(last, x);
    }
    else {
        newNode->next = P->next;
        P->next = newNode;
        return;
    }
}
//them 1 node vao truoc node P
void insertBeforeP(Node* &last, Node* P, int x){
    Node* newNode = new Node;
    newNode->data = x;
    if(IsEmpty(last)){
        cout << "List is Empty\n";
        return;
    }
    if(P == NULL){
        return;
    }
    if(P == last){ //chi co last 
        Node* temp = last->next;
        while (temp->next != P){
            temp = temp->next;
        }
        newNode->next = P;
        temp->next = newNode;
        return;
        
    }
    else {
        Node* temp = last->next;
        while (temp->next != P){
            temp = temp->next;
        }
        newNode->next = P;
        temp->next = newNode;
        return;
    }
}
//tim node P gia tri k 
Node* SearchNode(Node* &last, int k){
    if(IsEmpty(last)){
        return NULL;
    }
    else {
        Node* temp = last->next;
        while (temp != last) {
            if(temp->data == k) return temp;
            temp = temp ->next;
        }
        if(last->data == k) return last;
        return NULL;
    }
}
// them 1 node vao sau node gia tri k 
void insertAfterK(Node* &last, int k, int x){
    Node* temp = SearchNode(last, k);
    insertAfterP(last, temp, x);
}
//them 1 node vao truoc node gia tri k 
void insertBeforeK(Node* &last, int k, int x){
    Node* temp = SearchNode(last, k);
    insertBeforeP(last, temp, x);
}
//xoa node dau tien
void deleteBegin(Node* &last){
    if(IsEmpty(last)){
        cout << "List is Empty\n";
        return;
    }
    if(last == NULL){
        return;
    }
    if(last == last->next){ // chi co 1 phan tu 
        delete last;
        last = NULL;
        return;
    }
    else {
        Node* temp = last->next;
        last->next = temp->next;
        delete temp;
        return;
    }
}
//xoa node P
void deleteP(Node* &last, Node* P){
    if(IsEmpty(last)){
        cout << "List is Empty\n";
        return;
    }
    if(P == NULL){
        return;
    }
    if(P == last){
        Node* temp = last->next;
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        last = temp;
        delete P;
        return;
    }
    else{
        Node* temp = last->next;
        while (temp->next != P) {
            temp = temp->next;
        }
        temp->next = P->next;
        delete P;
        return;
    }
    
}
//xoa node P gia tri K
void deleteK(Node* &last, int k){
    Node* temp = SearchNode(last, k);
    deleteP(last,temp);
}
// hien thi list 
void Display(Node* &last){
    if(IsEmpty(last)){
        cout << "List is Empty\n";
        return;
    }
    else {
        Node* temp = last->next;
        while (temp != last) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << last->data << endl;
        return;
    }
}

int main(){
    Node* last;
    createList(last);
    InsertBegin(last, 2);
    Display(last);
    InsertBegin(last, 3);
    Display(last);
    insertAfterK(last, 3, 5);
    Display(last);
    insertBeforeK(last, 2, 6);
    Display(last);
    insertBeforeK(last, 2, 7);
    Display(last);
    deleteBegin(last);
    Display(last);
    deleteK(last, 7);
    Display(last);
}
