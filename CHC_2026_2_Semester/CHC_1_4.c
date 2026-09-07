#include <stdio.h>

void FindDecimal(int* arr){
    for(int i=0;i<29;i++){
        if(arr[i] != 0){
            for(int j= i+arr[i];j<29; j+= arr[i]){
                arr[j] = 0;
            }
        }
    }
}
int main(){

    int ary[30] = {0};
    for(int i=0;i<29;i++){
        ary[i] = i+2;
    }

    FindDecimal(ary);

    for(int i=0;i<29;i++){
        if(ary[i] != 0){
            printf("%d ",ary[i]);
        }
    }
}