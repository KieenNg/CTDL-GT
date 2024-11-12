#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *LP, *RP;
};
typedef Node* PNode;
typedef PNode BinaryTree;

// Ham tao Node
//Cach 1
Node* createNode(int data){
    Node* newNode = new Node;
    
}
//Cach 2
void createNode1(Node*& newNode, int data){
    newNode = new Node;
    newNode->info = data;
    newNode->LP = NULL;
    newNode->RP = NULL;
}

Node* insertTree1(int a[], int i,int n){ // i la chi so phan tu mang duoc insert
    Node* root = NULL;
    if(i < n){
    Node* newNode = createNode1(a[i]);
    root = newNode;
    root->LP = insertTree1(a, 2*i + 1, n);
    root->RP = insertTree1(a, 2*i + 2, n);
    }
    return root;
}

//duyet cay theo thu tu truoc
void preOderTraveral(BinaryTree T){
    if(T == NULL){
        cout << "Cay rong" << endl;
    }
    else{
        cout << T->info << "\t";
        preOderTraveral(T->LP);
        preOderTraveral(T->RP);
    }
}

//Khu de quy


int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

}