#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *left,*right;

}TREE;

TREE* lexins(TREE *,int);
void preorder(TREE *);
void inorder(TREE *);
void postorder(TREE *);
int minval(TREE *);
int maxval(TREE *);
int noofnodes(TREE *);
int count;


int main(void){
    TREE *root,*temp;
    int choice,x;
    root=NULL;

    while(1){
        printf("\t1->Insertion\n\t2->Preorder");
        printf("\t3->Inorder\n\t4->Postorder Traversal");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                    printf("Enter value...");
                    scanf("%d",&x);
                    root=lexins(root,x);}break;
            case 2:{preorder(root);}break;
            case 3:{inorder(root);}break;
            case 4: {postorder(root);}break;
            case 5:{x=minval(root);printf("Min:%d",x);}break;
            case 6: x=maxval(root);printf("Max:%d",x);break;
            case 7:{count=noofnodes(root);printf("no.ofnodes: %d",count);}break;
            default:return 0;
        }
    }
}

TREE* lexins(TREE *root,int x){
    TREE *newnode,*temp;
    int flag=1;
    newnode=(TREE *)malloc(sizeof(TREE));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->info=x;


    if(root==NULL) root=newnode;
    else
    {  temp=root; 
        while(flag)
        {

        if(x<temp->info)
            if(temp->left== NULL)
            {  temp->left=newnode;
             flag=0; }
        else temp=temp->left;
        

        else if(temp->right==NULL)
        {
            temp->right=newnode;
            flag=0;
        }else temp=temp->right;
    }
    

}return root;}

void preorder(TREE * root){
    if(root!=NULL){
    printf("%d",root->info);
    preorder(root->left);
    preorder(root->right);}
}
void inorder(TREE * root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d",root->info);
    inorder(root->right);}
}
void postorder(TREE * root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->info);}
}
int minval(TREE *root){
    TREE *temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
        return temp->info;
}
int maxval(TREE *root){
    TREE *temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
        return temp->info;
}

int noofnodes(TREE *root){
    
    if(root!=NULL){
        noofnodes(root->left);
        count++;
        noofnodes(root->right);
        }
    
    return count;
}

TREE* deletenode(TREE *root,int x){
    TREE *temp,*q,*parent,*insucc;int key=x;
    q=NULL;
    temp=root;
    parent=NULL;

    //search for given info in tree
    while(temp!=NULL && temp->info!=key){
        parent=temp;
        if(key<temp->info) temp=temp->left;
        else temp=temp->right;
    }
    if(temp==NULL)
    printf("Unsuccessful search...Key not found..");
    else if(temp->left==NULL) q=temp->right;//single child case
    else if(temp->right==NULL) q=temp->left; 
    else{
        insucc=temp->right;
        while(insucc->left!=NULL) insucc=insucc->left;

        insucc->left=temp->left;
        q=temp->right;

    }
    if(parent==NULL) root=q;
    else if(temp=parent->left) parent->left=q;
    else if(temp=parent->right)parent->right=q;
    count--;

}