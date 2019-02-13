#include <iostream>
using namespace std;
#define MAX 2000000
#include <algorithm>
 
void maxheapify(int *tree, int *pnum, int i){
    int left, right, largest;
    left = 2 * i;
    right = 2 * i + 1;
    if (left <= *pnum && tree[left] > tree[i]){
        largest = left;
    }else{
        largest = i;
    }
    if (right <= *pnum && tree[right] > tree[largest]){
        largest = right;
    }
    if (largest != i){
        int tmp = tree[largest];
        tree[largest] = tree[i];
        tree[i] = tmp;
        maxheapify(tree, pnum, largest);
    }
}

 
void insert(int *tree, int element, int *pnum){
    *pnum += 1;
    tree[*pnum] = element;
    int i = *pnum;
    while (i > 1 && tree[i / 2] < tree[i]){
        int tmp = tree[i];
        tree[i] = tree[i / 2];
        tree[i / 2] = tmp;
        i = i / 2;
        }
    }
 
void extract(int *tree, int *pnum){
    int minimum = *pnum;
    if (minimum <= 0){
        cout << "under flow\n";
    }
    else{
        cout << tree[1] << endl;
        tree[1] = tree[*pnum];
        *pnum -= 1;
        maxheapify(tree, pnum, 1);
    }
}
 
int main(){
    int tree[MAX];
    string command;
    int element;
    int num = 0;
    int *pnum = &num;
    while(true){
        cin >> command;
        if (command == "end"){
            break;
        }
        else if(command == "insert"){
            cin >> element;
            insert(tree, element, pnum);
        }
        else{
            extract(tree, pnum);
        }
    }
    return 0;
}