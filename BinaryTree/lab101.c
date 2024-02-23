#include <stdio.h>
#include <stdlib.h>
#include "./week8.h"

#ifndef __bin_tree__
 
typedef struct tree_t {
    int data;
    struct tree_t *left;
    struct tree_t *right;
} tree_t_t;
typedef tree_t_t tree_t;
#endif

int is_full(tree_t *tree_t) {
    if (!tree_t){
        return 1 ; 
    }
    if((tree_t->left && !tree_t->right) || (!tree_t->left && tree_t->right ) ){
        return 0 ;
    }
    return is_full(tree_t->left) && is_full(tree_t->right);
}

int height(tree_t *node) {
    if (node == NULL){
        return 0 ;
    }
    int leftHeight = height(node->left) ;
    int rightHeight = height(node->right) ;

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int size(tree_t *node){
    if (node == NULL){
        return 0 ; 
    }
    return size(node->left) + 1 + size(node->right); 
}

int is_perfect(tree_t *node) {
    int treeSize = size(node) ; 
    int treeHeight = height(node) ;
    int amountPerfect = (2*treeHeight)+1;
    // printf("height  : %d\n",treeHeight) ; 
    // printf("size : %d\n",treeSize) ; 
    // printf("perfect expected : %d\n",amountPerfect) ; 
    if (treeSize == amountPerfect){
        return 1 ; 
    }
    return 0 ; 
}

int findMaxIndex (tree_t *node){
    if (node){
        if (!node->left && !node->right){
            return node->nb ; 
        }
        else {
            int checkLeft = findMaxIndex(node->left) ; 
            int checkRight = findMaxIndex(node->right) ; 
            return (checkLeft> checkRight) ? checkLeft : checkRight ; 
        }
    }
    return 0 ; 
}

int is_complete(tree_t *node){
    if (node){
        int maxIndex = findMaxIndex(node) ; 
        int treeSize = size(node) ; 
        return (maxIndex == treeSize) ? 1 : 0 ;
    }
    return 0 ; 
}

// must have onlu one per floor 
int is_degenerate(tree_t *node){
    int treeSize = size(node) ; 
    int treeHeigth = height(node) ;
    if (treeSize == treeHeigth){
        return 1 ; 
    }
    return 0 ; 
}

int is_skewed(tree_t *node) {
    if (!node) {
        return 1; // An empty tree is considered skewed
    }
    if (node->left && node->left->right) {
        return 0; // Left child has a right child; not skewed
    }
    if (node->right && node->right->left ) {
        return 0; // Right child has a left child; not skewed
    }
    // Recursively check the left and right subtrees
    return is_skewed(node->left) && is_skewed(node->right);
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,&branch);
        t = attach(t, parent, child, branch);
    }
    printf("%d %d %d %d %d\n", is_full(t),is_perfect(t), is_complete(t),is_degenerate(t), is_skewed(t));
    return 0;
}