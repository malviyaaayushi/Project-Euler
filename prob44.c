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

int main(){

    uint64_t i = 0, j = 1, num1 = 0, num2 = 0, num3 = 0;
    int found = 0;
    //printf("%d", isPentagonal(22));
    while(!found){
        i++;
        num1 = i * (3*i - 1)/2;
        for(j=1; j<i; j++){
            num2 = j * (3*j - 1)/2;
            num3 = num1 + num2;
            num2 = num1 - num2;
            //printf("%" PRIu64 " ""%" PRIu64 " ""\n", num3, num2);
            if(num2 < 0){
                num2 *= -1;
            }
            if(isPentagonal(num3) && isPentagonal(num2)){
                printf("ans = ""%" PRIu64 "\n", num2);
                found = 1;
                break;
            }
        }
    }

    return 0;
}
