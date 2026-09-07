#include <stdio.h>
#include <string.h>

int input_char(char* arr){
    char c;
    for(int i=0;i<100;i++){
        scanf("%c",&c);
        if(c == '\n'){
            arr[i] = '\0';
            break;
        }
        arr[i] = c;
    }  
    char d[20];
    printf("Enter Ascend or Descend\n");
    scanf("%s",d);

    if(strcmp(d,"Ascend") == 0){
        return 1;
    }
    else if(strcmp(d,"Descend") == 0){
        return 2;
    }
    else{
        return 0;
    }
   
}

void func_sort(char* arr, int b){
    int len = strlen(arr);
    if(b==1){
        for(int i=0;i<len;i++){
            for(int j=0;j<len-i-1;j++){
                if(arr[j] > arr[j+1]){
                    char temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    else if(b==2){
        for(int i=0;i<len;i++){
            for(int j=0;j<len-i-1;j++){
                if(arr[j] < arr[j+1]){
                    char temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

    }
}
void func_print(char* arr){
    for(int i=0;arr[i] != '\0';i++){
        printf("%c",arr[i]);
    }
}

int main(){
    char arr[100] = {0};
   
    int t = input_char(arr);

    
    func_sort(arr,t);
    func_print(arr);
    return 0;


}