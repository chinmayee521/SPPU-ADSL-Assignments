//===============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 9 : File handling
//===============================================================================
#include <iostream>
#include<fstream>
using namespace std;

class student
{

	int  rollno ;
	char name[10] ;
	float p;

public:
		void accept()
		{
		cout<<"\n Enter name = ";
		cin>>name;
		cout<<"\n Enter roll no = ";
		cin>>rollno;
		cout<<"\n Enter percentage = ";
		cin>>p;
		}
		void display()
		{

			cout<<"\n "<<name<<"\t\t|"<<rollno<<"\t |"<<p;
		}
		int ret_no()
		{
			return rollno;
		}



};


int main()
{

int ch , n=0 ,temp_no , flag , bytes ;
fstream file;
student s;

do
{
	cout<<"\n============================================================================";
	cout<<"\n_______________________________ M E N U ______________________________________";
	cout<<"\n============================================================================";
	cout<<"\n 1) Create File \n 2) Display \n 3) Insert a record \n 4) Search a Record \n 5) Modify \n 6) Exit ";
	cout<<"\n Enter your choice = ";
	cin>>ch;

	switch( ch )
	{
		case 1:
				file.open( "records.txt" , ios::out);
				cout<<"\n Enter no of records = ";
				cin>>n;
				for( int i=0 ; i<n ; i++)
				{
					s.accept();
					file.write((char*)&s , sizeof(s));
				}
				file.close();
				break;


		case 2:
				file.open("records.txt" , ios::in);
				cout<<"\n================|========|============";
				cout<<"\n name   \t| no \t | percentage";
				cout<<"\n================|========|============";
				/*for( int i=0 ; i<n ; i++)
				{
					file.read((char*)&s , sizeof(s));
					s.display();
				}*/
				if(n==0)
					cout<<"\n No records !";
				else
				{
				while( file.read((char*)&s , sizeof(s)))
				{
					s.display();
				}
				}
				file.close();

				break;
		case 3:
				file.open("records.txt" , ios::out | ios::app);		// append and out
				s.accept();
				file.write((char*)&s , sizeof(s)); n++;
				file.close();

				break;
		case 4:
				file.open("records.txt" , ios::in);
				cout<<"\n Enter roll no to be searched = ";
				cin>>temp_no;
				flag=0;
				/*for( int i=0; i< n ;i++)
				{
					file.read((char*)&s , sizeof(s));

					if( s.ret_no() == temp_no)
					{
						cout<<"\n Record found ! ";
						flag=1;break;
					}

				}*/

				// using eof

				 while( file.eof()==0)			// eof at end nonzero
				 {
					 file.read((char*)&s , sizeof(s));

					 if( s.ret_no() == temp_no)
					 {
					 	cout<<"\n Record found ! ";
					 	flag=1;break;
					 }


				 }
				if(flag==0)
				cout<<"\n Record not  found !";
				else
				{
					cout<<"\n================|========|============";
					cout<<"\n name   \t| no \t | percentage";
					cout<<"\n================|========|============";
					s.display();
				}


				file.close();
				break;
		case 5:
				file.open("records.txt" , ios::in | ios::out);			// in and out
				cout<<"\n Enter roll no to be searched = ";
				cin>>temp_no;
				flag=0;


			while( file.eof()==0)			// eof at end nonzero
			{
				file.read((char*)&s , sizeof(s));

				if( s.ret_no() == temp_no)
				{
				cout<<"\n Record found ! ";
				flag=1;break;
				}
			}
			if(flag==0)
				cout<<"\n Record not  found !";
			else
			{
				bytes = -1*sizeof(s);
				file.seekp( bytes , ios::cur);
				cout<<"\n Previous data :";
				cout<<"\n================|========|============";
				cout<<"\n name   \t| no \t | percentage";
				cout<<"\n================|========|============";
				s.display();
				cout<<"\n Enter new data :";
				s.accept();
				file.write((char*)&s , sizeof(s));
			}
			file.close();
				break;

		case 6:
				cout<<"\n E x i t i n g .....";
				break;
		default:
			cout<<"\n Invalid Choice ";

	}


}while( ch != 6);

	return 0;
}

// o u t p u t



/*
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 2

================|========|============
 name   	| no 	 | percentage
================|========|============
 No records !
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 1

 Enter no of records = 3

 Enter name = aaa

 Enter roll no = 1

 Enter percentage = 1

 Enter name = bbb

 Enter roll no = 56

 Enter percentage = 5

 Enter name = fff

 Enter roll no = 34

 Enter percentage = 3

============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 2

================|========|============
 name   	| no 	 | percentage
================|========|============
 aaa		|1	 |1
 bbb		|56	 |5
 fff		|34	 |3
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 3

 Enter name = gh

 Enter roll no = 4

 Enter percentage = 4

============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 2

================|========|============
 name   	| no 	 | percentage
================|========|============
 aaa		|1	 |1
 bbb		|56	 |5
 fff		|34	 |3
 gh		|4	 |4
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 4

 Enter roll no to be searched = 4

 Record found !
================|========|============
 name   	| no 	 | percentage
================|========|============
 gh		|4	 |4
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 4

 Enter roll no to be searched = 67

 Record not  found !
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 5

 Enter roll no to be searched = 4

 Record found !
 Previous data :
================|========|============
 name   	| no 	 | percentage
================|========|============
 gh		|4	 |4
 Enter new data :
 Enter name = ggggg

 Enter roll no = 40

 Enter percentage = 0

============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 2

================|========|============
 name   	| no 	 | percentage
================|========|============
 aaa		|1	 |1
 bbb		|56	 |5
 fff		|34	 |3
 ggggg		|40	 |0
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 7

 Invalid Choice
============================================================================
_______________________________ M E N U ______________________________________
============================================================================
 1) Create File
 2) Display
 3) Insert a record
 4) Search a Record
 5) Modify
 6) Exit
 Enter your choice = 6

 E x i t i n g .....*/
















