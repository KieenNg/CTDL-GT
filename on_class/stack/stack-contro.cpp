#include<iostream>
using namespace std;

#define MAX 100
struct Stack{
    int arr[MAX];
    unsigned int n;
};

void initStack(Stack *s){
    s->n = 0; //stack dang co 1 phan tu, neu = -1 thi stack dang rong
}
bool IsEmpty(Stack s){
    return (s.n == 0);
}
