#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

uint64_t factorial(int n){
    if (n<=1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    uint64_t i = 0, n = 0;
    uint64_t factorials[10];
    for(i=0; i<10; i++){
        factorials[i] = factorial(i);
        //printf("%" PRIu64 "\n", factorials[i]);
    }
    uint64_t super_sum = 0, sum = 0;
    for(i=10; i<7*factorials[9]; i++){
        sum = 0;
        n = i;
        while(n>0){
            sum += factorials[n%10];
            if(sum>i){
                break;
            }
            n /= 10;
        }
        if( sum == i ){
            super_sum += i;
            printf("%" PRIu64 "\n", i);
        }
    }
    printf("Sum = %" PRIu64 "\n", super_sum);
    return 0;
}
