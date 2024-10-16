#include <iostream>
using namespace std;

struct Node{
    int info;
    Node* next;
};
typedef Node* Pnode;

struct Queue{
    Node* F;
    Node* R;
};

void InitQueue(Queue &Q){
    Q.F = Q.R = NULL;
}

int IsEmpty(Queue &Q){
    return (Q.F == NULL);
}

void EnQueue(Queue &Q, int x){
    Node* newNode = new Node;
    newNode->info = x;
    if(IsEmpty(Q)){ //neu queue rong
        Q.F = Q.R = newNode;
        return;
    }
    else //neu queue khong rong
    {
        Q.R->next = newNode;
        Q.R = newNode;
    }
    
}

int DeQueue(Queue &Q){
    if(IsEmpty(Q)){
        cout << "Queue is already empty!\n";
        return -1;
    }
    Node* ptr = Q.F;
    int value = ptr->info;
    if(Q.F == Q.R){ // Queue co 1 phan tu
        delete Q.F;
        Q.F = Q.R = NULL;
    }
    else{
        Q.F = Q.F->next;
        delete ptr;
    }
    return value;
}

int Peek(Queue &Q){
    if(IsEmpty(Q)){
        cout << "Queue is empty\n";
        return -1;
    }
    return (Q.F->info);
}
int getSize(Queue &Q){
    if(IsEmpty(Q)){
        cout << "\n Queue rong\n";
        return -1;
    }
    int size = 0;
    Node* ptr = Q.F;
    while(ptr != Q.R){
        size++;
        ptr = ptr->next;
    }
    size++;
    return size;
}
void Display(Queue &Q){
    Node* ptr = Q.F;
    cout << "Queue:\t";
    while(ptr != Q.R){
        cout << ptr->info << "\t";
        ptr = ptr->next;
    }
    cout << Q.R->info << endl; // hien thi not phan tu cuoi cung, vi while khong duyet het
}

int main(){
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,11);
    EnQueue(Q,22);
    EnQueue(Q,33);
    Display(Q);
    DeQueue(Q);
    Display(Q);
    EnQueue(Q,44);
    EnQueue(Q,55);
    Display(Q);
    
    cout << "So phan tu tu la: " << getSize(Q);
}