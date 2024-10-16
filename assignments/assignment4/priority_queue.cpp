#include <iostream>
using namespace std;

struct detail{
    int data;
    int priority;
};

struct Node{
    detail elements;
    Node* next;
};

typedef Node* Pnode;
typedef Node* PriorityQueue;

void InitQueue(PriorityQueue &Q){
    Q = NULL;
}

int IsEmpty(PriorityQueue &Q){
    return (Q == NULL);
}


void EnQueue(PriorityQueue &Q, detail new_element){
    Pnode P = new Node;
    P->elements = new_element;
    if(IsEmpty(Q)){
        P->next = NULL;
        Q = P;
        return;
    }
    if(new_element.priority > Q->elements.priority){
        P->next = Q;
        Q = P;
        return;
    }
    Pnode tmp = Q;
    while (tmp->next != NULL && tmp->next->elements.priority >= new_element.priority){
        tmp = tmp->next;
    }
    P->next = tmp->next;
    tmp->next = P;
}

int DeQueue(PriorityQueue &Q){
    if(IsEmpty(Q)){
        cout <<" Queue is already empty\n";
        return -1;
    }
    else {
        int value = 0;
        value = Q->elements.data; 
        Q = Q->next;
        return value;
    }
}


int Count(PriorityQueue &Q){
    int cnt = 0;
   if(IsEmpty(Q)){
        cout << "Queue is empty!\n";
        return -1;
    }
   else{
      
       Pnode tmp = Q;
        while(tmp != NULL){
            cnt++;
            tmp = tmp->next;
        }
   }
   return cnt;
}

void Display(PriorityQueue &Q){
    if(IsEmpty(Q)){
        cout << "Queue is empty!\n";
        return;
    }
    Pnode tmp = Q;
    cout << "Cac phan tu trong danh sach:\n";
    while(tmp != NULL){
        cout << tmp->elements.data << "\t";
        tmp = tmp->next;
    }
    cout << "\n";
    return;
}

int main(){
    PriorityQueue Q;
    detail e1 = {11,4};
    detail e2 = {22,5};
    detail e3 = {33,3};
    detail e4 = {44,6};
    detail e5 = {99,10};
    InitQueue(Q);
    EnQueue(Q,e1); 
    EnQueue(Q,e2); 
    EnQueue(Q,e3); 
    EnQueue(Q,e4); 
    EnQueue(Q,e5); 
    Display(Q);
    cout << "Queue dang co: " << Count(Q) << " phan tu\n";
    DeQueue(Q);
    Display(Q);
    cout << "Queue dang co: " << Count(Q) << " phan tu\n";
}
