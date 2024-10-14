#include <iostream>
using namespace std;

#define MAX 100

typedef struct{
    int data[MAX];
    int front;
    int rear;
} Queue;

void InitQueue(Queue &q){
    q.front = q.rear = -1;
}

bool IsEmpty(Queue q){
    return (q.front == -1) || (q.front > q.rear);
}

bool IsFull(Queue q){
    return (q.rear == MAX - 1);
}

void EnQueue(Queue &q, int x){
    if(IsFull(q)){
        cout << "Queue is full \n";
        return;
    }
    if(IsEmpty(q)){
        q.front = 0;
        q.rear = 0;
    }
    else{
        q.rear++;
    }
    q.data[q.rear] = x;
}

int DeQueue(Queue &q){
    if(IsEmpty(q)){
        cout << "Queue is already empty !" << endl;
        return -1;
    }
    int data = q.data[q.front++];
    return data;
}

void Display(Queue q){
    if(IsEmpty(q)){
        cout << "Queue is empty!\n";
        return ;
    }
    else{
        cout << "Cac phan tu trong Queue:\n";
        for(int i = q.front; i <= q.rear; i++){
            cout << q.data[i] << " ";
        }
    }
    cout << endl;
}


int main(){

    Queue q;
    InitQueue(q);
    EnQueue(q,1);
    EnQueue(q,2);
    EnQueue(q,3);
    
    Display(q);

}