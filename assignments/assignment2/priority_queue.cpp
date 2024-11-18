#include <iostream>
using namespace std;

#define MAX 10


struct detail{
    int data;
    int priority;
};

// Define the structure PriorityQueue in C++ (no typedef needed)
struct priority_queue {
    detail elements[MAX];  // Use 'elements' as the array of Element objects
    int size;
};

// Initialize the priority queue
void initQueue(priority_queue &q) {
    q.size = 0;
}

bool IsFull(priority_queue q){
    return (q.size == MAX-1);
}

bool IsEmpty(priority_queue q){
    return (q.size == 0);
}

void EnQueue(priority_queue &q, detail new_element){
    if(IsFull(q)){
        return;
    }
    if(IsEmpty(q)){
        q.elements[0] = new_element;
        q.size++;
        return;
    }
    q.size++;
    for(int i = q.size - 1; i >= 0; i--){
        if(new_element.priority > q.elements[i].priority){
            q.elements[i+1] = q.elements[i];
        }
        q.elements[i] = new_element;
    }
}
void DeQueue(priority_queue &q){
    if(IsEmpty(q)){
        return;
    }
    for(int i = 0; i < q.size; i++){
        q.elements[i] = q.elements[i+1];
    }
    q.size --;
}

void Display(priority_queue q){
    for (int i = 0; i < q.size; i++){
        cout << q.elements[i].data << " ";
    }
}
int main(){
    detail e1 = {11,4};
    detail e2 = {19,1};
    detail e3 = {13,3};
    detail e4 = {14,5};
    priority_queue q;
    initQueue(q);
    EnQueue(q, e1);
    EnQueue(q, e2);
    EnQueue(q, e3);
    EnQueue(q, e4);
    Display(q);
}