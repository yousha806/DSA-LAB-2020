#include<stdio.h>
#include<stdlib.h>

void BSTinsert(int);
void preorder(int);
void inorder(int);
void postorder(int);


int t[50];

int main(){

    int choice,i,x;
    
    for(i=0;i<50;i++)
        t[i]=0;
    while(1){
    printf("\nEnter 1-> BST Insertion\n\t2->Preorder\n\t3->Inorder\n\t4->Postorder\n\t5->Exit");
    scanf("%d",&choice);
    switch(choice){
            case 1: {
                    printf("Enter value...");
                    scanf("%d",&x);
                    BSTinsert(x);}break;
            case 2:{preorder(i);}break;
            case 3:{inorder(i);}break;
            case 4: {postorder(i);}break;
            default:exit(1);

    }
    }
}

void BSTinsert(int x){

    int i=0;
    if(t[i]==0) t[i]=x;//empty tree;
    else{
        while(t[i]!=0){
            if(x<t[i]) i=2*i+1;
            else i=2*i+2;
        }
        t[i]=x;
    }

}

void preorder(int i){
  
    if(t[i]!=0){
    printf("%d",t[i]);
    preorder(2*i+1);
    preorder(2*i+2);}
}

void inorder(int i){
    if(t[i]!=0){
    inorder(2*i+1);
    printf("%d",t[i]);
    inorder(2*i+2);}
}

void postorder(int i){
    
    if(t[i]!=0){
    postorder(2*i+1);
    postorder(2*i+2);
    printf("%d",t[i]);}
}

