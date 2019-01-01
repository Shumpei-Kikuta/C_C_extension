#include <iostream>
using namespace std;

// insertion sort
void insertion_sort(int *lists, int N){
    for (int i = 1; i < N; i++){
        int v = lists[i];
        int j = i - 1;
        while ((j >= 0) & (lists[j] > v)){
            lists[j + 1] = lists[j];
            j--;
        }
        lists[j + 1] = v;
    }
}

// input lists
void input_lists(int *lists, int N){
    for (int i = 0; i < N; i++){
        cin >> lists[i];
    }
}

// print list and add space between each element
void print_lists(int *lists, int N){
    for (int i = 0; i < N; i++){
        cout << lists[i];
        cout << " ";
    }
}

int main(){
    int N;
    cin >> N;
    int *lists;
    lists = new int[N];
    input_lists(lists, N);
    insertion_sort(lists, N);

    print_lists(lists, N);
    delete[] lists;
    return 0;
}