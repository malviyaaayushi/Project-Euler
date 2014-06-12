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
    uint64_t size = factorial(n), i = 0, sum = 0;
    pandigitals = (uint64_t*) malloc(size*sizeof(uint64_t));
    getPandigitals(n);
    uint64_t mod2 = pow(10, 2);
    uint64_t mod3 = pow(10, 3);
    uint64_t mod4 = pow(10, 4);
    int rec[mod4-mod3];
    for(i=0; i<mod4-mod3; i++){
        rec[i] = 0;
    }
    for(i=0; i<size; i++){
        if( (pandigitals[i]%mod4 == ((pandigitals[i]/(mod4*mod3))%mod2)*((pandigitals[i]/mod4)%mod3) ) //){
            &&  rec[pandigitals[i]%mod4 - mod3]==0 ){
            printf("%" PRIu64 " ""%" PRIu64 " ""%" PRIu64 " ""%" PRIu64 "\n", pandigitals[i]%mod4, ( (pandigitals[i]/(mod4*mod3))%mod2 )*( (pandigitals[i]/mod4)%mod3 ), ( (pandigitals[i]/mod4)%mod3 ), ( (pandigitals[i]/(mod4*mod3))%mod2 ));
            sum += (pandigitals[i]%mod4);
            rec[pandigitals[i]%mod4 - mod3] = 1;
        }
        if( (((pandigitals[i]/(10*mod4))%mod4) == (pandigitals[i]%10)*((pandigitals[i]/10)%mod4) ) //){
            &&  rec[((pandigitals[i]/(10*mod4))%mod4) - mod3]==0 ){
            printf("%" PRIu64 " ""%" PRIu64 " ""%" PRIu64 " ""%" PRIu64 "\n", pandigitals[i]%mod4, ( (pandigitals[i]/(mod4*mod3))%mod2 )*( (pandigitals[i]/mod4)%mod3 ), ( (pandigitals[i]/mod4)%mod3 ), ( (pandigitals[i]/(mod4*mod3))%mod2 ));
            sum += ((pandigitals[i]/(10*mod4))%mod4);
            rec[((pandigitals[i]/(10*mod4))%mod4) - mod3] = 1;
        }
    }
    printf("%" PRIu64 "\n", sum);
    return 0;
}
