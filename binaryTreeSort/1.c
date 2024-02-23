#include <stdio.h>
#include <stdlib.h>
// #include "week9.h"

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;

bst_t *create(int number){
    bst_t *t = (bst_t*)malloc(sizeof(bst_t));
    t->data = number;
    t->left = NULL;
    t->right = NULL;
    return t;
}

bst_t *search(bst_t* targetNode, int data){
    if(targetNode==NULL){
        return targetNode;
    }
    bst_t *temp = NULL;
    if(data < targetNode->data){
        temp = search(targetNode->left,data);
    }
    else{
        temp = search(targetNode->right,data);
    }
    return (temp==NULL)? targetNode : temp;
}

bst_t *insert(bst_t *targetNode,int number){
    bst_t *node = create(number) ;
    if (!targetNode){
        return node ; 
    }
    bst_t* temp = search(targetNode,number);
    if(number < temp->data){
        temp->left = node;
    }
    else{
        temp->right = node;
    }
    return targetNode ;
}

bst_t *find_min(bst_t *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

bst_t *delete(bst_t *targetNode, int number) {
    if (targetNode == NULL)
        return targetNode;

    if (number < targetNode->data)
        targetNode->left = delete(targetNode->left, number);
    else if (number > targetNode->data)
        targetNode->right = delete(targetNode->right, number);
    else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if (targetNode->left == NULL) {
            bst_t *temp = targetNode->right;
            free(targetNode);
            return temp;
        } else if (targetNode->right == NULL) {
            bst_t *temp = targetNode->left;
            free(targetNode);
            return temp;
        }

        // Case 3: Node with two children
        bst_t *temp = find_min_node(targetNode->right);
        targetNode->data = temp->data;
        targetNode->right = delete(targetNode->right, temp->data);
    }
    return targetNode;
}

int find(bst_t *targetNode,int number){
    if(targetNode){
        if(targetNode->data == number){
            return 1;
        }
        if(number < targetNode->data){
            return find(targetNode->left, number);
        }
        else{
            return find(targetNode->right, number);
        }
    }
    return 0;
}

int find_min(bst_t *targetNode){
    if (!targetNode->left){
        return targetNode->data; 
    }
    else {
        return find_min(targetNode->left) ; 
    }
}

int find_max(bst_t *targetNode){
    if (!targetNode->right){
        return targetNode->data; 
    }
    else {
        return find_max(targetNode->right) ; 
    }
}

int main(void) {
    bst_t *t = NULL;
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
                scanf("%d", &data);
                printf("%d\n", find(t, data));
                break;
            case 4:
                printf("%d\n", find_min(t));
                break;
            case 5:
                printf("%d\n", find_max(t));
                break;
        }
    }

    return 0;
}
