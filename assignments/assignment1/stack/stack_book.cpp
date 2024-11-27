#include <iostream>
using namespace std;

#define MAX 100


typedef struct 
{
    int id;
    string name;
    long price;
}Book;


typedef struct{
	Book book[MAX];
	unsigned int n;
}Stack;

void Initialize (Stack &s){
	s.n = 0; //stack dang rong
}

bool IsEmpty (Stack s){
	return (s.n == 0);
}

bool IsFull (Stack s){
	return (s.n == MAX - 1);
}
void Push(Stack &s, Book x){
	if(IsFull(s)){
		cout << "Stack is full, cannot add book ! \n";
		return;
	}
	s.book[s.n++] = x;
}

void AddBook(Stack &s){
	if(IsFull(s)){
		cout << "Stack is full, cannot add book\n";
		return;
	}
	Book newbook;
	cout << "Nhap id sach: ";
	cin >> newbook.id;
	cin.ignore();

	cout << "Nhap ten sach: ";
	getline(cin, newbook.name);

	cout << "Nhap gia tien: ";
	cin >> newbook.price;

	Push(s, newbook);
	cout << "Book is added\n";
}

int Pop(Stack &s){ // Bo 1 cuon sach cuoi cung
	if(IsEmpty(s)){
		return -1;
	}
	s.n--;
}

void AveragePrice(Stack s){
	float sum;
	for(int i = 0; i < s.n; i++){
		sum += (float) s.book[i].price;
	}
	int count = s.n;
	cout << "Gia tien trung binh cac cuon sach la: "<< sum/count << endl ;
	return;
}
void display(Stack s){
	if(IsEmpty(s)){
		cout << "Stack rong \n";
		return;
	}
	cout << "Cac sach hien co: \n";
	for(int i = 0; i < s.n; i++){
		cout << "ID sach: " << s.book[i].id << ". Ten sach: "<< s.book[i].name << ". Gia sach: " << s.book[i].price << "\n"; 
	}
}

int main(){
	Stack s; 
	Initialize(s);
	
	int amount;
	cout << " Nhap so luong sach muon them: ";
	cin >> amount;
	for(int i = 0; i < amount; i++){
		AddBook(s);
	}
	
	AveragePrice(s);

	display(s);
	return 0;
}