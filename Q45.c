#include<stdio.h>

int main(){
    int i , n ;
    float d = 3.0 , sum = 0.0;
    printf("ENTER THE TERM : ");
    scanf("%d" , &n);
    for(i=1;i<=n;i++){
        sum += (float)((2.0*i)/d);
         d = d + 4.0 ;
    }
    printf("THE SUM UPTO %d TERMS IS %.2f" , n , sum);
    return 0;
}