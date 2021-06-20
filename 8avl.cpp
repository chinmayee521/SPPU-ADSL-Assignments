//===============================================================================
// Name        : Chinmayee Taralkar
// Roll no     : SECOB252
//Assignment 8: AVL tree
//===============================================================================
#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node* left;
struct node* right;
};

class AVL{
public:
    node *root;
    int B_factor(node* temp);
    int height(node* temp);
    node* rotateRight(node* parent);
    node* rotateLeft(node* parent);
    node* RR(node* parent);
    node* LL(node* parent);
    node* LR(node* parent);
    node* RL(node* parent);
    node* balance(node* T);
    node* insert(node* root, int value);
    void preOrder(node *cn);
    void postOrder(node *cn);
    void inOrder(node *cn);
    //node* getRoot();

    AVL(){
    root=NULL;
    }

};


/*node* AVL::getRoot(){
    return root;
}*/

int AVL::B_factor(node* temp){
    int l_height=height(temp->left);
    int r_height=height(temp->right);
    int b_factor= l_height-r_height;
    return b_factor;
}

int AVL::height(node* temp){
    int h=0;
    if(temp!=NULL){
        int l_height=height(temp->left);
        int r_height=height(temp->right);
        int max_height=max(l_height,r_height);
        h=max_height+1;
    }
    return h;
}

node* AVL::rotateRight(node* parent){
    node* temp;
    temp=parent->left;
    parent->left=temp->right;
    temp->right=parent;
    return temp;
}

node* AVL::rotateLeft(node* parent){
    node* temp;
    temp=parent->right;
    parent->right=temp->left;
    temp->left=parent;
    return temp;
}

node* AVL::RR(node* parent){
    node* temp=rotateLeft(parent);
    return temp;
}

node* AVL::LL(node* parent){
    node* temp=rotateRight(parent);
    return temp;
}

node* AVL::LR(node* parent){
    node* temp;
    temp=parent->left;
    parent->left=rotateLeft(temp);
    temp=rotateRight(parent);
    return temp;
}

node* AVL::RL(node* parent){
    node* temp;
    temp=parent->right;
    parent->right=rotateRight(temp);
    temp=rotateLeft(parent);
    return temp;
}

node* AVL::balance(node *T){
    int bal_factor=B_factor(T);
    if(bal_factor>1){
        if(B_factor(T->left)>0)
            T=LL(T);
        else
            T=LR(T);
    }else if(bal_factor<-1){
        if(B_factor(T->right)>0)
            T=RL(T);
        else
            T=RR(T);
    }
    return T;
}

node* AVL::insert(node* root, int value){
    if(root==NULL){
        root=new node;
        root->data=value;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
        root=balance(root);
    }
    else if(value>=root->data){
        root->right=insert(root->right,value);
        root=balance(root);
    }
    return root;
}

void AVL::preOrder(node *cn){
    if(cn!= NULL){
        cout<<cn->data<<" ";
        preOrder(cn->left);
        preOrder(cn->right);
    }

}

void AVL::postOrder(node *cn){
    if(cn!= NULL){
        preOrder(cn->left);
        preOrder(cn->right);
         cout<<cn->data<<" ";
    }

}

void AVL::inOrder(node *cn){
    if(cn!= NULL){
        preOrder(cn->left);
        cout<<cn->data<<" ";
        preOrder(cn->right);
    }

}

int main(){
AVL a;
int choice,value;
do{
    cout<<endl;
    cout<<"1] Add Node"<<endl;
    cout<<"2] Inorder Traversal"<<endl;
    cout<<"3] Preorder Traversal"<<endl;
    cout<<"4] Postorder Traversal"<<endl;
    cout<<"5] Exit"<<endl;
    cout<<"  Enter your Choice : ";
    cin>>choice;

    switch(choice){
    case 1:
        cout<<"Enter the Value to Insert : ";
        cin>>value;
        a.root=a.insert(a.root,value);
    break;
    case 2:
        a.inOrder(a.root);
    break;
    case 3:
        a.preOrder(a.root);
    break;
    case 4:
        a.postOrder(a.root);
    break;
    case 5:
        cout<<"Exited"<<endl;
    break;
    }
}while(choice!=5);

return 0;
}
