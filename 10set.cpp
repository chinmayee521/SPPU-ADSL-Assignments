//===============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 10 : Set operations
//===============================================================================

#include<iostream>
using namespace std;
#define MAX 30
class SET
{
    int element[MAX],no;

public:
        void get();
        void display();
        void Union(SET,SET);
        void Intersection(SET,SET);
        void Difference(SET,SET);
        void Symmetric_Difference(SET,SET);
        void Delete(int,SET&);
        void Insert(int,SET&);
        void Search(int,SET&);
};


void SET :: get()
{
    cout<<"Enter The Number Of Elements: ";
    cin>>no;

    for(int i=0;i<no;i++)
    {
    	cout<<"Enter The Element: ";
    	cin>>element[i];
    }

    cout<<endl<<endl;

}


void SET :: Insert(int k,SET &a)
{
    if(a.no<=MAX)
    {
        a.element[a.no++]=k;
        cout<<k<<" Has Been Inserted Into The Set!!!"<<endl;
    }
    else
        cout<<"The Set Is Full!!!"<<endl;
}


void SET :: Delete(int k, SET &a)
{
	int j,flag=0;
	for(int i=0;i<a.no;i++)
	{
		if(a.element[i]==k)
		{
			j=i;
			flag=1;
			break;
		}
	}

	if(flag==1)
	{
	    for(int i=j;i<a.no;i++)
        a.element[i]=a.element[i+1];

        a.no--;
        cout<<k<<" Has Been Deleted From The Set!!!"<<endl;
	}
	else
        cout<<"The Element Is Not Present In The Set!!!"<<endl;
}
void SET::Search(int k,SET &a)
{
        int j,flag=0;
	for(int i=0;i<a.no;i++)
	{
		if(a.element[i]==k)
		{
			j=i;
			flag=1;
			break;
		}
	}

	if(flag==1)
	{

        cout<<k<<"Is present in the Set!!!"<<endl;
	}
	else
        cout<<"The Element Is Not Present In The Set!!!"<<endl;
}


void SET :: display()
{
    cout<<"{ ";
    for(int i=0;i<no;i++)
    {
        cout<<element[i];
        if(i != no-1)
            cout<<", ";
    }
    cout<<" }"<<endl<<endl;
}



void SET :: Union(SET a , SET b)
{
    int counter=0,flag;
    for(int i=0;i<a.no;i++)
    {
        element[i]=a.element[i];
        counter++;
    }

    for(int i=0;i<b.no;i++)
    {
        flag=0;

        for(int j=0;j<a.no;j++)
        {
            if(b.element[i] == a.element[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
        	element[counter]=b.element[i];
            counter++;
        }
    }

    no=counter;

}



void SET :: Intersection(SET a , SET b)
{
    int counter=0,flag;

    for(int i=0;i<b.no;i++)
    {
        flag=0;

        for(int j=0;j<a.no;j++)
        {
            if(b.element[i] == a.element[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            element[counter]=b.element[i];
            counter++;
        }
    }

    no=counter;
}



void SET :: Difference(SET a , SET b)
{
     int counter=0,flag;

    for(int i=0;i<a.no;i++)
    {
        flag=0;

       for(int j=0;j<b.no;j++)
        {
            if(a.element[i] == b.element[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
        	element[counter]=a.element[i];
            counter++;
        }
    }

    no=counter;
}

int main()
{
    SET Set_A,Set_B,inter,uni,diff,symm,a_b,b_a;
    int k;
    char c,choice;

    cout<<"Enter The Elements Of Set A"<<endl;
    Set_A.get();

    cout<<"Enter The Elements Of Set B"<<endl;
    Set_B.get();

    do
    {
        cout<<"\n\n================================== ~ Set Operations ~ ==================================\n1. Display Elements Of Set A\n2. Display Elements Of Set B\n3. Union Of Sets\na. Intersection Of Sets\n5. Difference Of Sets(A-B)\n6. Insert An Element Into The Set\n7. Delete An Element From The Set\n8.Search an element from the set\n9.Symmetric Difference\n10. Exit The Program\nEnter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case '1':
            		cout<<"Elements in Set A: ";
            	    Set_A.display();
            	    break;


            case '2':
                    cout<<"Elements in Set B: ";
                    Set_B.display();
                    break;

             case '3':
            		uni.Union(Set_A,Set_B);
            		cout<<"Union Of The Sets: ";
            		uni.display();
            		break;



             case '4':

                    inter.Intersection(Set_A,Set_B);
                    cout<<"Intersection Of The Sets: ";
                    inter.display();
                    break;


             case '5':
            		diff.Difference(Set_A,Set_B);
            		cout<<"Difference Of The Sets(A-B): ";
            		diff.display();

            		diff.Difference(Set_B,Set_A);
            		cout<<"Difference Of The Sets(B-A): ";
            		diff.display();
                        break;


             case '6':
                    cout<<endl<<"Enter The Name Of The Set In Which Insertion Is To Be Performed : ";
                    cin>>c;
                    if(c=='a' || c=='A')
                    {
                        cout<<endl<<"Enter The Element You Want To Insert In Set A: ";
                        cin>>k;
                        Set_A.Insert(k,Set_A);
                    }
                    else if(c=='b' || c=='B')
                    {
                        cout<<endl<<"Enter The Element You Want To Insert In Set B: ";
                        cin>>k;
                        Set_B.Insert(k,Set_B);
                    }
                    else
                        cout<<endl<<"~ Such A Set Does Not Exist!!! ~"<<endl;
                    break;

             case '7':
                    cout<<endl<<"Enter The Name Of The Set Whose Element You Want To Delete: ";
                    cin>>c;
                    if(c=='a' || c=='A')
                    {
                       cout<<endl<<"Enter The Element You Want To Delete From Set A: ";
                        cin>>k;
                        Set_A.Delete(k,Set_A);
                    }
                    else if(c=='b' || c=='B')
                    {
                       cout<<endl<<"Enter The Element You Want To Delete From Set B: ";
                        cin>>k;
                        Set_B.Delete(k,Set_B);
                    }
                    else
                        cout<<endl<<"~ Such A Set Does Not Exist!!! ~"<<endl;

                    break;

         case '8':
                    cout<<endl<<"Enter The Name Of The Set Whose Element You Want To Delete: ";
                    cin>>c;
                    if(c=='a' || c=='A')
                    {
                       cout<<endl<<"Enter The Element You Want To Search From Set A: ";
                        cin>>k;
                        Set_A.Search(k,Set_A);
                    }
                    else if(c=='b' || c=='B')
                    {
                       cout<<endl<<"Enter The Element You Want To Search From Set B: ";
                        cin>>k;
                        Set_B.Search(k,Set_B);
                    }
                    else
                        cout<<endl<<"~ Such A Set Does Not Exist!!! ~"<<endl;

                    break;

          case '9':
                        a_b.Difference(Set_A,Set_B);
                        b_a.Difference(Set_B,Set_A);
                       symm.Union(a_b,b_a);
                       cout<<"\n Symmetric difference is: ";
                       symm.display();
                       break;



        }

    } while(choice!='10');

}
