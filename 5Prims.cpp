//===============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 2 : Implement Prim's algorithm
//===============================================================================

#include <iostream>
using namespace std;
class graph
{
	int a[10][10], v, e,v1,v2,w,mincost=0,G[10][10];
	bool visited[10];
public:
	graph()
{
	for(int i=0;i<10;i++)
	{
		visited[i]=0;
		for(int j=0;j<10;j++)
		{
			a[i][j]=0;
			G[i][j]=0;
		}
	}
e=0;
}
	void create();
	void display();
	void prim();

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
	cout<<"\nEnter weight of the edge: ";
	cin>>w;
	if((v1<0 && v1>v) || (v2<0 && v2>v))
	{
		cout<<"\nInvalid!! Enter again--";
		goto d;
	}
	else
	{
		a[v1][v2]=w;
		a[v2][v1]=w;

	}
	cout<<"\nDo you want to add more edges?(y/n)\n\n";
	cin>>ch;
	}while(ch=='y');
}
void graph::display()
{
	for(int k=0;k<v;k++)
	{
		cout<<k<<"\t";

	}
	cout<<"\n---------------------------------------------------------";
	cout<<"\n\n";
	for(int i=0;i<v;i++)
	{
		cout<<i<<"\t\t";

		for(int j=0;j<v;j++)
		{

			cout<<a[i][j]<<"\t";

		}
		cout<<"\n\n";
	}
}
void graph::prim()
{
	int min,x,y;
	visited[0]=1;									//initialize starting vertex to 0
	while(e<v-1)									//loop till edge is not equal to vertex-1
	{
		 min=9999,x=0,y=0;							//to calculate min edge during each iteration

		for(int i=0;i<v;i++)						//row wise
		{
			if(visited[i]==1)
			{
				for(int j=0;j<v;j++)				//col wise
				{
					if(visited[j]==0 && a[i][j]!=0)
					{
						if(min>a[i][j])				//finding min value
						{
							min=a[i][j];
							x=i;
							y=j;

						}
					}
				}
			}
		}
		mincost=mincost+min;						//to find mincost
		G[x][y]=G[y][x]=mincost;
		visited[y]=1;
		e++;
	}
	cout<<"\nMinimum Cost of spanning tree is: "<<mincost;

}
int main()
{
	graph g;
	int c; char ch;
	do
	{
	cout<<"\n''''----****MENU****----''''\n";
	cout<<"\n1)Create\t2)Display\t3)MST\nEnter your choice: ";
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
		g.prim();
		break;


	}
cout<<"\nGo back to menu?(y/n): ";
cin>>ch;
	}while(ch=='y');
	return 0;
}


/*
 *
''''----****MENU****----''''

1)Create	2)Display	3)MST
Enter your choice: 1

Enter number of vertices: 5

Enter end vertices v1 and v2 of the edge: 0
1

Enter weight of the edge: 10

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 0
3

Enter weight of the edge: 30

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 0
4

Enter weight of the edge: 100

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 1
2

Enter weight of the edge: 50

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 2
3

Enter weight of the edge: 20

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 4
3

Enter weight of the edge: 60

Do you want to add more edges?(y/n)

y

Enter end vertices v1 and v2 of the edge: 4
2

Enter weight of the edge: 10

Do you want to add more edges?(y/n)

n

Go back to menu?(y/n): y

''''----****MENU****----''''

1)Create	2)Display	3)MST
Enter your choice: 2
         0	 1	  2	 3	 4
---------------------------------------------------------

0		0	10	0	30	100

1		10	0	50	0	0

2		0	50	0	20	10

3		30	0	20	0	60

4		100	0	10	60	0


Go back to menu?(y/n): y

''''----****MENU****----''''

1)Create	2)Display	3)MST
Enter your choice: 3

Minimum Cost of spanning tree is: 70
Go back to menu?(y/n): n
 *
 */
