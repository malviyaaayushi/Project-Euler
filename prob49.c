#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

uint64_t* pandigitals;

uint64_t factorial(int n){
    if (n<=1){
        return 1;
    }
    return n*factorial(n-1);
}

void getPandigitals(int n, int* set){
    if(n==1){
        pandigitals[0] = set[0];
        return;
    }
    int i = 0;
    uint64_t size = factorial(n-1), j = 0;
    uint64_t count = 0; // to keep track of the pandigitals' array size
    uint64_t mul = 1; //to switch the position of n in newly generated pandigitals
    uint64_t temp[size];
    // copy all the previous entires in a temporary array
    getPandigitals(n-1, set);
    for(j=0; j<size; j++){
        temp[j] = pandigitals[j];
    }
    for(i=0; i<n; i++){
        //generate new numbers by appending 'n' & switching its position
        for(j=0; j<size; j++){
            pandigitals[count++] = (temp[j]/(mul))*(mul*10) + (temp[j]%mul) + set[n-1]*mul;
        }
        mul *= 10;
    }
}

int main(){
    int n = 4;
    uint64_t size = factorial(n), i = 0;
    pandigitals = (uint64_t*) malloc(size*sizeof(uint64_t));
    int set[4];
    set[0] = 1;
    set[1] = 2;
    set[2] = 8;
    set[3] = 7;
    getPandigitals(n, set);
    for(i=0; i<size; i++){
        printf("%" PRIu64 "\n", pandigitals[i]);
    }
    return 0;
}
