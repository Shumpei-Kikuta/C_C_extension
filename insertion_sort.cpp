#include <iostream>
using namespace std;

// prototype declarelation
void insertion_sort(int *lists, int N);
void bubble_sort(int *lists, int N);
int selection_sort(int *lists, int N);
void input_lists(int *lists, int N);
void print_lists(int *lists, int N);

int selection_sort(int *lists, int N){
    int score = 0;
    for (int i = 0; i < N; i++){
        int min = lists[i];
        int min_element = i;
        bool flag = false;
        for (int j = i; j < N; j++){
            if (min > lists[j]){
                min_element = j;
                min = lists[j];
                flag = true;
            }
        }
        if (flag){
                int tmp = lists[i];
                lists[i] = lists[min_element];
                lists[min_element] = tmp;
                score++;
            }
    }
    return score;
}


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

void bubble_sort(int *lists, int N){
    bool flag = true;
    int score = 0;
    while (flag){
        flag = false;
        for (int i = N - 1; i > 0; i--){
            if (lists[i] < lists[i - 1]){
                flag = true;
                int tmp = lists[i];
                lists[i] = lists[i - 1];
                lists[i - 1] = tmp;
                score += 1;
            }
        }
    }
    print_lists(lists, N);
    cout << "\n";
    cout << score << endl;
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
        if (i) cout << " ";
        cout << lists[i];
    }
    cout << "\n";
}

int main(){
    int N;
    cin >> N;
    int *lists;
    lists = new int[N];
    input_lists(lists, N);
    int score = selection_sort(lists, N);
    print_lists(lists, N);
    cout << score << endl;
    delete[] lists;
    return 0;
}