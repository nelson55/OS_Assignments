//Part 2: Phi Function

#include <stdio.h>
#include <math.h>

//Calculate the greatest common denominator of a given value
int gcd(int a, int b){
    if(a == 0){
        return b;
    } else {
        return gcd(b%a, a);
    }
}

//Calculate the Phi number for a given number
int phi(int n){

    int res = 1;

    for(int i=2; i < n; i++){
        if(gcd(i, n) == 1){
            res++;
        }
    }
    return res;
}

int main(){
    
     

    //printf("phi(%d) = %d\n", n, phi(n));
}

