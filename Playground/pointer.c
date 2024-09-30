#include <stdio.h>

int main(){
    int *y;
    *y = 10;
    int *z = &y;
    printf("*y = %d\n", *y);
    printf("y = %d\n", y);
    printf("&y = %d", &y);
    printf("*z = \n", *z);
    printf("z = %d\n", z);

    return 0;
}