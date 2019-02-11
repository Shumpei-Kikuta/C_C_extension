#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

int main(){
    int n, left, right;
    cin >> n;
    vector<int> L;
    for (int i = 0; i < n; i++){
        cin >> left >> right;
        if(i == 0){
            L.push_back(left);
        }
        L.push_back(right);
    }
    vector<vector<int> > M;
    M.resize(n - 1);
    for (int i = 0; i < n - 1; i++){
        M[i].resize(n);
        if (i == 0){
            for (int j = 0; j < n - 1; j++){
                M[i][j] = L[j] * L[j + 1] * L[j + 2];
            }
        }
        else{
            for (int j = 0; j < n - 1 - i; j++){
                M[i][j] = min(M[i - 1][j] * L[i + j + 2], M[i - 1][j + 1] * L[j]);
            }
        }
    }
    cout << M[n - 2][0] << endl;
    return 0;
}