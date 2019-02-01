#include <iostream>
#include <vector>
using namespace std;
#define NIL -1

struct Node{
    int parent;
    int left;
    int right;
};

void input_dispose(int *n, Node *Nodes){
    cin >> *n;
    for (int i = 0; i < *n; i++){
        Nodes[i].parent = NIL;
        Nodes[i].right = NIL;
        Nodes[i].left = NIL;
    }
    for (int i = 0; i < *n; i++){
        int num, num_children;
        cin >> num >> num_children;
        for (int j = 0; j < num_children; j++){
            int child, last_child;
            cin >> child;
            if (j == 0){
                Nodes[num].left = child;
            }else{
                Nodes[last_child].right = child;
            }
            Nodes[child].parent = num;
            last_child = child;
        }
    }
}

int calc_depth(int u, Node *Nodes){
    if (Nodes[u].parent == NIL){
        return 0;
    }
    else{
        return calc_depth(Nodes[u].parent, Nodes) + 1;
    }
}

void calc_attribute(int i, Node *Nodes){
    if (Nodes[i].parent == NIL){
        cout << "root" << ", ";
    }else if (Nodes[i].left == NIL){
        cout << "leaf" << ", ";
    }else{
        cout << "internal node" << ", ";
    }
}

void ask_sibling(vector<int> &rchildren, int i, Node *Nodes){
    if (Nodes[i].right != NIL){
        rchildren.push_back(Nodes[i].right);
        ask_sibling(rchildren, Nodes[i].right, Nodes);
    }
}

void exec_children(vector<int> &rchildren, int i, Node *Nodes){
    if (Nodes[i].left != NIL){
        rchildren.push_back(Nodes[i].left);
        ask_sibling(rchildren, Nodes[i].left, Nodes);
    }
}

void calc_children(int i, Node *Nodes){
    vector<int> children;
    vector<int> &rchildren = children;
    exec_children(rchildren, i, Nodes);
    int child_num = children.size();
    cout << "[";
    if (child_num != 0){
        for (int i = 0; i < child_num; i++){
            cout << children[i];
            if (i != child_num - 1){
                cout << ", ";
            }
        }
    }
    cout << "]" << endl;

}

void output_dispose(int n, Node *Nodes, int *depths){
    for (int i = 0; i < n; i++){
        cout << "node " << i << ": parent = " << Nodes[i].parent << ", ";
        int depth = depths[i];
        cout << "depth = " << depth << ", ";
        calc_attribute(i, Nodes);
        // cout << calc_attribute(i, Nodes) << ", ";
        calc_children(i, Nodes);


    }
}

void set_depth(int n, Node *Nodes, int p, int *depths){
    depths[n] = p;
    if (Nodes[n].left != NIL){
        set_depth(Nodes[n].left, Nodes, p + 1, depths);
    }
    if (Nodes[n].right != NIL){
        set_depth(Nodes[n].right, Nodes, p, depths);
    }
}

int main(){
    int n;
    Node Nodes[100000];
    int depths[100000];
    input_dispose(&n, Nodes);
    int root;
    for (int i = 0; i < n; i++){
        if (Nodes[i].parent == NIL){
            root = i;
            break;
        }
    }
    set_depth(root, Nodes, 0, depths);
    output_dispose(n, Nodes, depths);
    return 0;
}