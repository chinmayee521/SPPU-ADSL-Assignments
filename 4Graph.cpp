//============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 4 : Implement Graph using adjacency matrix and adjacency list


 //============================================================================

#include <iostream>
using namespace std;
typedef struct node
{
	node *next;
	int v;

}node;
class stack
{
	int s[10],top;
public:
	stack()
{
		top=-1;
}
	int empty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	int full()
	{
		if(top==9)
			return 1;
		else
			return 0;



	}
	void push(int k)
	{

			top++;
			s[top]=k;

	}
	int pop()
	{
		int d;
		d=s[top];
		top--;
		return d;

	}
};
class graph
{
	int v,a[10][10],v1,v2;
	bool visited[10];
	node *hn[10];
public:
	graph()
{
	for(int i=0;i<10;i++)
	{
		visited[i]=0;
		for(int j=0;j<10;j++)
		{
			a[i][j]=0;
		}
	}
	v=0;
	for(int i=0;i<10;i++)
			{
				hn[i]=NULL;
			}

}
public:
	void create();
	void display();
	void dfs_rec(int k);
	void dfs_nrec(int k);
	void addnode(int v1,int v2);
	void display_list();


};

void graph::create()
{
	char ch;
	cout<<"\nEnter number of vertices: ";
	cin>>v;
	do
	{
	d:cout<<"\nEnter end vertices v1 and v2 of the edge: ";
	cin>>v1>>v2;
	if(v1<0 && v1>v || v2<0 && v2>v)
	{
		cout<<"\nInvalid!! Enter again--";
		goto d;
	}
	else
	{
		a[v1][v2]=1;
		a[v2][v1]=1;
		addnode(v1,v2);
		addnode(v2,v1);
	}
	cout<<"\nDo you want to add more edges?(y/n)\n\n";
	cin>>ch;
	}while(ch=='y');
}

void graph::display()
{
	for(int k=0;k<v;k++)
	{
		cout<<"\t"<<k;

	}
	cout<<"\n---------------------------------------------------------";
	cout<<"\n\n";
	for(int i=0;i<v;i++)
	{
		cout<<i<<"|\t";

		for(int j=0;j<v;j++)
		{

			cout<<a[i][j]<<"\t";

		}
		cout<<"\n\n";
	}
}
void graph::dfs_rec(int k)
{

	visited[k]=true;
	cout<<k<<"  ";
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false && a[i][k]==true)
			dfs_rec(i);
	}
}
void graph::dfs_nrec(int k)
{
	for(int i=0;i<v;i++)
	{
		visited[i]=0;
	}
	stack s1;
	visited[k]=true;
	s1.push(k);
	while(!s1.empty())
	{
		k=s1.pop();
		cout<<k<<" ";

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false && a[i][k]==true)
		{
			s1.push(i);
			visited[i]=1;
			break;
		}
	}
	}
}
void graph::addnode(int v1,int v2)
{
	char ch;

	node *nn=new node;
	nn->v=v1;
	nn->next=NULL;
	if(hn[v2]==NULL)
	{
		hn[v2]=nn;
	}
	else
	{
		node *cn;
		cn=hn[v2];
		while(cn->next!=NULL)
			cn=cn->next;
		cn->next=nn;
	}




}
void graph::display_list()
{
	for (int i=0;i<5;i++)
	{
		cout<<i;
		node *cn=hn[i];
		while(cn!=NULL)
		{
			cout<<"->"<<cn->v;
			cn=cn->next;
		}
		cout<<endl;
	}
}
int main()
{
	char m;
	int ver,c;
	graph g;
	do
	{
	cout<<"\n::::::::ADJACENCY MATRIX:::::::::";
	cout<<"\n1)create\n2)display\n3)dfs recursive traversal\n4)dfs nonrecursive\n5)Display adjacency list\n6)exit";
	cout<<"\nenter choice: ";
	cin>>c;
	switch(c)
	{
	case 1:
		g.create();
		break;

	case 2:
		g.display();
		break;

	case 3:
		cout<<"\nEnter starting vertex: ";
		cin>>ver;
		g.dfs_rec(ver);
		break;
	case 4:
		cout<<"\nEnter starting vertex: ";
		cin>>ver;
		g.dfs_nrec(ver);
		break;

	case 5:
		g.display_list();
		break;


	}

	}while(c!=6);

	return 0;
}


/*

::::::::ADJACENCY MATRIX:::::::::
1)create
2)display
3)dfs recursive traversal
4)dfs nonrecursive
5)Display adjacency list
6)exit
enter choice: 1

Enter number of vertices: 5

Enter end vertices v1 and v2 of the edge: 0
1

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 0
3

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 0
4

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 1
2

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 2
3

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 3
4

Do you want to add more edges?(y/n)

n

::::::::ADJACENCY MATRIX:::::::::
1)create
2)display
3)dfs recursive traversal
4)dfs nonrecursive
5)Display adjacency list
6)exit
enter choice: 2
	0	1	2	3	4
---------------------------------------------------------

0|	0	1	0	1	1

1|	1	0	1	0	0

2|	0	1	0	1	0

3|	1	0	1	0	1

4|	1	0	0	1	0


::::::::ADJACENCY MATRIX:::::::::
1)create
2)display
3)dfs recursive traversal
4)dfs nonrecursive
5)Display adjacency list
6)exit
enter choice: 3

Enter starting vertex: 0
0  1  2  3  4
::::::::ADJACENCY MATRIX:::::::::
1)create
2)display
3)dfs recursive traversal
4)dfs nonrecursive
5)Display adjacency list
6)exit
enter choice: 4

Enter starting vertex: 0
0 1 2 3 4
::::::::ADJACENCY MATRIX:::::::::
1)create
2)display
3)dfs recursive traversal
4)dfs nonrecursive
5)Display adjacency list
6)exit
enter choice: 5
0->1->3->4
1->0->2
2->1->3
3->0->2->4
4->0->3

::::::::ADJACENCY MATRIX:::::::::
1)create
2)display
3)dfs recursive traversal
4)dfs nonrecursive
5)Display adjacency list
6)exit
enter choice: 6


 */
