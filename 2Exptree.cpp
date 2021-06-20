//============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 3 : Implement Expression Tree using Binary Search Tree
// Operations: -Create
//  		   -Postorder display (non-recursive)


 //============================================================================

#include <iostream>
using namespace std;

typedef struct tnode
{
	char c;
	tnode *plf,*prt;
}tnode;

class stack
{
	tnode *s[20];
	int top;
public:
	stack()
{
		top=-1;
}
	void push(tnode *p)
	{
		top++;
		s[top]=p;
	}
	tnode* pop()
	{
		tnode *p;
		p=s[top];
		top--;
		return p;
	}
	char getTop()
	{
		if(empty())
		{
			return '$';
		}
		else
		return s[top]->c;
	}
	int empty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
};

class exp_tree
{
	tnode *cn,*root;
public:
	int priority(char ch)
	{
		switch(ch)
		{
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '$':
			return 0;
			break;
		}
	}
	void create();
	void display();
};

void exp_tree::create()
{
	tnode *nn;
	stack oper, opn;
	char exp[20];
	cout<<"\nEnter expression: ";
	cin>>exp;

	for(int i=0;exp[i]!='\0';i++)
	{
		nn=new tnode;
		nn->c=exp[i];
		if(nn->c=='+' || nn->c=='-' || nn->c=='*' || nn->c=='/')
		{
			char ch=oper.getTop();

			if(priority(ch)>=priority(nn->c))
			{
				while(!oper.empty() && priority(ch)>=priority(nn->c))
				{
				cn=oper.pop();
				cn->prt=opn.pop();
				cn->plf=opn.pop();
				opn.push(cn);
				}
			}
			oper.push(nn);
		}
		else
			opn.push(nn);

	}
	while(!oper.empty())
	{
		cn=oper.pop();
		cn->prt=opn.pop();
		cn->plf=opn.pop();
		opn.push(cn);
	}
	root=cn;


}

void exp_tree::display()
{
	tnode *cn1=root;
	stack s1,s2;
	s1.push(cn1);
	while(!s1.empty())
	{
		cn1=s1.pop();
		if(cn1->plf)
		{
			s1.push(cn1->plf);
		}
		if(cn1->prt)
		{
			s1.push(cn1->prt);
		}
		s2.push(cn1);

	}
	while(!s2.empty())
	{
		cn1=s2.pop();
		cout<<" "<<cn1->c;
	}
}






int main()
{
	exp_tree a;
	int n;
	do
	{
	cout <<"\n\t\tEXPRESSION TREE\n";
	cout<<"\n------------------------------------------------------------------------";
	cout<<"\n1.Create\n2.Display\n3.Exit\n**Enter your choice!= ";
	cin>>n;
	switch(n)
	{
	case 1:
		a.create();
		break;
	case 2:
		a.display();
		break;
	}
	}while(n!=3);
	return 0;
}

/*
 * OUTPUT:
 * 		EXPRESSION TREE

------------------------------------------------------------------------
1.Create
2.Display
3.Exit
**Enter your choice!= 1

Enter expression: a-b*c-d/e+f

		EXPRESSION TREE

------------------------------------------------------------------------
1.Create
2.Display
3.Exit
**Enter your choice!= 2
 a b c * - d e / - f +
		EXPRESSION TREE

------------------------------------------------------------------------
1.Create
2.Display
3.Exit
**Enter your choice!= 3
 *
 */
