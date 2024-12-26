#include<iostream>
using namespace std;

typedef struct SV
{
	unsigned int mssv;
	string name;
	double cpa;
	int visited;
} sv;

typedef struct Queue
{
	int data[7];
	int F, R;
} queue;
void init(queue& Q)
{
	Q.F=Q.R=-1;
}
int isEmpty(queue& Q)
{
	return Q.F==-1;
}
void enQueue(queue& Q, int k)
{
	if(isEmpty(Q))
	{
		Q.F=Q.R=0;
		Q.data[Q.R]=k;
	}
	else
	{
		Q.R+=1;
		Q.data[Q.R]=k;
	}
}
int deQueue(queue& Q)
{
	int temp;
	if(isEmpty(Q)) return 0;
	else if(Q.F==Q.R)
	{
		temp=Q.data[Q.R];
		Q.F=Q.R=-1;
		return temp;
	}	
	else
	{
		temp=Q.data[Q.R];
		Q.R-=1;
		return temp;
	}
}

void show(sv x[], int i)
{
	cout << "\n----------Sinh vien thu " << i+1 << "----------\n";
	cout << "MSSV: " << x[i].mssv << "\n";
	cout << "Ten: " << x[i].name << "\n";
	cout << "CPA: " << x[i].cpa;
}

void DFS_Deepth(int id_sv[7][7], int v, sv x[]) // duyet theo chieu sau
{
	x[v].visited=1;
	show(x, v);
	for(int i=0; i<7; i++)
	{
		if(id_sv[v][i]==1 && !x[i].visited)
		{
			DFS_Deepth(id_sv, i, x);
		}
	}
}

void DFS_Width(int id_sv[7][7], int v, sv x[]) // duyet theo chieu rong
{
	x[v].visited=1;
	queue Q;
	init(Q);
	enQueue(Q, v);
	show(x, v);
	while(!isEmpty(Q))
	{
		v=deQueue(Q);
		for(int i=0; i<7; i++)
		{
			if(id_sv[v][i]==1 && !x[i].visited)
			{
				enQueue(Q, i);
				x[i].visited=1;
				show(x, i);
			}
		}
	}
}
int main()
{
	int id_sv[7][7]={
				{0, 1, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 1, 0},
				{0, 0, 0, 0, 0, 1, 1},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 1, 0}
					};
	sv x[7];
	for(int i=0; i<7; i++)
	{
		cout << "----------Sinh vien thu " << i+1 << "----------\n";
		x[i].mssv=i+1;
		cout << "Ten: "; getline(cin, x[i].name);
		cout << "CPA: "; cin >> x[i].cpa;
		cout << "Visited: "; cin >> x[i].visited; cin.ignore();
	}
	//DFS_Deepth(id_sv, 0, x);
	//DFS_Width(id_sv, 0, x);
 } 
 
