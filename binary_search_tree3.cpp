#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    int  key;
    Node *left, *right, *parent;
};

Node *root, *NIL;

void insert(int  k){
    Node *x, *y, *z;
    x = root;
    y = NIL;
    z = new Node;
    z -> key = k;
    z -> left = NIL;
    z -> right = NIL;
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
    Node *x, *y;
    x = root;
    y = NIL;
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

void del(int  k){
    Node *x, *z;
    x = root;
    z = new Node;
    z -> key = k;
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
                if (x -> parent -> right == x){
                    // xが右の子
                    x -> parent -> right = x -> right;
                    x -> right -> parent = x -> parent;
                    x -> left -> parent = x-> left;
                    x -> right -> left = x -> left;
                }else{
                    // xが左の子
                    x -> parent -> left = x -> left;
                    x -> left -> parent = x -> parent;
                    x -> right -> parent = x-> left;
                    x -> left -> right = x -> right;
                }
            }
            else{
                // 子が一つ
                if ((x -> left == NIL) && (x -> right != NIL) && (x -> parent -> right = x)){
                    // cout << x -> key << x -> parent -> right -> key << x -> parent -> left -> key;
                    // xの右に子がいて，xは右のこの場合
                    x -> parent -> right = x -> right;
                    x -> right -> parent = x -> parent;
                }else if ((x -> left == NIL && x -> right != NIL) && (x -> parent -> left = x)){
                    // xの右に子がいて，xは左のこの場合
                    x -> parent -> left = x -> right;
                    x -> right -> parent = x -> parent;
                }else if ((x -> right == NIL && x -> left != NIL) && (x -> parent -> right = x)){
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
        // else{
        //     inorder(root);
        //     cout << endl;
            preorder(root);
            cout << endl;
        // }
        
    }

    return 0;
}