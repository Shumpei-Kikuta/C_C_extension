#include <iostream>
using namespace std;
#include <string.h>
#include <algorithm>
#include <vector>
#define MAX 1001

int matching(string X, string Y, int n, int m, vector<vector<int> > &rc){
    if (n == 0 || m == 0){
        rc[n][m] = 0;
    }
    else if (X[n] == Y[m]){
        rc[n][m] = matching(X, Y, n - 1, m - 1, rc) + 1;
    }
    else if (X[n] != Y[m]){
        rc[n][m] = max(matching(X, Y, n - 1, m, rc), matching(X, Y, n, m - 1, rc));
    }
    return rc[n][m];
}

int main(){
    int q, n, m;
    string input;
    string X, Y;
    vector<vector<int> > c;
    vector<vector<int> > & rc = c;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> X;
        n = X.length();
        X = ' ' + X;
        cin >> Y;
        m = Y.length();
        Y = ' ' + Y;
        c.resize(n + 1);
        for (int i = 0; i <= n; i++){
            c[i].resize(m + 1);
        }
        cout << matching(X, Y, n, m, rc) << endl;
    }
    return 0;
}