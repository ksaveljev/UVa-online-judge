#include <iostream>
using namespace std;

typedef struct node_ {
    int v;
    struct node_* left;
    struct node_* right;
} node;

void insert(node* n, int v) {
    while (true) {
        if (n->v > v) {
            if (n->left == NULL) {
                n->left = new node;
                n->left->v = v;
                n->left->left = NULL;
                n->left->right = NULL;
                break;
            } else {
                n = n->left;
            }
        } else {
            if (n->right == NULL) {
                n->right = new node;
                n->right->v = v;
                n->right->left = NULL;
                n->right->right = NULL;
                break;
            } else {
                n = n->right;
            }
        }
    }
}

void print_post(node* n) {
    if (n == NULL) return;
    print_post(n->left);
    print_post(n->right);
    cout << n->v << endl;
}

int main(void) {
    int v;
    node* root = new node;

    cin >> v;

    root->v = v;
    root->left = NULL;
    root->right = NULL;

    while (cin >> v) {
        insert(root, v);
    }

    print_post(root);

    return 0;
}
