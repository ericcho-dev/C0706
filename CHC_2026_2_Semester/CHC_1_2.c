#include <stdio.h>

void Swap(int q, int w){
    int temp ;
    temp = q;
    q = w;
    w = temp;
    printf("Swap by index : %d %d\n",q,w);
}
void SwapPointer(int* q, int* w){
    int temp ;
    temp = *q;
    *q = *w;
    *w = temp;
    printf("Swap by pointer : %d %d\n",*q,*w);
}

int main(){
    int ary[3] = {0};

    scanf("%d %d",&ary[0],&ary[1]);
    printf("Before Swap : %d %d\n",ary[0],ary[1]);

    Swap(ary[0],ary[1]);

    scanf("%d %d",&ary[2],&ary[3]);
    printf("Before Swap : %d %d\n",ary[2],ary[3]);

    SwapPointer(&ary[2],&ary[3]);

    return 0;
}