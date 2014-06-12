#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

uint64_t* pandigitals;
uint64_t* primes;
uint64_t* prime_rec;
uint64_t* rec;

uint64_t my_index;
uint64_t prime_size;

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
        if(n < prime_size){
            prime_rec[n] = 1;
        }
    }
    return eligible;
}

uint64_t factorial(int n){
    if (n<=1){
        return 1;
    }
    return n*factorial(n-1);
}

void getPandigitals(int n){
    if(n==1){
        pandigitals[0] = 1;
        return;
    }
    int i = 0;
    uint64_t size = factorial(n-1), j = 0;
    uint64_t count = 0; // to keep track of the pandigitals' array size
    uint64_t mul = 1; //to switch the position of n in newly generated pandigitals
    uint64_t temp[size];
    // copy all the previous entires in a temporary array
    getPandigitals(n-1);
    for(j=0; j<size; j++){
        temp[j] = pandigitals[j];
    }
    for(i=0; i<n; i++){
        //generate new numbers by appending 'n' & switching its position
        for(j=0; j<size; j++){
            pandigitals[count++] = (temp[j]/(mul))*(mul*10) + (temp[j]%mul) + n*mul;
        }
        mul *= 10;
    }
}

void generate_primes(int n){
    primes[my_index++] = 2;
    uint64_t i = 3;
    int count = 0;
    while(count<n){
        if(isPrime(i)){
            rec[count] = 0;
            count++;
        }
        i += 2;
    }
}

int main(){
    int n = 9;
    uint64_t size = factorial(n), i = 0, num = 0;
    prime_size = pow(10, 4);
    pandigitals = (uint64_t*) malloc(size*sizeof(uint64_t));
    primes = (uint64_t*) malloc(prime_size*sizeof(uint64_t));
    prime_rec = (uint64_t*) malloc(prime_size*sizeof(uint64_t));
    rec = (uint64_t*) malloc(prime_size*sizeof(uint64_t));

    for(i=0; i<prime_size; i++){
        prime_rec[i] = 0;
        rec[i] = 0;
    }

    generate_primes(prime_size);

    getPandigitals(n);

    for(i=0; i<size; i++){
        //printf("%" PRIu64 "\n", pandigitals[i]);
        num = pandigitals[i]%10000;
        if(!rec[num] && prime_rec[num]){
            rec[num] = 1;
            printf("%" PRIu64 "\n", num);
        }
    }

    return 0;
}
