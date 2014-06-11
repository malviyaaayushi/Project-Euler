#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

int isPentagonal(uint64_t n){
    if (n < 0)
        return 0;
    double i = (sqrt(24*n+1) + 1)/6;
    return i == (int) i;
}

int isHexagonal(uint64_t n){
    if (n < 0)
        return 0;
    double i = (sqrt(8*n+1) + 1)/4;
    return i == (int) i;
}

int main(){

    uint64_t i = 0, j = 0, num1 = 0, num2 = 0;
    int found = 0;
    i = 285;
    //printf("%d", isPentagonal(22));
    while(!found){
        i++;
        num1 = i * (i + 1)/2;
        printf("%d\n", num1);
        if(isPentagonal(num1) && isHexagonal(num1)){
            printf("ans = %d\n", num1);
            found = 1;
            break;
        }
    }

    return 0;
}
