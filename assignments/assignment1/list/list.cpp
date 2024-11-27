#include <iostream>
using namespace std;

#define MAX 100

typedef struct{
    float data[MAX];
    unsigned int top;
}List;

void InitList(List &list){
    list.top = 0;
}

bool IsEmpty(List list){
    return (list.top == 0);
}

bool IsFull(List list){
    return (list.top == MAX - 1);
}

//////////// Them vao dau danh sach /////////////////
void AddFront(List &list, float x){
    if(IsEmpty(list)){
        list.data[0] = x;
    }
    else {
        list.top++;
        for(int i = list.top - 1; i >= 0; i--){
            list.data[i+1] = list.data[i];
        }
        list.data[0] = x;
        cout << "Da them "<< x <<" vao dau danh sach\n";
    }
}

////////////// Them vao cuoi danh sanh ///////////////////
void AddRear(List &list, float x){
    if(IsFull(list)){
        cout << "List is full!\n";
        return;
    }
    else {
        list.data[list.top++] = x;
        cout << "Da them "<< x <<" vao cuoi danh sach\n";
    }
}

///////////////// Them vao vi tri bat ky /////////////////
void AddPosition(List &list, int pos, float x){
    if(IsFull(list)){
        cout << "List is full ! \n";
        return;
    }
    else if(IsEmpty(list)){
        list.data[0] = x;
    }
    else {
        list.top++;
        for(int i = list.top - 1; i >= pos; i--){
            list.data[i+1] = list.data[i];
        }
        list.data[pos] = x;
        cout << "Da them " << x << " vao vi tri thu " << pos << "\n";
    }
}

////////////////Xoa phan tu vi tri bat ky/////////////
void DeletePosition(List &list, int pos){
    if(IsEmpty(list)){
        cout << "List is already empty! \n";
        return;
    }
    else {
        for(int i = pos; i < list.top; i++){
            list.data[i] = list.data[i+1];
        }
        list.top--;
        cout << "Da xoa vi tri thu " << pos << "\n";
    }
}

//////////////Hien thi ra man hinh///////////////////
void display(List list){
    if(IsEmpty(list)){
        cout << "List is empty! \n";
        return;
    }
    else{
        cout << "Cac phan tu trong danh sach la: "; 
        for(int i = 0; i < list.top ; i++){
            cout << list.data[i] << " ";
        }
    }
    cout << "\n";
}

int main(){
    List list;
    InitList(list);
    AddRear(list, 1.5);
    AddRear(list, 2.5);
    AddFront(list, 0.5);
    display(list);

    AddPosition(list, 2, 3.5);
    display(list);
    
    DeletePosition(list, 1);
    display(list);
}