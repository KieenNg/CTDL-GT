#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};
typedef Node* Pnode;

void initStack(Pnode &H){
    H = NULL;
}
int IsEmpty(Pnode &H){
    return H == NULL;
}
void Push(Pnode &H, int x){
    Pnode newNode = new Node;
    newNode->info = x;
    newNode->next = H;
    H = newNode;
}
int Pop(Pnode &H){
    int value = 0;
    if(H == NULL) { 
        cout << "Danh sach rong" << endl;
        return -1;
    }
    else{
        Pnode ptr = H;
        value = ptr->info;
        H = H->next;
        delete ptr;
        return value;
    }
}
int Top(Pnode &H){
    return (H->info);
}
void Display(Pnode &H){
    Pnode temp = H;
    while(temp != NULL){
        cout << temp->info << "\t";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){
    Pnode H;
    initStack(H);
    Push(H, 1);
    Push(H, 2);
    Push(H, 3);
    Push(H, 4);
    Display(H);
    Pop(H);
    Display(H);
    Pop(H);
    Display(H);
    return 0;
}
