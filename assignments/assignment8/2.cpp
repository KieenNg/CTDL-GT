#include<iostream>
#include<string>
using namespace std;

struct Node{
    string key;
    Node *LP, *RP;
};
//Khoi tao Node
void InitTree(Node* &root){
    root = NULL;
}
//Them 1 Node
void InsertT(Node* &root, const string &x){
    Node* Q;
    if(root == NULL){
        Q = new Node;
        Q->key = x;
        Q->LP = Q->RP = NULL;
        root = Q;
    }
    else {
        if(x.size() < root->key.size()) InsertT(root->LP, x);
        else if(x.size() > root->key.size()) InsertT(root->RP, x);
        else return;
    }
}
//Tim kiem Node
Node* SearchNode(Node* root, const string &x){
    if(root == NULL || x == root->key){
        return root;
    }
    else if(x.size() < root->key.size()) return SearchNode(root->LP, x);
    else return SearchNode(root->RP, x);
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

void  DeleteT(Node*& root, const string &x) {
    if(root == NULL) return;
    else {
		if (x.size() < root->key.size())  DeleteT(root->LP, x);
		else  if (x.size() > root->key.size())  DeleteT(root->RP, x);
		else  DelNode(root);		//Xoá gốc của cây
    }
	
}

// Hiển thị các phần tử trong cây theo thứ tự trước (NLR)
void hienThi(Node* root) {
    if (root == NULL) return;
    cout << root->key << "\t";
    hienThi(root->LP);
    hienThi(root->RP);
}

int main(){
    Node* T;
    InitTree(T);

    InsertT(T, "apple");
    InsertT(T, "banana");
    InsertT(T, "cherry");
    InsertT(T, "date");
    InsertT(T, "fig");
    InsertT(T, "grape");

    hienThi(T);
    cout << endl;

    // string deleteKey = "banana";
    // DeleteT(T, deleteKey);
    // hienThi(T);
    // cout << endl;
}