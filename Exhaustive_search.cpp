#include <iostream>
using namespace std;
#define MAX_N 21
#define MAX_M 2001

int n;
int A[MAX_N];
int q;
bool dp[MAX_N][MAX_M];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }
    // initialize
    dp[0][0] = true;
    for (int i = 1; i < MAX_M; i++){
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < MAX_M; j++){
            if (j < A[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - A[i]];
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++){
        int mi;
        cin >> mi;
        if (dp[n][mi]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}