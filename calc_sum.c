#include <stdio.h>

int main(){
    int input1, input2, sum;
    printf("Enter two integer values as follows\n");
    scanf("%d%d", &input1, &input2);
    sum = (input1 + input2) * (input2 - input1 + 1) / 2;
    printf("The sum between %d and %d is %d\n", input1, input2, sum);
    return 0;
}