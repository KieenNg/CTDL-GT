#include <cstddef>
#include <iostream>
#include <cstring>
using namespace std;

struct detail{
    long mssv;
    char hoten[50];
    float cpa;
};

struct Node{
    detail element;
    Node* next;
};

typedef Node* Pnode;
typedef Node* List;

void InitList(List &L){
    L = NULL;    
    return;
};

int IsEmpty(List &L){
    return (L == NULL);
}

Pnode createStudentNode(long MSSV, char HOTEN[], float CPA){
    Pnode P = new Node;
    P->element.mssv = MSSV;
    strcpy(P->element.hoten, HOTEN);
    P->element.cpa = CPA;
    return P;
}

void createFirst(List &L, Pnode P){
    if(IsEmpty(L)){
        P->next = NULL;
        L = P;
    }
    else {
        P->next = L;
        L = P;
    }
}
//search student with MSSV 
Pnode SearchStudent(List &L, int MSSV){
    if(IsEmpty(L)){
        cout << "Danh sach rong, khong tim thay\n";
        return NULL;
    }
    else {
        Pnode P = L;
        while(P != NULL){
            if(P->element.mssv = MSSV) return P;
            else P = P->next;
        }
    }
    return NULL;

}
//bo sung node P vao truoc node MSSV
void insertBeforeMSSV(List &L, Pnode P, int MSSV){
    Pnode search_node = SearchStudent(L,MSSV);
    if(IsEmpty(L)){
        P->next = NULL;
        L = P;
        return;
    }
    else {
        Pnode temp = L;
        while (temp->next != search_node) {     
            temp = temp->next;
        }
        P->next = temp->next;
        temp->next = P;
    }
}
void insertAfterMSSV(List &L, Pnode P, int MSSV){
    Pnode search_node = SearchStudent(L, MSSV);
    if(IsEmpty(L)){
        P->next = NULL;
        L = P;
        return;
    }
    else {
        P->next = search_node->next;
        search_node->next = P;
    }
}
void deleteFirst(List &L){
    if(IsEmpty(L)){
        cout << "List is EMpty\n";
        return;
    }
    else {
        L = L->next;
        return;
    }
}
//xoa Node tro boi P 
void deteteP(List &L, Pnode P){ 
    if(IsEmpty(L)){
        cout << "List is Empty\n";
        return;
    }
    Pnode temp = L;
    while (temp->next != P) {
         temp->next = P->next;
    }

}
//xoa sinh vien khi biet MSSV
void deteleMSSV(List &L, int MSSV){ 
    if(IsEmpty(L)){
        cout << "List is Empty\n";
        return;
    }
    Pnode P = SearchStudent(L,MSSV);
    deteteP(L,P);
    return;
}

float cpaMax(List &L){
    if(IsEmpty(L)){
        cout << "List is Empty\n";
        return -1;
    }
    float max=0;
    Pnode temp = L;
    while (temp != NULL){
        if(temp->element.cpa > temp->next->element.cpa){
            max = temp->element.cpa;
        }
        temp = temp->next;
    }
    return max;
}

void HienThi(List &L){
    cout << " \nHien thi danh sach: \n";
    Pnode P = L;
    while (P != NULL)
    {
        cout << P->element.mssv << "\t";
        P = P -> next;
    }
    cout << "\n";
}
int main(){
    Pnode e1 = createStudentNode(20213977, "Nguyen Kien", 3.17);
    Pnode e2 = createStudentNode(20210428, "TQ Huy", 3.69);
    Pnode e3 = createStudentNode(20210396, "NM Hung", 3.69);
    Pnode e4 = createStudentNode(20211578, "VD Phuong", 3.69);
    List L;
    InitList(L);
    createFirst(L, e1);
    createFirst(L, e2);
    //insertBeforeMSSV(L, e3, 20213977);
    insertAfterMSSV(L, e4, 20210428); 
    HienThi(L);
    deleteFirst(L);
    HienThi(L);

}
