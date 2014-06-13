#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

int array[10];

int sameNumbers(uint64_t num1, uint64_t num2){
    int i = 0;
    for(i=0; i<10; i++){
        array[i] = 0;
    }
    while(num1>0){
        array[num1%10]++;
        num1 /= 10;
    }
    while(num2>0){
        array[num2%10]--;
        num2 /= 10;
    }
    for(i=0; i<10; i++){
        if(array[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int i = 0;
    //printf("%d\n", sameNumbers(2314, 53214));
    while(1){
        i++;
        if( sameNumbers(i, 2*i) && sameNumbers(i, 3*i) && sameNumbers(i, 4*i) && sameNumbers(i, 5*i) && sameNumbers(i, 6*i) ){
            break;
        }
    }
    printf("%d\n", i);
    return 0;
}
