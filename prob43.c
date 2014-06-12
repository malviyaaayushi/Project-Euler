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

int main(){
    int n = 9;
    uint64_t size = factorial(n+1), i = 0, temp_size = factorial(n);
    pandigitals = (uint64_t*) malloc(size*sizeof(uint64_t));
    getPandigitals(n);

    // all this crap is just to add zero also -_-
    uint64_t* temp = (uint64_t*) malloc(temp_size*sizeof(uint64_t));
    for(i=0; i<temp_size; i++){
        temp[i] = pandigitals[i];
    }
    uint64_t count = 0, j = 0, mul = 1;
    for(i=0; i<10; i++){
        //generate new numbers by appending 'n' & switching its position
        for(j=0; j<temp_size; j++){
            pandigitals[count++] = (temp[j]/(mul))*(mul*10) + (temp[j]%mul);
        }
        mul *= 10;
    }

    int array[7];
    array[0] = 17;
    array[1] = 13;
    array[2] = 11;
    array[3] = 7;
    array[4] = 5;
    array[5] = 3;
    array[6] = 2;

    int mod = 1000, eligible = 0;

    uint64_t num = 0, sum = 0;

    for(i=0; i<size; i++){
        // printf("%" PRIu64 "\n", pandigitals[i]);
        num = pandigitals[i];
        eligible = 1;
        for(j=0; j<7; j++){
            if( (num%mod)%array[j] != 0){
                eligible = 0;
                break;
            }
            num /= 10;
        }

        if(eligible){
            sum += pandigitals[i];
        }
    }

    printf("%" PRIu64 "\n", sum);

    return 0;
}
