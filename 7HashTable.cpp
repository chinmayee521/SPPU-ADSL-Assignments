//===============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 7 : Implement telephone directory operations using Hash table
//===============================================================================
#include<iostream>
#include<string>
using namespace std;

typedef struct teldir
{
    long long int no;
    string name;
}dir;

class hashtable
{
    bool flag[10];
    dir ht[10];

public:
    hashtable()
    {
        for(int i=0;i<10;i++)
        flag[i]=false;
    }

    int hashfn(long long int key)
    {
        return key%10;
    }

    void insert()
    {
        dir a;
        cout<<"\nEnter name of customer : ";
        cin>>a.name;
        cout<<"Enter phone no : ";
        cin>>a.no;
        int p = hashfn(a.no);
        for(int i=0;i<10;i++)
        {
            if(flag[p] == false)
            {
                ht[p] = a;
                flag[p] = true;
                cout<<"\nData inserted !";
                return;
            }
            else
            p=(p+1)%10;
        }
         cout<<"\nHash table overflow...";
    }

    void display()
    {
        cout<<'\n';
        for(int i=0;i<10;i++)
        {
            if(flag[i]==true)
            cout<<endl<<i<<" : "<<ht[i].no<<"\t"<<ht[i].name;

        }
    }

    void search(long long int key)
    {
        int p = hashfn(key);

         for(int i=0;i<10;i++)
        {
            if(ht[p].no == key && flag[p]==true)
            {
                cout<<"\n Phone number found ! ";
                cout<<"\nName of person having given phone number = "<<ht[p].name;
                return;
            }
            else
            p=(p+1)%10;
        }
        cout<<"\nPhone number not found.";

    }

    void search(string key)
    {
         for(int i=0;i<10;i++)
        {
              if(ht[i].name == key && flag[i]==true)
            {
                cout<<"\n Name found ! ";
                cout<<"\nPhone number of person is = "<<ht[i].no;
                return;
            }
        }
         cout<<"\nName not found.";
    }

    void delet(long long int key)
    {
        int p = hashfn(key);

         for(int i=0;i<10;i++)
        {
            if(ht[p].no == key && flag[p]==true)
            {
                flag[p]=false;
                cout<<"\nDetails deleted";
                return;
            }
            else
            p=(p+1)%10;
        }
        cout<<"\nPhone number not found.";

    }

};

int main()
{
    hashtable t;
    int v;
    long long int n;
    string a;
    cout<<"\n                 MENU\n";
    do
    {
        cout<<"\n\n1 : Insert Details";
        cout<<"\n2 : Display directory";
        cout<<"\n3 : Search Details using Phone no.";
        cout<<"\n4 : Search Details using name";
        cout<<"\n5 : Delete Details";
        cout<<"\n6 : Exit\n";
        cin>>v;

        switch(v)
        {
            case 1 :t.insert();
                    break;

            case 2 :cout<<"\nThe hash table of telephone directory is :";
                    t.display();
                    break;

            case 3 :cout<<"\nEnter phone no. to search";
                    cin>>n;
                    t.search(n);
                    break;

            case 4 :cout<<"\nEnter name to search";
                    cin>>a;
                    t.search(a);
                    break;

            case 5 :cout<<"\nEnter phone no. to delete";
                    cin>>n;
                    t.delet(n);
                    break;

            case 6 :cout<<"\nExitted..!";
                    break;

            default : cout<<"\nEnter a valid option!!\n";

        }

    }while(v!=6);




    return 0;
}














