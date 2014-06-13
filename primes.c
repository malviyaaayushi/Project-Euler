#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

uint64_t prime_size;
uint64_t my_index;

uint64_t* primes;

int isPrime(uint64_t n){
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

void generate_primes(uint64_t n){
    my_index = 0;
    primes[my_index++] = 2;
    uint64_t i = 3;
    while(i<=n){
        if(isPrime(i)){
                // do nothing
                //printf("%" PRIu64 "\n", i);
        }
        i += 2;
    }
}

int main(){
    prime_size = 1;
    primes = (uint64_t*) malloc(prime_size*sizeof(uint64_t));

    generate_primes(prime_size);
    return 0;
}
