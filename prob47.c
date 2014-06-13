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

int numPrimeFactors(uint64_t n){
    uint64_t i = 0;
    int count = 0;
    for(i=0; i<my_index && n>primes[i]; i++){
        if(n%primes[i]==0){
            count++;
        }
    }
    //printf("%d\n", count);
    return count;
}

void printPrimefactors(uint64_t n){
    uint64_t i = 0;
    int count = 0;
    printf("%d: ", n);
    for(i=0; i<my_index && n>primes[i]; i++){
        if(n%primes[i]==0){
            printf("%d ", primes[i]);
            count++;
        }
    }
    printf(" (%d)\n", count);
}

int main(){
    uint64_t i = 0, n = 1000000;
    int req = 4;
    uint64_t array[req];
    prime_size = n;
    primes = (uint64_t*) malloc(prime_size*sizeof(uint64_t));
    generate_primes( prime_size );
    int j = 0;

    for(i=0; i<req; i++){
        array[i] = 0;
    }

    for( i=646; i<n; i++ ){
        array[0] = array[1];
        array[1] = array[2];
        array[2] = array[3];
        array[3] = numPrimeFactors(i);

        if(array[1]==req && array[0]==req && array[2]==req && array[3]==req){
            break;
        }
    }

    printf("%" PRIu64 "\n", i-3);


    return 0;
}
