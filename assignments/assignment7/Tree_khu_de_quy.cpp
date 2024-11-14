#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int info;
    Node *LP, *RP;
};

typedef Node* PNode;
typedef Node* BinaryTree;

Node* CreateNode(int data) {
    Node* newNode = new Node;
    newNode->info = data;
    newNode->LP = NULL;
    newNode->RP = NULL;
    return newNode;
}

void BuildTreeFromArray(BinaryTree &T, int a[], int size) {
    if (size == 0) return;

    PNode newNode = CreateNode(a[0]);
    T = newNode;

    // Use a queue to assist in level order construction of the tree
    queue<BinaryTree> Q;
    Q.push(T);

    int i = 1;
    while (i < size) {
        // Get the front node from the queue
        BinaryTree current = Q.front();
        Q.pop();

        // Add the left child if there are more elements in the array
        if (i < size) {
            current->LP = CreateNode(a[i]);
            Q.push(current->LP);
            i++;
        }

        // Add the right child if there are more elements in the array
        if (i < size) {
            current->RP = CreateNode(a[i]);
            Q.push(current->RP);
            i++;
        }
    }
}

// Function to print the tree in pre-order traversal
void PreOrderTraversal(BinaryTree T) {
    if (T == NULL) return;
    cout << T->info << " ";
    PreOrderTraversal(T->LP);
    PreOrderTraversal(T->RP);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    BinaryTree T = NULL;
    BuildTreeFromArray(T, arr, size);

    cout << "Pre-order Traversal of the Tree: ";
    PreOrderTraversal(T);
    cout << "\n";
    return 0;
}
