#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

uint64_t prime_size;
uint64_t my_index;

uint64_t* primes;

int isPrime(uint64_t n){
    if(n==1){
        return 0;
    }
    uint64_t i = 0;
    int eligible = 1;
    uint64_t bound = pow(n, 0.5) + 1;
    for(i=0; primes[i]<=bound && n>primes[i] && i<my_index; i++){
        if(n%primes[i]==0){
            eligible = 0;
            break;
        }
    }
    if(eligible){
        primes[my_index++] = n;
    }
    return eligible;
}

int isRightTruncatable(uint64_t n){
    int is_it = 1;
    while(n>0){
        if( ! isPrime(n) ){
            is_it = 0;
            break;
        }
        n /= 10;
    }
    return is_it;
}

int isLeftTruncatable(uint64_t n){
    int is_it = 1;
    int len = 0, i=0;
    uint64_t num_cpy = n;
    while(num_cpy>0){
        len++;
        num_cpy /= 10;
    }
    uint64_t mul = 1;
    for(i=0; i<len; i++){
        mul *= 10;
    }
    while(mul>0 && n>0){
        if( ! isPrime(n) ){
            is_it = 0;
            break;
        }
        mul /= 10;
        n = n%mul;
    }
    return is_it;
}

int main(){
    uint64_t i = 2;
    int count = 0;
    uint64_t sum = 0;
    prime_size = 1000000;
    primes = (uint64_t*) malloc(prime_size*sizeof(uint64_t));
    primes[my_index++] = 2;
    while(count<11 && i<prime_size){
        i++;
        if( isPrime(i)){
            if ( i>10 && isRightTruncatable(i) && isLeftTruncatable(i) ){
                count++;
                printf("%" PRIu64 "\n", i);
                sum += i;
            }
        }
    }
    if(i>=prime_size){
        printf("Increase prime size\n");
    }else{
        printf("\nsum = %" PRIu64 "\n", sum);
    }
printf("\nsum = %" PRIu64 "\n", sum);
    return 0;
}




