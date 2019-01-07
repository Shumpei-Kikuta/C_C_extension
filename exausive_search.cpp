# include <iostream>
# include <vector>
using namespace std;

void input_dispose(int *n, int *q, vector<int> &rA, vector<int> &rM){
    cin >> *n;
    int element;
    for (int i = 0; i < *n; i++){
        cin >> element;
        rA.push_back(element);
    }
    cin >> *q;
    for (int i = 0; i < *q; i++){
        cin >> element;
        rM.push_back(element);
    }
}

void test_input_dispose(int n, int q, vector<int> &rA, vector<int> &rM){
    for (int i = 0; i < n; i ++){
        cout << rA[i] << endl;
    }
    for (int i = 0; i < q; i ++){
        cout << rM[i] << endl;
    }
}

void initialize_vector(int n, vector<int> &rS){
    for(int i = 0; i < n; i++){
        rS.push_back(0);
    }
}

void test_initialize_vector(int n, vector<int> &rS){
    for(int i = 0; i < n; i++){
        cout << rS[i] << endl;
    }
}

int generate(int n, vector<int> &rS, vector<int> &rA){
    int sum = 0;
    for (int j = 0; j < n; j++){
        if (rS[j] == 0){
            continue;
        }
        else{
            sum += rA[j];
        }
    }
    return sum;
}

void solve_conquer_divide(int i, int n, vector<int> &rA, vector<int> &rS, vector<int> &rSum){
    // generate bit sequence
    // make summation
    if (i == n){
        int sum = generate(n, rS, rA);
        rSum.push_back(sum);
    }
    else{
        rS[i] = 0;
        solve_conquer_divide(i+1, n, rA, rS, rSum);
        rS[i] = 1;
        solve_conquer_divide(i+1, n, rA, rS, rSum);
    }
}

void test_solve_conquer_divide(vector <int> &rSum){
    int size = rSum.size();
    for (int i = 0; i < size; i++){
        cout << rSum[i] << endl;
    }
}

bool linear_search(vector<int> &rSum, int t){
    int n = rSum.size();
    rSum[n] = t;
    // cout << t << endl;
    int i = 0;
    while (rSum[i] != t){
        i++;
    }
    if (i == n){
        return false;
    }
    else{
        return true;
    }
}

void try_on(int q, vector<int> &rM, vector<int> &rSum){
    // try assign all of q and check if you get the same value
    for (int i = 0; i < q; i++){
        int t = rM[i];
        if (linear_search(rSum, t)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}

int main(){
    int n, q, i;
    i = 0;
    vector<int> A, M, S, Sum;
    vector<int> &rA = A;
    vector<int> &rM = M;
    vector<int> &rS = S;
    vector<int> &rSum = Sum;

    input_dispose(&n, &q, rA, rM);
    // test_input_dispose(n ,q, rA, rM);
    initialize_vector(n, rS);
    // test_initialize_vector(n, rS);
    solve_conquer_divide(i, n, rA, rS, rSum);
    // test_solve_conquer_divide(rSum);
    try_on(q, rM, rSum);
    return 0;
}