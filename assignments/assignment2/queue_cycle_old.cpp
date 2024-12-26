#include <iostream>
using namespace std;

#define MAX 3

typedef struct {
    int data[MAX];
    int front;
    int rear;
} queue_cycle;


void InitialQueue(queue_cycle &q){
    q.front = q.rear = -1;
    return;
}

bool IsEmpty(queue_cycle q){
    return (q.front == -1);
}

bool IsFull(queue_cycle q){
    //return (q.front == 0) && (q.rear == MAX - 1);
    if((q.front == 0) && (q.rear == MAX - 1)){
        return true;
    }
    if(q.front == (q.rear + 1) % MAX){
        return true;
    }
    else return false;
}

void EnQueue(queue_cycle &q, int x){
    if(IsFull(q)){
        cout <<"Queue is full! \n";
        return;
    }
    else{
        if(q.front == -1) q.front = 0;
        q.rear = (q.rear + 1) % MAX;
        q.data[q.rear] = x;
    }
}

int DeQueue(queue_cycle &q){
    int element;
    if (IsEmpty(q)){
        cout << "Queue is empty!\n";
        return -1;
    }
    else {
        element = q.front;
        if(q.front == q.rear){      //neu front bang rear thi reset queue
        q.front = -1;
        q.rear = -1;
        }
        else{
            q.front = (q.front + 1) % MAX;
        }
        cout << "Dequeue!\n";
        return element;
    }
    
}

void Display(queue_cycle q){
    if(IsEmpty(q)){
        cout << "Queue is empty!\n";
        return ;
    }
    else{
        cout << "Cac phan tu trong Queue:\n";
        for(int i = q.front; i == q.rear; i=(i+1)%MAX){
            cout << "i = "<< i << "\t";
        }
        for(int i = q.front; i != q.rear; i=(i+1)%MAX){
            cout <<q.data[i] << " ";
        }
        cout << "\nfront =" << q.front << endl;
            cout << "rear =" << q.rear << endl;
    }
    cout << endl;
}

int main(){
    queue_cycle q;
    InitialQueue(q);
    EnQueue(q,1);
    EnQueue(q,2);
    EnQueue(q,3);
    Display(q);
    EnQueue(q,4);
    Display(q);
    DeQueue(q);
    EnQueue(q,5);
    //EnQueue(q,6);
    
    Display(q);
}
