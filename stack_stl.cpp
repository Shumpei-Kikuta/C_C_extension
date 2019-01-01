#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int main(){
    stack<int> S;
    int a, b, x;
    string s;

    while (cin >> s){
        if (s[0] == '+'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            x = a + b;
            S.push(x);
        }
        else if(s[0] == '-'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            x = b - a;
            S.push(x);
        }
        else if (s[0] == '*'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            x = b * a;
            S.push(x);
        }
        else{
            S.push(atoi(s.c_str()));
        }
    }
    cout << S.top() << endl;
}