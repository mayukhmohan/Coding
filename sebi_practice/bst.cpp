//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct _node {
    int value;
    _node *left, *right;
}nodeT, *nodeP;

nodeP new_node(int x)
{
    nodeP node = (nodeP)malloc(sizeof(nodeT));
    node->value = x;
    node->left =  node->right = NULL;
    return node;
}

nodeP insert_node_BST(nodeP root, int x)
{
    if (root == NULL) {
        root = new_node(x);
    } else if (root->value > x) {
        root->left = insert_node_BST(root->left, x);
    } else {
        root->right = insert_node_BST(root->right, x);
    }
    return root;
}

void preorder_traversal(nodeP root, vector<int> &vec)
{
    if (root) {
        vec.push_back(root->value);
        preorder_traversal(root->left, vec);
        preorder_traversal(root->right, vec);
    }
}

void inorder_traversal(nodeP root, vector<int> &vec)
{
    if (root) {
        inorder_traversal(root->left, vec);
        vec.push_back(root->value);
        inorder_traversal(root->right, vec);
    }
}

void output_utility(vector<int> vec1, vector<int> vec2)
{
    if (vec1.size() != vec2.size()) {
        cout << "Error in Tree Building !!" << endl;
    }

    for (int i = 0; i < vec1.size(); i++) {
        if (vec1[i] == vec2[i]) {
            cout << i+1 << " " << vec1[i] << endl;
        }
    }
    cout << endl;  
}

int main()
{
    nodeP root = NULL;
    vector<int> preorder;
    vector<int> inorder;

    while (1) {
        int x;
        cin >> x;
        if (x == -1) {
            break;
        }
        root = insert_node_BST(root, x);
    }

    preorder_traversal(root, preorder);
    inorder_traversal(root, inorder);
    output_utility(preorder, inorder);

    return 0;
}