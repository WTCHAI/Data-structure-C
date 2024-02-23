#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t avl_t;
#endif

// Helper function to calculate the height of a node
int height(avl_t *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Helper function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to create a new node with given data
avl_t *create_node(int data) {
    avl_t *new_node = (avl_t *)malloc(sizeof(avl_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1; // New node is initially added at leaf
    return new_node;
}

// Right rotate subtree rooted with y
avl_t *right_rotate(avl_t *y) {
    avl_t *x = y->left;
    avl_t *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left rotate subtree rooted with x
avl_t *left_rotate(avl_t *x) {
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int get_balance(avl_t *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

avl_t *find_min(avl_t *targetNode) {
    avl_t *pos = targetNode;
    while (pos->left != NULL) {
        pos = pos->left;
    }
    return pos;
}

// Insert a new node with a given data
avl_t *insert(avl_t *root, int data) {
    // Perform the normal BST rotation
    if (root == NULL)
        return create_node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root; // Duplicate keys are not allowed in AVL trees

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Perform rotation to maintain AVL property
    int balance = get_balance(root);

    // Left Heavy
    if (balance > 1 && data < root->left->data)
        return right_rotate(root);

    // Right Heavy
    if (balance < -1 && data > root->right->data)
        return left_rotate(root);

    // Left Right Heavy
    if (balance > 1 && data > root->left->data) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Left Heavy
    if (balance < -1 && data < root->right->data) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// Write your code here

avl_t *delete(avl_t *root, int data) {
    
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            avl_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            avl_t *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        avl_t *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Perform rotation to maintain AVL property
    int balance = get_balance(root);

    // Left Heavy
    if (balance > 1 && get_balance(root->left) >= 0) {
        return right_rotate(root);
    }

    // Right Heavy
    if (balance < -1 && get_balance(root->right) <= 0) {
        return left_rotate(root);
    }

    // Left Right Heavy
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Left Heavy
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}


int main(void) {
    avl_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &command);

        switch (command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                print_tree(t);
                break;
        }
    }

    return 0;
}
