#include <iostream>
#include <cstring>
using namespace std;

int top;
int S[100];

int pop(){
    int x = S[top];
    top--;
    return x;
}

void push(int x){
    top ++;
    S[top] = x;
}


int main(){
    int a,b;
    top = 0;
    char s[100];
    while (!cin.eof()){
        cin >> s;
        if (s[0] == '+'){
            a = pop();
            b = pop();
            push(b + a);
        }
        else if (s[0] == '-'){
            a = pop();
            b = pop();
            push(a - b);
        }
        else if (s[0] == '*'){
            a = pop();
            b = pop();
            push(b * a);
        }
        else{
            push(atoi(s));
        }
    }

    cout << pop() << endl;

    return 0;
}