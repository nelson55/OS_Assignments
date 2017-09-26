//Part 1: Armstrong Numbers

#include <stdio.h>
#include <math.h>

int checkArmstrong(int number, int order);
int power(int n, int r);

int main(){

    int k; //Order of Armstrong number
    int p; //Range low value
    int q; //Range high value

    int i;

    printf("Enter k: ");
    scanf("%d", &k);
    printf("\nEnter p: ");
    scanf("%d", &p);
    printf("\nEnter q: ");
    scanf("%d", &q);

    printf("\nk is %d \np is %d \nq is %d", k,p,q);

    //Check every number between the given numbers p and q
    for(i = p + 1; i < q; ++i){
        if(checkArmstrong(i, k) == 1){
            printf("\n%d", i);
        } 
    }
}

//Function to check if a given number is an Armstrong number using the given order
int checkArmstrong(int number, int order){

    int sum = 0, remainder, temp;

    temp = number;
        
    while(temp != 0){
        remainder = temp%10;
        sum = sum + power(remainder, order);
        temp = temp/10;
    }

    if(number == sum){
        return 1;
    } else {
        return 0;
    }

}

//power function for integers
int power(int n, int r) {
   int c, p = 1;
 
   for (c = 1; c <= r; c++) 
      p = p*n;
 
   return p;   
}