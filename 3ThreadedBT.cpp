//============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 2 : Implement Threaded Binary Tree
// Operations: -Create
//  			    -inorder display
//  			    -preorder display
//============================================================================
#include <iostream>
using namespace std;
typedef struct tbtnode
{
	tbtnode *left,*right;
	int data;
	int lth,rth;
}tbtnode;

class threaded_BT
{
	tbtnode *root,*dummy;
public:
	threaded_BT()
{
		root=NULL;
		dummy=new tbtnode;
		dummy->lth=1;
		dummy->rth=1;
		dummy->left=dummy;
		dummy->right=dummy;
}
	void create();
	void inorder();
	void preorder();

};

void threaded_BT::create()
{
	tbtnode *nn,*temp;
	char ch;
	do
	{
		nn=new tbtnode;
		nn->lth=nn->rth=1;
		nn->right=nn->left=NULL;

		cout<<"\nEnter data= ";
		cin>>nn->data;

		if(root==NULL)
		{

			root=nn;
			dummy->left=root;
			dummy->lth=0;
			root->left=dummy;
			root->right=dummy;
			root->lth=1;
			root->rth=1;

		}
		else
		{
			temp=root;
			while(1)
			{
				if(nn->data<=temp->data)
				{
					if(temp->lth==1)
					{
						nn->left=temp->left;
						nn->right=temp;
						temp->left=nn;
						temp->lth=0;
						break;

					}
					temp=temp->left;
				}
				else
				{
					if(temp->rth==1)
					{
						nn->right=temp->right;
						nn->left=temp;
						temp->right=nn;
						temp->rth=0;
						break;
					}
					temp=temp->right;
				}
			}


		}
		cout<<"\nContinue?(y/n)";
		cin>>ch;
	}while(ch=='y');
}
void threaded_BT::inorder()
{
	tbtnode *temp=root;
	while(temp!=dummy)
	{
		while(temp->lth==0)
		{
			temp=temp->left;
		}
		cout<<temp->data<<" ";
		while(temp->rth==1)
		{
			temp=temp->right;
			if(temp==dummy)
				return;
			cout<<temp->data<<" ";
		}
		temp=temp->right;
	}
}void threaded_BT::preorder()
{
	tbtnode *temp=root;
	while(temp!=dummy)
	{
		cout<<temp->data<<" ";
		while(temp->lth==0)
		{

			temp=temp->left;
			cout<<temp->data<<" ";
		}

		while(temp->rth==1)
		{
			temp=temp->right;
			if(temp==dummy)
				return;

		}
		temp=temp->right;
	}
}


int main()
{
	threaded_BT a1;
	int n;
	do
	{
	cout << "\n\t\tTHREADED BINARY TREE\n1.Create\n2.Inorder display\n3.Preorder display\n4.Exit\nEnter your choice\n";
	cin>>n;
	switch(n)
	{
	case 1:
		a1.create();
		break;
	case 2:
		a1.inorder();
		break;
	case 3:
		a1.preorder();
		break;

	}
	}while(n!=4);
	return 0;
}


/*
 * OUTPUT:
 * THREADED BINARY TREE
1.Create
2.Inorder display
3.Preorder display
4.Exit
Enter your choice
1

Enter data= 22

Continue?(y/n)y

Enter data= 14

Continue?(y/n)y

Enter data= 25

Continue?(y/n)y

Enter data= 12

Continue?(y/n)y

Enter data= 20

Continue?(y/n)y

Enter data= 10

Continue?(y/n)y

Enter data= 15

Continue?(y/n)y

Enter data= 30

Continue?(y/n)y

Enter data= 35

Continue?(y/n)n

		THREADED BINARY TREE
1.Create
2.Inorder display
3.Preorder display
4.Exit
Enter your choice
2
10 12 14 15 20 22 25 30 35
		THREADED BINARY TREE
1.Create
2.Inorder display
3.Preorder display
4.Exit
Enter your choice
3
22 14 12 10 20 15 25 30 35
		THREADED BINARY TREE
1.Create
2.Inorder display
3.Preorder display
4.Exit
Enter your choice
4
 *
 */
