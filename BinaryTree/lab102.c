#include <stdio.h> 
#include <stdlib.h> 
#include "./week8.h" 

#ifndef __bin_tree__
typedef struct node { 
    int data; 
    struct node *left; 
    struct node *right; 
} node_t; 
typedef node_t tree_t;
#endif 




void print_preorder(tree_t *node){
    if (!node){
        return ;
    }
    printf("%d ",node->data) ;
    print_preorder(node->left) ; 
    print_preorder(node->right) ;

}

void print_postorder(tree_t *node){
    if (!node){
        return ;
    }
    print_postorder(node->left) ; 
    print_postorder(node->right) ;
    printf("%d ",node->data) ;
}

void print_inorder(tree_t *node){
    if (!node){
        return ;
    }
    print_inorder(node->left) ; 
    printf("%d ",node->data) ;
    print_inorder(node->right) ;
}

int main(void) { 
    tree_t *t = NULL; 
    int n, i; 
    int parent, child; 
    int branch; // 0 root, 1 left, 2 right 
    scanf("%d", &n); 
    for (i=0; i<n; i++) { 
        scanf("%d %d %d", &parent, &child,  &branch); 
        t = attach(t, parent, child, branch);
    } 
    print_preorder(t); 
    print_postorder(t); 
    print_inorder(t); 
    return 0; 
}
