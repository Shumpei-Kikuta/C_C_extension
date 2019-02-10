#include <iostream>
#define MAX 25
#define NIL -1
using namespace std;

struct Node{
    int left;
    int right;
    int parent;
};

void input_dispose(int *n, Node *nodes){
    cin >> *n;
    for (int i = 0; i < *n; i++){
        int id, left, right, parent;
        Node node;
        cin >> id >> left >> right;
        node.left = left;
        node.right = right;
        node.parent = NIL;
        nodes[id] = node;
    }
}

void get_parent(int n, Node *nodes){
    for (int i = 0; i < n; i++){
        if (nodes[i].left != NIL){
            nodes[nodes[i].left].parent = i;
        }
        if (nodes[i].right != NIL){
            nodes[nodes[i].right].parent = i;
        }
    }
}

void preorder_tree_walk(int u, Node *nodes){
    cout << " " << u;
    if (nodes[u].left != NIL){
        preorder_tree_walk(nodes[u].left, nodes);
        }
    if (nodes[u].right != NIL){
        preorder_tree_walk(nodes[u].right, nodes);
    }
}

void inorder_tree_walk(int u, Node *nodes){
    if (nodes[u].left != NIL){
        inorder_tree_walk(nodes[u].left, nodes);
    }
    cout << " " << u;
    if (nodes[u].right != NIL){
        inorder_tree_walk(nodes[u].right, nodes);
    } 
}

void postorder_tree_walk(int u, Node *nodes){
    if (nodes[u].left != NIL){
        postorder_tree_walk(nodes[u].left, nodes);
    }
    if (nodes[u].right != NIL){
        postorder_tree_walk(nodes[u].right, nodes);
    }
    cout << " " << u;
}

int main(){
    int n, root; 
    Node nodes[MAX];
    // 二分木の格納
    input_dispose(&n, nodes);
    get_parent(n, nodes);
    // for (int i = 0; i < n; i ++){
    //     cout << nodes[i].parent << endl;
    // }
    for (int i = 0;i < n; i++){
        if (nodes[i].parent == NIL){
            root = i;
        }
    }
    // preorder tree walk
    cout << "Preorder" << endl;
    preorder_tree_walk(root, nodes);
    cout << endl;

    cout << "Inorder" << endl;
    inorder_tree_walk(root, nodes);
    cout << endl;

    cout << "Postorder" << endl;
    postorder_tree_walk(root, nodes);
    cout << endl;
    return 0;
}