#include <iostream>
using namespace std;

#define REAL_MAX 8 
#define MAX (REAL_MAX + 1) 

struct queue_cycle{
    int data[MAX];
    int front;
    int rear;
};
void InitQueue(queue_cycle &q){
    q.front = q.rear = 0;
}

bool IsFull(queue_cycle &q){
    return (q.rear + 1) % MAX == q.front;
}
bool IsEmpty(queue_cycle &q){
    return (q.front == q.rear);
}
void EnQueue(queue_cycle &q, int x){
    if(IsFull(q)){
        return;
    }
    q.data[q.rear] = x;
    q.rear = (q.rear + 1) % MAX;
}
int DeQueue(queue_cycle &q){
    if(IsEmpty){
        return 0;
    }
    int element = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    return element;   
}
void Display(queue_cycle q){
    for (int i = q.front; i != q.rear; i = (i + 1) % MAX){
        cout <<q.data[i] << "\t" << endl;
    }
}

int main(){
    queue_cycle q;
    InitQueue(q);
    EnQueue(q,1);
    EnQueue(q,2);
    EnQueue(q,3);
    EnQueue(q,4);
    EnQueue(q,5);
    EnQueue(q,6);
    EnQueue(q,7);
    EnQueue(q,8);
    DeQueue(q);
    DeQueue(q);
    DeQueue(q);

    Display(q);
}


