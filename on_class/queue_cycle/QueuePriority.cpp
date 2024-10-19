#include <iostream>
using namespace std;

#define MAX 10

struct Element
{
    int data;
    int priority;
};


typedef struct QueuePriority
{
    Element data[MAX];
    int size;
};

int initialize(QueuePriority* q){
    return (q->size == MAX - 1);
}

int IsEmpty(QueuePriority* q){
    return q->size ==0;
}

void EnQueue(QueuePriority* q, int e){
    if(IsFull(q)){

    }
    if(IsEmpty(q)){
        q->data[0] = e;
    }
    else {
        int i
        for(i = q->size - 1; i>= 0; i--){
            if(e.priority > q->data[i]){
                q->data[i+1] = q->data[i];
            }
        }
        q->data[i] = e;

        q->size++;
    }
    
}

void Show(QueuePriority* q){
    for(int i = 0; i < q->size; i++){
        cout << q->data[i].
    }
}

int main(){
    Element e1 = {11,4};
    Element e2 = {12,3};
    Element e3 = {13,2};
    Element e4 = {16,1};
    QueuePriority* q;
    EnQueue(q, e1);
    EnQueue(q, e2);
    EnQueue(q, e3);
    EnQueue(q, e4);
    
}