#include <iostream>
using namespace std;

#define MAX 100

struct Stack{
	int arr[MAX];
	unsigned int n;
};

void Initialize (Stack &s){
	s.n = 0; //stack dang rong
}

bool IsEmpty (Stack s){
	return (s.n == 0);
}

bool IsFull (Stack s){
	return (s.n == MAX - 1);
}
void Push(Stack &s, int x){
	s.arr[s.n++] = x;
}

int Pop(Stack &s){
	if(IsEmpty(s)){
		return -1;
	}
	return s.arr[s.n--];
}

void display(Stack s){
	if(IsEmpty(s)){
		cout << "Stack rong \n";
		return;
	}
	cout << "Cac phan tu trong danh sach: ";
	for(int i = 0; i < s.n; i++){
		cout << s.arr[i] << " ";
	}
}

int main(){
	Stack s; 
	Initialize(s);
	
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	
	display(s);
	return 0;
}