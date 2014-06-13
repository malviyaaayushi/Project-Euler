#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>
#include<inttypes.h>

uint64_t combination(int n, int r){
    uint64_t ans = 1;
    int i = 0;
    r = (r > (n-r))? r : (n-r);
    for(i=0; i<r; i++){
        ans *= (n-i);
    }
    for(i=0; i<r; i++){
        ans /= (i+1);
    }
    return ans;
}

int main(){
    int i = 0, n = 100, j = 0, r = 0;
    int count = 0, final_count = 0;
    uint64_t num = 0;
    for(i=23; i<=n; i++){
        count = 0;
        //r = (i%2==1)? (i+1)/2 : i/2;
        r = i;
        for(j=1; j<=r && j<i; j++){
            num = combination(i, j);
            //printf("%" PRIu64 "\n", num);
            if( num > 1000000 ){
                count++;
                printf("%" PRIu64 "\n", num);
            }
        }
        final_count += count;
    }

    printf("%d\n", final_count);

    return 0;
}
