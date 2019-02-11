#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    int  key;
    Node *left, *right, *parent;
};

Node *NIL, *root = NIL;

void insert(int  k){
    Node *x = root, *y = NIL, *z = new Node;
    z -> key = k;
    z -> left = z -> right = NIL;
    while (x != NIL){
        y = x;
        if (x -> key < z -> key){
            x = x -> right;
        }
        else{
            x = x -> left;
        }
    }
    z -> parent = y;
    if (y == NIL){
        root = z;
    }
    else{
        if (z -> key < y -> key){
            y -> left = z;
        }
        else{
            y -> right = z;
        }
    }
}

bool find(int  k){
    Node *x=root, *y=NIL;
    while (x != NIL){
        if (x -> key < k){
            x = x -> right;
        }
        else if (x -> key > k){
            x = x -> left;
        }
        else{
            return true;
        }
    }
    return false;
}

void preorder(Node *u){
    cout << " " << u -> key;
    if (u -> left != NIL){
        preorder(u -> left);
    }
    if (u -> right != NIL){
        preorder(u -> right);
    }
}

void inorder(Node *u){
    if (u -> left != NIL){
        inorder(u -> left);
    }
    cout << " " << u -> key;
    if (u -> right != NIL){
        inorder(u -> right);
    }
}

Node* nxt_inorder(Node *u){
    if (u -> left != NIL){
        return nxt_inorder(u -> left);
    }
    else{
        return u;
    }
}

void contents(Node *x, Node *z){
    while (x != NIL){
        if (x -> key == z -> key){
            if (x -> left == NIL && x -> right == NIL){
                // xが子を持たないケース
                if (x -> parent -> right == x){
                    x -> parent -> right = NIL;
                }
                else{
                    x -> parent -> left = NIL;
                }
            }
            else if (x -> left != NIL && x -> right != NIL){
                // 子を二匹持っているケース
                Node *nxt = nxt_inorder(x -> right);
                int tmp = nxt -> key;
                contents(nxt, nxt);
                x -> key = tmp;
            }
            else{
                // 子が一つ
                if ((x -> left == NIL) && (x -> right != NIL) && (x -> parent -> right == x)){
                    // xの右に子がいて，xは右のこの場合
                    x -> parent -> right = x -> right;
                    x -> right -> parent = x -> parent;
                }else if ((x -> left == NIL && x -> right != NIL) && (x -> parent -> left == x)){
                    // xの右に子がいて，xは左のこの場合
                    x -> parent -> left = x -> right;
                    x -> right -> parent = x -> parent;
                }else if ((x -> right == NIL && x -> left != NIL) && (x -> parent -> right == x)){
                    // xの左に子がいて，xは右のこの場合
                    x -> parent -> right = x -> left;
                    x -> left -> parent = x -> parent;
                }   
                else{
                    // xの左に子がいて，xは左のこの場合
                    x -> parent -> left = x -> left;
                    x -> left -> parent = x -> parent;
                }
            }
            break;
        }
        else if (x -> key < z -> key){
            x = x -> right;
        }
        else{
            x = x -> left;
        }
    }
}

void del(int  k){
    Node *x, *z;
    x = root;
    z = new Node;
    z -> key = k;
    contents(x, z);
}

int  main(){
    int  m;
    int  k;
    string command;
    cin >> m;
    for (int  i = 0; i < m; i++){
        cin >> command;
        if (command == "insert"){
            cin >> k;
            insert(k);
        }
        else if(command == "find"){
            cin >> k;
            if (find(k)){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
        else if (command == "delete"){
            cin >> k;
            del(k);
        }
        else{
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
        
    }

    return 0;
}