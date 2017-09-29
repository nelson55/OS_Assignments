//Part 2: Phi Function

#include <stdio.h>
#include <string.h>

int array[100] = {1,2};

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

//Function to get ints from the input string and calulate the Phi value
void strToPhi(char *str){
    int n, i = 0, length;

    while(sscanf(str, "%d%n", &n, &length) == 1) {
        printf("Phi of %d is %d\n", n, phi(n));
        str += length;
        i++;
    }
}

int main(){

    char input[100];
    
    printf("Enter a list of positive integers, separated by spaces: ");
    fgets(input, 100, stdin);
    strToPhi(input);
    
    return 0;
}