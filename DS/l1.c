#include<stdio.h>
int main(void){
    int a,b;
    a=39839489380438938908;b=4;
    //if a or b is a huge number it wont work, program is not robust
    int c=a+b;
    printf("%d",c);
    //what to do if number is bigger than all available data types
}