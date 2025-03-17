#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Bst {
    int val;
    Bst* left, *right;
};

Bst* makeRoot(int val) {
    Bst* r = (Bst*)malloc(sizeof(Bst));
    r->val = val;
    r->left = NULL; r->right = NULL;
    return r;
}

bool check;
Bst* insert(Bst* root, int val) {
    if (!root) 
        return makeRoot(val);
    
    if (root->val == val) {
        check = true;
        return root;
    }
    if (val > root->val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    
    Bst* root = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        check = false;
        root = insert(root, val);

        if (check) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}