#include<iostream>
using namespace std;

void DFS_Depth(int G[7][7], int v)
{
	visited[v]=1;
	cout << v+1 << "	";
	for(int i=0; i<7; i++)
	{
		if(G[v][i]==1 && !visited[i])
		{
			DFS_Depth(G, i);
		}
	}
}

typedef struct Queue
{
	int data[7];
	int F, R;
} queue;
void init(queue& Q)
{
	Q.F=-1;
	Q.R=-1;
}
int checkEmpty(queue Q)
{
	return Q.F==-1;
}
void enQueue(queue& Q, int v)
{
	if(checkEmpty(Q)) 
	{
		Q.F=Q.R=0;
		Q.data[Q.R]=v;
	}
	else
	{
		Q.R+=1;
		Q.data[Q.R]=v;
	}
}
int deQueue(queue& Q)
{
	if(checkEmpty(Q)) return 0;
	else if(Q.F==Q.R)
	{
		int a=Q.data[Q.R];
		Q.F=Q.R=-1;
		return a;
	}
	else
	{
		int b=Q.data[Q.R];
		Q.R-=1;
		return b;
	}
}
void DFS_Width(int G[7][7], int v)
{
	visited[v]=1;
	queue Q;
	init(Q);
	enQueue(Q, v);
	cout << v+1 << "	";
	while(!checkEmpty(Q))
	{
		v=deQueue(Q);	
		for(int i=0; i<7; i++)
		{
			if(G[v][i]==1 && !visited[i])
			{
				enQueue(Q, i);
				visited[i]=1;
				cout << i+1 << "	";
			}
		}
	}
}
int main()
{
	int G[7][7]={
				{0, 1, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 1, 0},
				{0, 0, 0, 0, 0, 1, 1},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 1, 0}
				};
	DFS_Width(G, 0);
}

