#include <iostream>
#include <vector>
using namespace std;

void input_dispose(long int *N, vector<long int> &rS){
    cin >> *N;
    for (long int i = 0; i < *N; i++){
        long int element;
        cin >> element;
        rS.push_back(element);
    }
}

void test_input_dispose(long int N, vector<long int> &rS){
    for (long int i = 0; i < N; i++){
        cout << rS[i];
    }
}

void merge(vector<long int> &rS, long int left, long int mid, long int right, long int *pmerge_num){
    vector<long int> L, R;
    for (long int i = left; i < mid; i++){
        L.push_back(rS[i]);
    }
    for (long int j = mid; j < right; j++){
        R.push_back(rS[j]);
    }
    L.push_back(10000000000);
    R.push_back(1000000000);
    long int li, ri;
    li = 0;
    ri = 0;
    for (long int i = left; i < right; i++){
        *pmerge_num += 1;
        if (L[li] < R[ri]){
            rS[i] = L[li];
            li++;
        }
        else{
            rS[i] = R[ri];
            ri++;
        }
    }
}

void merge_sort(vector<long int> &rS, long int left, long int right, long int *pmerge_num){
    if (left < right - 1){
        long int mid = (left + right) / 2;
        merge_sort(rS, left, mid, pmerge_num);
        merge_sort(rS, mid, right, pmerge_num);
        merge(rS, left, mid, right, pmerge_num);
    }
}

void conquer_divide(vector<long int> &rS){
    long int left = 0;
    long int right = rS.size();
    long int merge_num = 0;
    long int *pmerge_num = &merge_num;
    merge_sort(rS, left, right, pmerge_num);
    for (long int i = 0; i < rS.size(); i++){
        cout << rS[i];
        if (i != rS.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
    cout << merge_num << endl;
}

int main(){
    long int N;
    vector<long int> S;
    vector<long int> &rS = S;
    input_dispose(&N, rS);
    // test_input_dispose(N, rS);
    conquer_divide(rS);
    return 0;
}