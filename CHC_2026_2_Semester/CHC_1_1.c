#include <stdio.h>

void Change(int a, int b){
    int temp = a;
    a = b;
    b= temp;
    printf("After value swap(in function), A : %d, B : %d\n",a,b);

}
void ChangeAddress(int* s, int* q){
    int temp = *s;
    *s = *q;
    *q = temp;
    printf("After value swap(in function), A : %d, B : %d\n",*s,*q);
}
int main(){
    int a=0,b=0;
    printf("Enter two numbers: \n");
    scanf("%d %d",&a,&b);
    printf("Before swap, A : %d, B : %d\n",a,b);
    printf("\n");
    
    Change(a,b);
    printf("After value swap(in main), A : %d, B : %d\n",a,b);
    printf("\n");
    
    ChangeAddress(&a,&b);
    printf("Reference value swap(in main), A : %d, B : %d\n",a,b);

    return 0;

}