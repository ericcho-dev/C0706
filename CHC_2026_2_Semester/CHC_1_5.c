#include <stdio.h>

void sort_Ascending(int* arr){
    for(int i=0;i<99;i++){
        for(int j = 0; j<99-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<100;i++){
        printf("%d ",arr[i]);
    }
}

void sort_Descending(int* arr){
    for(int i=0;i<99;i++){
        for(int j=0;j<99-i;j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<100;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[100];
    for(int i=0;i<100;i++){
        arr[i] = 100 - i;
    }
    int a=0;
    printf("Enter the number : 1(Ascending) / 2(Descending)\n");
    scanf("%d",&a);
    if(a==1){
        sort_Ascending(arr);
    }
    else if(a==2){
        sort_Descending(arr);
    }
    else{
        printf("ERROR\n");
    }
    return 0;
}