//============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 1 : Implement dictionary using Binary Search Tree
// Operations: -Create (Add new words with meanings)
//			    -Inorder, preorder, postorder display
//			    -Search the word
//		        -Delete the word
//	            -Modify the word

 //============================================================================


#include <iostream>
using namespace std;

typedef struct tnode
{
	string w, m;
	tnode *left, *right;
}tnode;
class dictionary
{
	tnode *root,*parent;
public:
	dictionary()
{
		root=NULL;
		parent=NULL;
}
	void create();
	void inorder(tnode *temp);
	void preorder(tnode *temp);
	void postorder(tnode *temp);
	tnode * get_root()										//to return root
	{
		return root;
	}
	void search_node(string key);
	void delete_node(string d);
	void modify(string p);

};

void dictionary::create()
{
	char c;
	do
	{
	tnode *nn=new tnode;
	cout<<"\nEnter word and its meaning: ";
	cin>>nn->w>>nn->m;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL)								//if tree is empty(no nodes)
	{
		root=nn;
	}
	else
	{
		tnode *temp;
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;

		if(nn->w<temp->w)
		{
			temp=temp->left;
		}
		else
			temp=temp->right;
		}

		if(nn->w<parent->w)						//if parent value is greater move left else right
		{
			parent->left=nn;
		}
		else
			parent->right=nn;

	}
	cout<<"\nDo you want to add new word??";
	cin>>c;
	}while(c=='y'||c=='Y');
}


void dictionary::inorder(tnode *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<"Word: "<<temp->w<<"\tMeaning: "<<temp->m<<"\n";
		inorder(temp->right);
	}

}

void dictionary::postorder(tnode *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<"Word: "<<temp->w<<"\tMeaning: "<<temp->m<<"\n";
	}

}
void dictionary::preorder(tnode *temp)
{
	if(temp!=NULL)
	{
		cout<<"Word: "<<temp->w<<"\tMeaning: "<<temp->m<<"\n";
		preorder(temp->left);
		preorder(temp->right);
	}

}

void dictionary::search_node(string key)
{
	char k;
	int flag=0;
	tnode *temp;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->w==key)
		{
			flag=1;
			break;
		}
		else
		{
			if (temp->w<key)
				temp=temp->right;
			else
				temp=temp->left;
		}
	}
	if(flag==1)
	{
		cout<<"\nWord found!!!!";
	}
	else
	{
		cout<<"\nWord not found!! ";
	}
}

void dictionary::delete_node(string d)
{
	int flag=0;
		tnode *temp;
		temp=root;
		while(temp!=NULL)								//traverse till null
		{
			if(temp->w==d)
			{
				flag=1;
				break;
			}
			else
			{
				parent=temp;
				if (temp->w<d)
					temp=temp->right;
				else
					temp=temp->left;
			}
		}
		if(flag==0)
		{
			cout<<"\nword not found!! ";
		}
		else
		{
			if(temp->left==NULL && temp->right==NULL)				//leaf node- no left and right child
			{
				if(temp==root)
				{
					delete temp;
					root=NULL;
					return;
				}
				else
				{
					if(parent->w>temp->w)							//temp is left child of parent
						parent->left=NULL;
					else
						parent->right=NULL;							//temp is right child of parent

				}
			}
			else
			{
				if(temp->left==NULL)							//left child absent, right child present
				{
					if(temp==root)
					{
						root=temp->right;
						return;
					}
					if(temp->w<parent->w)						//temp is left child of parent
						parent->left=temp->right;
					else
						parent->right=temp->right;				//temp is right child of parent
				}
				else if(temp->right==NULL)						//right child absent, left child present
				{

					if(temp==root)
					{
						root=temp->right;
						return;
					}
					if(temp->w<parent->w)
						parent->left=temp->left;				//temp is left child of parent
					else
						parent->right=temp->left;				//temp is right child of parent

				}
				else if(temp->left!=NULL && temp->right!=NULL)			//both left and right child present
				{
					tnode *temp1;
					temp1=temp->left;                           //rightmost node of left subtree
					while(temp1->right!=NULL)					//traversal
					{
						temp1=temp1->right;
					}
					string m;
					m=temp1->w;									//store value of rightmost child of left subtree
					delete_node(temp1->w);						//delete rightmost child
					temp->w=m;									//store value of temp of word in m

				}

			}
		}

}

void dictionary::modify(string p)
{

	string m1;
	int flag=0;
	tnode *temp;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->w==p)
		{
			flag=1;
			break;
		}
		else
		{
			if (temp->w<p)
				temp=temp->right;
			else
				temp=temp->left;
		}
	}
	if(flag==1)
	{
		cout<<"\nWord found!!!!";
		cout<<"\nWord: "<<temp->w<<"\tMeaning: "<<temp->m;
		cout<<"\nEnter new meaning: ";
		cin>>m1;
		temp->m=m1;
		cout<<"\nMeaning updated!!!";
	}
	else
		cout<<"\nWord not found!! ";
}

int main()
{
	dictionary b1;
	int ch; string dd,ddd,dddd;

	do
	{
	cout << "\n\n\t---***DICTIONARY***---\n1)Create\t2)Inorder\t3)Preorder\n4)Postorder\t5)Search word\t6)Delete word\n7)Modify meaning\n8)Exit" << endl;
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
	case 1:
		b1.create();
		break;
	case 2:

		b1.inorder(b1.get_root());
		break;
	case 3:
		b1.preorder(b1.get_root());
		break;
	case 4:

	    b1.postorder(b1.get_root());
		break;
	case 5:
		cout<<"\nEnter the word to be searched----";
		cin>>dd;
		b1.search_node(dd);
		break;
	case 6:
		cout<<"\nEnter the word to be deleted----";
		cin>>ddd;
		b1.delete_node(ddd);
		cout<<"\nWord deleted!";
		break;
	case 7:
		cout<<"\nEnter the word whose meaning is to be modified: ";
		cin>>dddd;
		b1.modify(dddd);
	}

	}while(ch!=8);
	return 0;
}

/*
 * OUTPUT:
 *

	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 1

Enter word and its meaning: parrot bird

Do you want to add new word??y

Enter word and its meaning: pune city

Do you want to add new word??y

Enter word and its meaning: india country

Do you want to add new word??y

Enter word and its meaning: hibiscus flower

Do you want to add new word??y

Enter word and its meaning: mango fruit

Do you want to add new word??y

Enter word and its meaning: doctor profession

Do you want to add new word??y

Enter word and its meaning: christmas festival

Do you want to add new word??n


	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 2
Word: christmas	Meaning: festival
Word: doctor	Meaning: profession
Word: hibiscus	Meaning: flower
Word: india	Meaning: country
Word: mango	Meaning: fruit
Word: parrot	Meaning: bird
Word: pune	Meaning: city


	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 3
Word: parrot	Meaning: bird
Word: india	Meaning: country
Word: hibiscus	Meaning: flower
Word: doctor	Meaning: profession
Word: christmas	Meaning: festival
Word: mango	Meaning: fruit
Word: pune	Meaning: city


	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 4
Word: christmas	Meaning: festival
Word: doctor	Meaning: profession
Word: hibiscus	Meaning: flower
Word: mango	Meaning: fruit
Word: india	Meaning: country
Word: pune	Meaning: city
Word: parrot	Meaning: bird


	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 5

Enter the word to be searched----pune

Word found!!!!

	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 6

Enter the word to be deleted----pune


	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 7

Enter the word whose meaning is to be modified: doctor

Word found!!!!
Word: doctor	Meaning: profession
Enter new meaning: career

Meaning updated!!!

	---***DICTIONARY***---
1)Create	2)Inorder	3)Preorder
4)Postorder	5)Search word	6)Delete word
7)Modify meaning
8)Exit

Enter your choice: 8
 *
 */

















