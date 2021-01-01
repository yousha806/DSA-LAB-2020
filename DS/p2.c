#include<stdio.h>


void swap1(int a,int b){
    int t;
    t=a;
    a=b;
    b=t;
}
int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d %d\n",a,b);
    swap1(a,b);
    printf("%d %d",a,b);

}
