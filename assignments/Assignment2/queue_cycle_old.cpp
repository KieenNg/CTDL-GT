#include <iostream>
using namespace std;
#if 0

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
#endif

#define FIFO_SIZE 7
static int PutI;  // index to put new
static int GetI;  // index of oldest
static int Fifo[FIFO_SIZE];

void Fifo_Init(){
  PutI = GetI = 0;  // empty
}

void Fifo_Put(int data){
  if(((PutI+1)%FIFO_SIZE) == GetI) return; // fail if full
  Fifo[PutI] = data;         // save in Fifo
  PutI = (PutI+1)%FIFO_SIZE; // next place to put
}

int Fifo_Get(){
  if(GetI == PutI) return 0; // fail if empty
  char data = Fifo[GetI];      // retrieve data
  GetI = (GetI+1)%FIFO_SIZE; // next place to get
  return data;
}

int main() {
    Fifo_Init();

    Fifo_Put(1);
    Fifo_Put(2);
    Fifo_Put(3);
    Fifo_Put(4);
    Fifo_Put(5);
    Fifo_Put(6);
    Fifo_Put(7);

    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
    cout << Fifo_Get() << endl;
}