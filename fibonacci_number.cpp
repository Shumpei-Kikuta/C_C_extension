#include <iostream>
using namespace std;
#define MAX 45

int calculate_fibonach(int n, int *F){
    if (n == 0 || n == 1){
        return F[n];
    }
    else{
        return calculate_fibonach(n - 1, F) + calculate_fibonach(n - 2, F);
    }
}

int main(){
    int n;
    cin >> n;
    int F[MAX];
    F[0] = 1;
    F[1] = 1;
    int fib_n = calculate_fibonach(n, F);
    cout << fib_n;
    return 0;
}