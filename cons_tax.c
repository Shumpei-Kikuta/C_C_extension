#include <stdio.h>

int main(){
    int water = 198;
    int milk = 138;
    int sum;
    sum = water + 2 * milk;
    int payment;
    payment = (int)(sum * 1.05);
    int charge;
    charge = 1000 - payment;
    printf("You get %d yen\n", charge);
    

    return 0;
}