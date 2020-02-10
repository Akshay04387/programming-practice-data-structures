#include<iostream>
using namespace std;

typedef struct Node{
  int val;
  struct Node *left;
  struct Node *right;
}node; 

node *root = nullptr;

node *newnode(int data){
    node *temp = (node *)malloc(sizeof(node));
    temp->val = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
void insert(int data,node **ptr){
    if(*ptr == nullptr){
        *ptr = newnode(data);
    }else{
        if((*ptr)->val>data)
            insert(data,&((*ptr)->left));
        else
            insert(data,&((*ptr)->right));
    }
}
void preorder(node *ptr){
    if(ptr == nullptr)
        printf("L ");
    else{
        preorder(ptr->left);
        preorder(ptr->right);
        printf("%d ",ptr->val);
    }
}

int main()
{
    int choice,val;
    while(1){
        cout<<"enter the choice:\n1. insert 2. preorder 3.exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter the val\n";
                cin>>val;
                insert(val,&root);
                break;
            case 2:
                cout<<"printing in preorder\n";
                preorder(root);
                cout<<endl;
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}
