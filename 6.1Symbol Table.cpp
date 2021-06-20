//===============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 6 : Symbol Table using linked list
//===============================================================================
#include <iostream>
using namespace std;


typedef struct node
{
	string  name  , type , val ;
	int  l[10] , no;
	node  * next ;

}node;

class table
{
	node *hn ;

public:
	table()
		{
			hn = NULL;	//*
		}
	void create();
	void display();
	void insert();
	void search();
	void del();

};
void table ::insert()
{
	int i ; char ans;
						// allocate memory

	node *nn = new node;
	nn->next=NULL;

					// accept details

	cout<<"\nEnter name of the variable = ";
	cin>>nn->name;

	cout<<"\n Enter type of the variable = ";
	cin>>nn->type;

	cout<<"\n Enter initial value = ";
	cin>>nn->val;

	 i =0;
	cout<<"\n Enter line numbers where the variable is used ...";

do
	{
		cout<<"\n Line no =";
		cin>>nn->l[i];
		i++;
		if(i==9)
		{
			cout<<"\n Max limit reached !";
			break;
		}
		cout<<"\n More lines ?";
		cin>>ans;
	}while(ans=='y' || ans=='Y');

	nn->no=i;

	if( hn == NULL )			// adding first node
	{
		hn=nn;
	}
	else
	{
		node *cn = hn;
							// traverse till last
		while(cn->next != NULL)
			cn=cn->next;

		cn->next = nn;

	}

	cout<<"\n Data Saved . . . ";



}
void table ::create()
{

	char c;
	do
	{

	insert();
	cout<<"\n Do you want to continue ?";
	cin>>c;

	}while(c=='y' || c=='Y');



}

void table::display()
{
	if( hn == NULL)
	{
		cout<<"\n Table is empty !";
		return;
	}
	int i =1;
	cout<<"\n=============================================================================";
	cout<<"\n					Symbol Table";
	cout<<"\n=============================================================================";

	cout<<"\n |\t Name\t Type\t Value\t line no\t\t No";
	cout<<"\n_|_________________________________________________________________________";

	node *cn = hn;
	while(cn != NULL)
	{

		cout<<"\n"<<i<<"|\t "<<cn->name<<"\t "<<cn->type<<"\t "<<cn->val<<"\t";

		for(int k =0 ; k< cn->no ;k++)
		{
			cout<<cn->l[k];
			if(k<cn->no-1)
				cout<<",";
		}
		if(cn->no <=4)
			cout<<"\t";
		cout<<"\t\t "<<cn->no;


		i++;
		cn = cn->next;
		cout<<"\n_|_________________________________________________________________________";
	}


}

void table ::search()
{
	if(hn==NULL)
	{
		cout<<"\n Table Empty !";

	}
	else
	{
	string temp;
	int f=0;

	cout<<"\n Enter the name of the variable to be searched = ";
	cin>>temp;

	node *cn = hn;
	while(cn!=NULL)
	{

		if(cn->name == temp)
		{
			cout<<"\n Data found !";
			cout<<"\n  Name\t Type\t Value\t line no\t\t No";
			cout<<"\n "<<cn->name<<"\t "<<cn->type<<"\t "<<cn->val<<"\t";

					for(int k =0 ; k< cn->no ;k++)
					{
						cout<<cn->l[k];
						if(k<cn->no-1)
							cout<<",";
					}
					if(cn->no <=4)
						cout<<"\t";
					cout<<"\t\t "<<cn->no;
				f=1;
				break;

		}
		cn=cn->next;			//*
	}
	if(f==0)
		cout<<"\n Data not found!";


	}


}

void table::del()
{

	if(hn==NULL)
	{
		cout<<"\n Table Empty !";

	}
else
{
	string temp;
	int f=0;

	cout<<"\n Enter the name of the variable to be deleted = ";
	cin>>temp;

	node *cn = hn;
	node *cn1 = NULL;		//*
	while(cn!=NULL)
	{

		if(cn->name == temp)
		{
			if(cn==hn)
			{
				hn=hn->next;
			}
			else
			cn1->next=cn->next;

			delete cn;
			cout<<"\n Record deleted !";
			display();

				f=1;
				break;

		}
		cn1=cn;
		cn=cn->next;			//*
	}
	if(f==0)
		cout<<"\n Data not found!";


	}




}
int main()
{

	int ch;
	table t;
do

{

	cout<<"\n==================================================================";
	cout<<"\n______________________________ M E N U _____________________________";
	cout<<"\n 1) Create \n 2) Display \n 3) Search \n 4) Insert \n 5) Delete \n 6) Exit";
	cout<<"\n Enter your choice = ";
	cin>>ch;

	switch( ch )
	{
	case 1:
		t.create();
			break;
	case 2:
		t.display();
			break;

	case 3:
		t.search();
			break;
	case 4:
			t.insert();
			break;
	case 5:
		t.del();
			break;
	case 6:
			cout<<"\n Exiting ...";
			break;
	default :
			cout<<"\n Invalid choice ! !";

	}

}while(ch !=6);




	return 0;
}










//   output










/*
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 2

 Table is empty !
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 1

Enter name of the variable = i

 Enter type of the variable = int

 Enter initial value = 0

 Enter line numbers where the variable is used ...
 Line no =1

 More lines ?y

 Line no =2

 More lines ?n

 Data Saved . . .
 Do you want to continue ?y

Enter name of the variable = s

 Enter type of the variable = string

 Enter initial value = pccoe

 Enter line numbers where the variable is used ...
 Line no =2

 More lines ?y

 Line no =3

 More lines ?y

 Line no =6

 More lines ?n

 Data Saved . . .
 Do you want to continue ?y

Enter name of the variable = x

 Enter type of the variable = float

 Enter initial value = 1.1

 Enter line numbers where the variable is used ...
 Line no =4

 More lines ?y

 Line no =5

 More lines ?y

 Line no =6

 More lines ?y

 Line no =7

 More lines ?n

 Data Saved . . .
 Do you want to continue ?n

==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 2

=============================================================================
					Symbol Table
=============================================================================
 |	 Name	 Type	 Value	 line no		 No
_|_________________________________________________________________________
1|	 i	 int	 0	1,2			 2
_|_________________________________________________________________________
2|	 s	 string	 pccoe	2,3,6			 3
_|_________________________________________________________________________
3|	 x	 float	 1.1	4,5,6,7			 4
_|_________________________________________________________________________
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 3

 Enter the name of the variable to be searched = x

 Data found !
  Name	 Type	 Value	 line no		 No
 x	 float	 1.1	4,5,6,7			 4
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 3

 Enter the name of the variable to be searched = xx

 Data not found!
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 4

Enter name of the variable = z

 Enter type of the variable = bool

 Enter initial value = 0

 Enter line numbers where the variable is used ...
 Line no =5

 More lines ?n

 Data Saved . . .
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 2

=============================================================================
					Symbol Table
=============================================================================
 |	 Name	 Type	 Value	 line no		 No
_|_________________________________________________________________________
1|	 i	 int	 0	1,2			 2
_|_________________________________________________________________________
2|	 s	 string	 pccoe	2,3,6			 3
_|_________________________________________________________________________
3|	 x	 float	 1.1	4,5,6,7			 4
_|_________________________________________________________________________
4|	 z	 bool	 0	5			 1
_|_________________________________________________________________________
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 5

 Enter the name of the variable to be deleted = z

 Record deleted !
=============================================================================
					Symbol Table
=============================================================================
 |	 Name	 Type	 Value	 line no		 No
_|_________________________________________________________________________
1|	 i	 int	 0	1,2			 2
_|_________________________________________________________________________
2|	 s	 string	 pccoe	2,3,6			 3
_|_________________________________________________________________________
3|	 x	 float	 1.1	4,5,6,7			 4
_|_________________________________________________________________________
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 5

 Enter the name of the variable to be deleted = xz

 Data not found!
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 5

 Enter the name of the variable to be deleted = i

 Record deleted !
=============================================================================
					Symbol Table
=============================================================================
 |	 Name	 Type	 Value	 line no		 No
_|_________________________________________________________________________
1|	 s	 string	 pccoe	2,3,6			 3
_|_________________________________________________________________________
2|	 x	 float	 1.1	4,5,6,7			 4
_|_________________________________________________________________________
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 44

 Invalid choice ! !
==================================================================
______________________________ M E N U _____________________________
 1) Create
 2) Display
 3) Search
 4) Insert
 5) Delete
 6) Exit
 Enter your choice = 6

 Exiting ...*/
