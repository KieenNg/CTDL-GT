#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* nextR;
	Node* nextL;
};
typedef Node* Pnode;
typedef Node* List;

void InitList(List H){
	H.nextR = H.nextL = NULL;
}
void insertBegin(List &H, int x){

	else{
		newNode->nextR = p;
		newNode->nextL = P->nextL;
		P->nextL = newNode;
		newNode -> nextL-> nextR = newNode;
	}
}

Node* searchNode(List &DL, int x){
	Node* ptr = DL.H;
	while(ptr != NULL){
		if(ptr->data ==  x){
			return ptr;
		}
		else return NULL;
	}
}
void deleteBegin(List &DL){
	if(IsEmpty(DL)){
		cout << "Danh sach rong\n";
		return;
	}
	if(DL.H == DL.T){ //danh sach co 1 phan tu
		Node* ptr = DL.H;
		detele ptr;
		DL.H = DL.T = NULL;
	}
	else { //tong quat
		Node* ptr = DL.H;
		DL.H = ptr -> nextR;
		DL.H->nexL = NULL;
		detele ptr;
	}
}

void deleteEnd(List &DL){
	if(IsEmpty(DL)){
		return;
	}
	if(DL.H == DL.T){
		delete HL.H;
		DL.H = DL.T = NULL;
	}
	else {
		Node* ptr = DL.T
		DL.T = DL.T->nextL;
		DL.T->nextR = NULL;
		delete ptr
	}
}

void deleteNode(List &DL, Pnode P){
	if(IsEmpty(DL)){
		cout << "Danh sach rong\n";
		return;
	}
	if(P == NULL){
		cout << "P khong hop le";
		return;
	}
	if(P == DL.H){ // neu P la phan tu dau
		deleteBegin(DL);
		return;
	}
	if(P = DL.T){
		deleteEnd(DL);
		return;
	}
	else{// tong quat
		P->nextL->nextR = P->nextR;
		P->nextR->nextL = P->nextL;
		detele P;
	}

}

int main(){
	insertBegin(DL,11);
	insertBegin(DL,22);
	insertBegin(DL,33);
	hienThi(DL);
	Node* temp = searchNode(DL, 44);
	insertBefore(DL,tmp, 66);
	hienThi(DL);
	deleteBegin(DL);
	hienThi(DL);

}
