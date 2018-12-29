#include <stdio.h>

void read_print(void){
    FILE *f;
    f = fopen("test.txt", "r");
    char string[12];
    fscanf(f, "%s", string);
    printf("%s\n", string);
}

int main(){
    FILE *f;
    f = fopen("test.txt", "w");
    char string[] = "HelloWorld";
    fprintf(f, "%s", string);
    fclose(f);
    read_print();
    return 0;
}