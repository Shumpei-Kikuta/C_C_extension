#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define NIL -1
#define MAX 25
using namespace std;

struct Node{
    int parent;
    int left;
    int right;
};

void input_dispose(int *n, Node *nodes){
    cin >> *n;
    int id, left, right;
    Node node;
    for (int i = 0; i < *n; i++){
        cin >> id >> left >> right;
        node.left = left;
        node.right = right;
        nodes[id] = node;
    }
}

void get_depth(int depth, int i, int *depths, Node *nodes){
    // depthを求め，nodeのidの順番に求めていく関数
    depths[i] = depth;
    if (nodes[i].left != NIL){
        get_depth(depth + 1, nodes[i].left, depths, nodes);
    }
    if (nodes[i].right != NIL){
        get_depth(depth + 1, nodes[i].right, depths, nodes);
    }
}

int get_height(int i, int *heights, Node *nodes){
    // 高さを求め，順番に格納する関数
    int right = 0;
    int left = 0;
    if (nodes[i].right != NIL){
        right = get_height(nodes[i].right, heights, nodes) + 1;
    }
    if (nodes[i].left != NIL){
        left = get_height(nodes[i].left, heights, nodes) + 1;
    }
    heights[i] = max(right, left);
    return max(right, left);
}

void get_parent(Node *nodes, int i, int p){
    nodes[i].parent = p;
    if (nodes[i].left != NIL){
        get_parent(nodes, nodes[i].left, i);
    }
    if (nodes[i].right != NIL){
        get_parent(nodes, nodes[i].right, i);
    }
}

int get_degree(int i, Node *nodes){
    if (nodes[i].left != NIL && nodes[i].right != NIL){
        return 2;
    }
    else if (nodes[i].left != NIL && nodes[i].right == NIL){
        return 1;
    }
    else if (nodes[i].left != NIL && nodes[i].right == NIL){
        return 1;
    }
    else{
        return 0;
    }
}

string get_type(int i, Node *nodes){
    if (nodes[i].parent == NIL){
        return "root";
    }
    else if (nodes[i].right == NIL && nodes[i].left == NIL){
        return "leaf";
    }
    else{
        return "internal leaf";
    }
}

void output_dispose(int n, Node *nodes, int *depths, int *heights, int *siblings){
    int parent, sibling, degree, depth, height;
    string type;
    for (int i = 0; i < n; i++){
        // 各情報を求める関数群
        parent = nodes[i].parent;
        sibling = siblings[i];
        degree = get_degree(i, nodes);
        depth = depths[i];
        height = heights[i];
        type = get_type(i, nodes);
        cout << "node " << i << ": parent = " << parent << ", sibling = " << sibling << ", degree = " << degree;
        cout << ", depth = " << depth << ", height = " << height << ", " << type << endl;
    }
}

void get_sibling(int n, int *siblings, Node *nodes){
    for (int i = 0; i< n; i++){
        if (nodes[i].parent == NIL){
            siblings[i] = NIL;
        }
        if (nodes[i].left != NIL && nodes[i].right != NIL){
            siblings[nodes[i].left] = nodes[i].right;
            siblings[nodes[i].right] = nodes[i].left;
        }
        else if (nodes[i].left != NIL && nodes[i].right == NIL){
            siblings[nodes[i].left] = NIL;
        }
        else if (nodes[i].left != NIL && nodes[i].right == NIL){
            siblings[nodes[i].right] = NIL;
        }
    }
}

int main(){
    int n;
    Node nodes[MAX];
    int depths[MAX];
    int heights[MAX];
    int siblings[MAX];
    input_dispose(&n, nodes);
    
    get_parent(nodes, 0, NIL);
    get_depth(0, 0, depths, nodes);
    get_sibling(n, siblings, nodes);
    int _ = get_height(0, heights, nodes);
    output_dispose(n, nodes, depths, heights, siblings);
    return 0;
}