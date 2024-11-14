#include "iostream"
#include <functional>
using namespace std;

struct Node{
    int info;
    Node *LP, *RP;
};

typedef Node* PNode;
typedef Node* BinaryTree;

//khoi tao Tree
void initTree(BinaryTree &T){
    T = NULL;
}
//Tao Node 
Node* CreateNode(int data){
    Node* newNode = new Node;
    newNode->info = data;
    newNode->LP = NULL;
    newNode->RP = NULL;
    return newNode;
}

Node* insertTree(int a[], int i, int n){
    Node* root = NULL;
    if(i < n){
        Node* newNode = CreateNode(a[i]);
        root = newNode;
        root->LP = insertTree(a, 2*i + 1, n);
        root->RP = insertTree(a, 2*i + 2, n);
    }
    return root;
}

//duyet cay theo thu tu truoc
void preOderTraversal(BinaryTree &T){
    if(T == NULL) return;
    cout << T->info << "\t";
    preOderTraversal(T->LP);
    preOderTraversal(T->RP);
}

//duyet cay theo thu tu giua
void inOderTraversal(BinaryTree &T){
    if(T == NULL) return;
    inOderTraversal(T->LP);
    cout << T->info << "\t";
    inOderTraversal(T->RP);
}

//duyet cay theo thu tu sau
void postOrderTraversal(BinaryTree &T){
    if(T == NULL) return;
    postOrderTraversal(T->LP);
    postOrderTraversal(T->RP);
    cout << T->info << "\t";
}

//Chieu cao cua cay 
int heightOfTree(BinaryTree &T){
    if(T == NULL) return 0;
    int left_height = heightOfTree(T->LP);
    int right_height = heightOfTree(T->RP);
    
    if(left_height >= right_height) return 1 + left_height;
    else return 1 + right_height;
}

//tong cac phan tu trong cay 
int sumOfTree(BinaryTree &T){
    if(T == NULL) return 0;
    return T->info + sumOfTree(T->LP) + sumOfTree(T->RP);
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryTree T = insertTree(a, 0, 10); 
    cout << "Duyet cay theo thu tu truoc:\n";
    preOderTraversal(T);
    cout << "\n";
    cout << "Duyet cay theo thu tu giua:\n";
    inOderTraversal(T);
    cout << "\nDuyet cay theo thu tu sau:\n";
    postOrderTraversal(T);
    cout << "\n";

    cout << "Tong cac phan tu trong cay: " << sumOfTree(T) << endl;
    cout << "Chieu cao cua cay: " << heightOfTree(T) << endl;
}

