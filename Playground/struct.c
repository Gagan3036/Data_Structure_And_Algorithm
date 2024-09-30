#include<stdio.h>

int main(){
    int x=10;
    int *y = &x;
    printf("x = %d\n", x);
    printf("&x = %u\n", &x);
    printf("y = %u\n", y);
    printf("*y = %d\n", *y);
    printf("&y = %u", &y);
    
    return 0;
}