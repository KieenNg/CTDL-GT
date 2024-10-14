#include <iostream>
using namespace std;

#define MAX 10

typedef struct{
    int data[MAX];
    int front;
    int rear;
}CycleQueue;

void InitQueue(CycleQueue &q){
    q.front = q.rear = -1;
}

bool IsFull(CycleQueue &q){
    //return (q.rear == MAX - 1);
    return (q.rear + 1) % MAX == q.front;
}

bool IsEmpty(CycleQueue &q){
    return (q.front == -1);
}


void EnQueue(CycleQueue &q, int x){
    if(IsFull(q)){
        return;
    }
    if(IsEmpty(q)){
        q.front = 0;
        q.rear = 0;
    }
    else
    {
        q.rear = (q.rear + 1) % MAX;
    }
    q.data[q.rear] = x;
    
}

void DeQueue(CycleQueue &q){
    if(IsEmpty(q)){
        return;
    }
    if((q.front == q.rear)){
        q.front = -1;
        q.rear = -1;
    }
    else
    {
        q.front = (q.front + 1) % MAX;
    }
}

void Display(CycleQueue q){
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

    CycleQueue q;
    InitQueue(q);
    EnQueue(q,1);
    EnQueue(q,2);
    EnQueue(q,3);
    
    Display(q);

}