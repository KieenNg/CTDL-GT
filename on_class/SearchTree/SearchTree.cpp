#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *LP, *RP;
};
typedef Node* PNode;

//khoi tao Tree
void initTree(Node* &root){ 
    root = NULL;
}

//them 1 Node vao Tree
//cach 1: chung tham chieu
void insertT(Node* &root, int x){
    PNode Q;
    if(root == NULL){
        Q = new Node;
        Q->key = x;
        Q->LP = Q->RP = NULL;
        root = Q;
    }
    else {
        if(x < root->key) insertT(root->LP, x);
        else if(x > root->key) insertT(root->RP, x);
        else return;
    }
}
//Cach 2: dung con tro cap 2
void insertT2(Node** root, int x){
    Node* Q;
    if(*root == NULL){
        Q = new Node;
        Q->key = x;
        Q->LP = Q->RP = NULL;
        *root = Q;
    }
    else {
        if(x < (*root)->key) insertT((*root)->LP, x);
        else if(x > (*root)->key) insertT((*root)->RP, x);
        else return;
    }
}
//Cach 3:
Node* insertT3(Node* root, int x){
    PNode Q;
    if(root == NULL){
        Q = new Node;
        Q->key = x;
        Q->LP = Q->RP = NULL;
        root = Q;
    }
    else {
        if(x < root->key) root->LP = insertT3(root->LP, x);
        else if(x > root->key) root->RP = insertT3(root->RP, x);
    }
    return root;
}


void hienThi(Node* root){ //duyet theo thu tu truoc
    if(root == NULL)return;
    cout << root->key << "\t";
    hienThi(root->LP);
    hienThi(root->RP);
}
// xoa node P
void  DelNode(Node*& P) {	//Xóa nút P & sắp lại cây
	Node* Q, *R;
	if (P->LP == NULL) {	//Xóa nút chỉ có cây con phải 							hoặc nút lá
		Q = P;
		P = P->RP;
	}
	else if (P->RP == NULL) 	//Xóa nút chỉ có cây con trái
	{
		Q = P;
		P = P->LP;
	}
	else { //Xóa nút có 2 cây con
		Q = P->LP;
		if (Q->RP == NULL) {
			P->key = Q->key;
			P->LP = Q->LP;
		}
		else {
			do {//Dùng R để lưu parent của Q
				R = Q;
				Q = Q->RP;
			} while (Q->RP != NULL);
			P->key = Q->key; //Lấy giá trị ở Q đưa lên
			R->RP = Q->LP;	//Chuyển con của Q lên vị trí Q
		}
	}
    // nhanh else co 2 cach
	delete  Q;	//Xoá Q
}
 
// xoa Node co gia tri x
void  DeleteT(Node*& Root, int  x) {
	if (Root != NULL) {
		if (x < Root->key)  DeleteT(Root->LP, x);
		else  if (x > Root->key)  DeleteT(Root->RP, x);
		else  DelNode(Root);		//Xoá gốc của cây
	}
}
int main(){
    Node* T;
    initTree(T);
    int a[]= {34, 11, 56, 23, 48, 99, 5, 12, 4};
    for(int i = 0; i < sizeof(a)/4; i++){
        insertT(T, a[i]);
    }
    hienThi(T);
    cout << endl;
    //Cach insert 2
    Node* T2;
    for(int i = 0; i < sizeof(a)/4; i++){
        insertT2(&T2, a[i]);
    }
    hienThi(T2);
}

