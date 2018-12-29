#include <stdio.h>

int main(){
    int input_list[10];
    for (int i = 0; i < 10; i++){
        scanf("%d\n", &input_list[i]);
    }
    for (int i = 9; i >= 0; i--){
        printf("%d\n", input_list[i]);
    }
    return 0;
}