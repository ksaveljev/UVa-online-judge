#include <iostream>
#include <string>
using namespace std;

typedef struct node_ {
    char c;
    struct node_* left;
    struct node_* right;
} node;

string inorder, preorder;
int pidx;

int find_node(int start, int end, char c) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == c)
            return i;
    }

    return -1;
}

node* rebuild_tree(int start, int end) {
    if (start > end) return NULL;

    node* r = new node;
    r->c = preorder[pidx++];
    r->left = NULL;
    r->right = NULL;

    if (start == end)
        return r;

    int pos = find_node(start, end, r->c);

    r->left = rebuild_tree(start, pos-1);
    r->right = rebuild_tree(pos+1, end);

    return r;
}

void print_postorder(node* r) {
    if (r == NULL) return;

    print_postorder(r->left);
    print_postorder(r->right);

    cout << r->c;
}

int main(void) {
    int c, tmp;

    cin >> c;

    while (c--) {
        cin >> tmp >> preorder >> inorder;
        pidx = 0;
        node* r = rebuild_tree(0, inorder.length()-1);
        print_postorder(r);
        cout << endl;
    }

    return 0;
}
