#include <iostream>
#include "Queue.h"
using namespace std;

struct QNode{
    int info;
    QNode* next;
};

struct Queue{
    QNode* F;
    QNode* R;
};
//khoi tao Queue
void InitQueue(Queue &Q){
    Q.F = Q.R = NULL;
}
//check Queue co Empty khong
int IsEmpty(Queue &Q){
    return (Q.F == NULL);
}
//EnQueue
void EnQueue(Queue &Q, QNode* newNode){
    if(IsEmpty(Q)){
        Q.F = Q.R = newNode;
        return;
    }
    else
    {
        Q.R->next = newNode;
        Q.R = newNode;
    }
    
}
//DeQueue
QNode* DeQueue(Queue &Q){
    if(IsEmpty(Q)){
        cout << "Queue is already empty!\n";
        return NULL;
    }
    QNode* ptr = Q.F;
    if(Q.F == Q.R){ // Queue co 1 phan tu
        return Q.F;
        delete Q.F;
        Q.F = Q.R = NULL;
    }
    else{
        return Q.F;
        Q.F = Q.F->next;
        delete ptr;
    }
}
// Lay gia tri phan tu Front
int Peek(Queue &Q){
    if(IsEmpty(Q)){
        cout << "Queue is empty\n";
        return -1;
    }
    return (Q.F->info);
}
// So luong phan tu trong Queue
int getSize(Queue &Q){
    if(IsEmpty(Q)){
        cout << "\n Queue rong\n";
        return -1;
    }
    int size = 0;
    QNode* ptr = Q.F;
    while(ptr != Q.R){
        size++;
        ptr = ptr->next;
    }
    size++;
    return size;
}


