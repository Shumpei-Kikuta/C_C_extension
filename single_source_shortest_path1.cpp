#include <iostream>
using namespace std;
#define MAX 100
#define inf 1000000

int n;
int d[MAX];
int adj_matrix[MAX][MAX];
int already[MAX] = {};

bool is_all_one(){
    for (int i = 0; i < n; i++){
        if (already[i] == 0){
            return false;
        }
    }
    return true;
}

void dijkstra(){
    if (is_all_one()){
        return;
    }else{
        int to_node = n;
        int minimum = inf;
        for (int j = 0; j < n; j++){
            if (already[j] != 1 && d[j] < minimum){
                to_node = j;
                minimum = d[j];
            }
        }
        already[to_node] = 1;
        for (int j = 0; j < n; j++){
            // if (d[j] > d[to_node] + adj_matrix[to_node][j]){
            if (already[j] != 1 && d[j] > d[to_node] + adj_matrix[to_node][j]){
                d[j] = d[to_node] + adj_matrix[to_node][j];
            }
        }
        // for (int i = 0; i < n; i++){
        //     cout << i << " " << already[i] << endl;
        // }
        dijkstra();
    }
}

int main(){
    int id, deg, to_node, weight;
    cin >> n;
    for (int i = 0; i< n; i++){for(int j = 0; j < n; j++){adj_matrix[i][j] = inf;}} //adjmatrixの初期化
    for (int i = 0; i< n; i++){d[i] = inf;} //dの初期化
    for (int i = 0; i < n; i++){
        cin >> id >> deg;
        for (int j = 0; j < deg; j++){
            cin >> to_node >> weight;
            adj_matrix[i][to_node] = weight;
        }
    }
    already[0] = 1;
    d[0] = 0;
    for (int j = 1; j < n; j++){
        d[j] = adj_matrix[0][j];
    }
    dijkstra();
    for (int i =0; i < n; i++){
        cout << i << " " << d[i] << endl;
    }
    return 0;
}