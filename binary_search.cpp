#include <iostream>
#include <vector>
using namespace std;

void input_dispose(int *n, int *q, vector<int> &S, vector<int> &T){
    cin >> *n;
    for (int i = 0; i < *n; i++){
        int element;
        cin >> element;
        S.push_back(element);
    }
    cin >> *q;
    for (int i = 0; i < *q; i++){
        int element;
        cin >> element;
        T.push_back(element);
    }
}

bool binary_search(vector<int> rS, int left, int right, int t){
    while (left < right){
        int median = (left + right) / 2;
        if (t == rS[median]){
            return true;
        }else if (t < rS[median]){
            right = median;
        }
        else{
            left = median + 1;
        }
    }
    return false;
}
int main(){
    int n, q;
    vector<int> S, T;
    vector<int> &rS = S;
    vector<int> &rT = T;
    input_dispose(&n, &q, rS, rT);
    int count = 0;
    for (int i = 0; i < q; i++){
        int left = 0;
        int right = n;
        if (binary_search(rS, left, right, rT[i])){
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}