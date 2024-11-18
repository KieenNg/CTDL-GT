#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *LP, *RP;
};
// Khoi tao 1 cay rong
void InitTree(Node* &root){
    root = NULL;
}
// Bo sung 1 phan tu
void InsertT(Node* &root, int x){
    Node* Q;
    if(root == NULL){
        Q = new Node;
        Q->key = x;
        Q->LP = Q->RP = NULL;
        root = Q;
    }
    else {
        if(x < root->key) InsertT(root->LP, x);
        else if(x > root->key) InsertT(root->RP, x);
        else return;
    }
}
// xoa node P
void  DelNode(Node* P) {	//Xóa nút P & sắp lại cây
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
//Cach 2:
void  DelNode2(Node* P) {	//Xóa nút P & sắp lại cây
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
		Q = P->RP;
		if (Q->LP == NULL) {
			P->key = Q->key;
			P->RP = Q->RP;
		}
		else {
			do {//Dùng R để lưu parent của Q
				R = Q;
				Q = Q->LP;
			} while (Q->LP != NULL);
			P->key = Q->key; //Lấy giá trị ở Q đưa lên
			R->LP = Q->RP;	//Chuyển con của Q lên vị trí Q
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
		else  DelNode2(Root);		//Xoá gốc của cây
	}
}
//Tim kien phan tu co gia tri x
Node* SearchNode(Node* root, int x){
    if(root == NULL){
        return NULL;
    }
    else {
        if (x == root->key) return root;
        else if(x < root->key) return SearchNode(root->LP, x);
        else if(x > root->key) return SearchNode(root->RP, x);
        else return NULL;
    }
}

void hienThi(Node* root){ //duyet theo thu tu truoc
    if(root == NULL)return;
    cout << root->key << "\t";
    hienThi(root->LP);
    hienThi(root->RP);
}
//Tong cac phan tu trong cay
int SumTree(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->key + SumTree(root->LP) + SumTree(root->RP);
    }
}
//Dem so phan tu
int CountNode(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + CountNode(root->LP) + CountNode(root->RP);
    }
}
int main(){
    Node* T;
    InitTree(T);
    int a[]= {34, 11, 56, 23, 48, 99, 5, 12, 4};
    for(int i = 0; i < sizeof(a)/4; i++){
        InsertT(T, a[i]);
    }
    hienThi(T);
    cout << endl;
    DeleteT(T, 11);
    hienThi(T);
    cout << endl;

    cout << SumTree(T) << endl;
    cout << CountNode(T) << endl;
}