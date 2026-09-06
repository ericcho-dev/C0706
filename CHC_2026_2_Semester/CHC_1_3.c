#include <stdio.h>

const double pi = 3.14;

double FindExtent(int s){
    double extent = 0;
    extent = pi*s*s;
    return extent;
}
double FindCircum(int q){
    double circum = 0;
    circum = 2*pi*q;
    return circum;
}

int main(){
    int a=0;
    printf("Enter the radius :\n");
    scanf("%d",&a);
    printf("Entered radius : %d\n",a);
    printf("The extent is %.6f\n",FindExtent(a));
    printf("The circumference is %.6f",FindCircum(a));

    return 0;
}