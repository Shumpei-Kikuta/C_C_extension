#include <stdio.h>

int main(){
    int water = 198;
    int milk = 138;
    int sum, payment, charge;
    sum = water + 2 * milk;
    payment = (int)(sum * 1.05);
    charge = 1000 - payment;
    printf("You get %d yen\n", charge);
    

    return 0;
}