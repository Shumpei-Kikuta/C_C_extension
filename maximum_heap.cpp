#include <iostream>
using namespace std;
#define MAX 500001

void maxHeapify(int *tree, int i, int n){
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;
    if (left <= n && tree[left] > tree[i]){
        largest = left;
    }else{
        largest = i;
    }
    if (right <= n && tree[right] > tree[largest]){
        largest = right;
    }

    if (largest != i){
        int tmp = tree[largest];
        tree[largest] = tree[i];
        tree[i] = tmp;
        maxHeapify(tree, largest, n);
    }

}

void buildMaxHeap(int *tree, int n){
    for (int i = n/2; i > 0; i--){
        maxHeapify(tree, i, n);
    }
}

int main(){
    int n, element;
    cin >> n;
    int tree[MAX];
    for (int i = 1; i <= n; i++){
        cin >> element;
        tree[i] = element;
    }
    buildMaxHeap(tree, n);
    for (int i = 1; i <= n; i++){
        cout << " " << tree[i];
    }
    cout << endl;
    return 0;
}