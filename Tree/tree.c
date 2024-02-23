#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value ; 
    struct node *firstChildren ; 
    struct node *nextSibling ; 
    struct node *parent ; 
} node_t ; 

typedef node_t tree_t ; 

// external function

// search targetnode and return that node to process in other function 
tree_t *searchTargetNode(tree_t *node , int targetValue){
    if (node == NULL) {
        return NULL; // Node not found
    }
    if (node->value == targetValue){
        return node; 
    }
    tree_t *tempNode = searchTargetNode(node->firstChildren, targetValue);
    if (tempNode != NULL) {
        return tempNode;
    }
    return searchTargetNode(node->nextSibling, targetValue);
}
tree_t *createNode(tree_t *parentNode, int value) {
    tree_t *tempNode = malloc(sizeof(tree_t));
    if (tempNode != NULL) {
        tempNode->value = value;
        tempNode->firstChildren = NULL;
        tempNode->nextSibling = NULL;
        tempNode->parent = parentNode;
    }
    return tempNode;
}

tree_t *attach(tree_t *node, int targetNode, int value) {
    if (targetNode == -1) {
        return createNode(NULL, value);
    } else {
        tree_t *parentNode = searchTargetNode(node, targetNode);
        if (parentNode != NULL) {
            tree_t *childrenNode = parentNode->firstChildren;

            // If there are no children, create and attach the new node as the first child.
            if (childrenNode == NULL) {
                tree_t *newNode = createNode(parentNode, value);
                parentNode->firstChildren = newNode;
            } else {
                // Iterate through the children to find the last one.
                while (childrenNode->nextSibling != NULL) {
                    childrenNode = childrenNode->nextSibling;
                }
                
                // Create and attach the new node as the last sibling.
                tree_t *newNode = createNode(parentNode, value);
                childrenNode->nextSibling = newNode;
            }
        }
        return node; // Return the modified tree
    }
}


tree_t *detach(tree_t *node, int targetNode) {
    if (node == NULL) {
        return NULL; // Node not found, return NULL
    }
    if (node->value == targetNode) {
        // Found the target node, remove it
        tree_t *temp = node->nextSibling;
        free(node);
        return temp; // Return the new subtree
    }
    // Recursively detach in children
    node->firstChildren = detach(node->firstChildren, targetNode);
    // Recursively detach in siblings
    node->nextSibling = detach(node->nextSibling, targetNode);
    return node; // Return the modified tree
}

// is found 
int search(tree_t *node, int targetValue) {
    if (node == NULL) {
        return 0; 
    }
    else if (node->value == targetValue) {
        return 1; 
    }
    else {
        int isFoundIn = search(node->firstChildren,targetValue) ;          
        if (isFoundIn) {
            return 1; 
        }
        // else  go next in sibling or if not search again 
        else {
            // Recursively search in the next sibling if it exists
            return search(node->nextSibling, targetValue);
        }
    }
}

int degree(tree_t *node, int targetValue) {
    if (node == NULL) {
        return 0; 
    }
    if (node->value == targetValue) {
        // Count the number of immediate children
        int count = 0;
        tree_t *child = node->firstChildren;
        while (child != NULL) {
            count++;
            child = child->nextSibling;
        }
        return count;
    } else {
        // Recursively search in the first child (assuming a tree structure)
        int countInChildren = degree(node->firstChildren, targetValue);
        // Recursively search in the next sibling if it exists
        int countInSibling = degree(node->nextSibling, targetValue);
        // The degree of the current node is the sum of degrees in children and siblings
        return countInChildren + countInSibling;
    }
}


int is_root(tree_t *node , int targetValue){
    if (node == NULL) {
        return 0 ; 
    }
    else if (node->value == targetValue){
        return 1 ;  // Return 1 if it's the root
    }
    tree_t *tempNode = searchTargetNode(node->firstChildren,targetValue) ;  
    if (tempNode != NULL){
        return 0 ; // Not the root
    } else {
        return is_root(node->nextSibling, targetValue);
    }
}

int is_leaf(tree_t *node , int targetValue){
    if (node == NULL){
        return 0 ; 
    }
    if (node->value == targetValue){
        if (node->firstChildren == NULL ){
            return 1 ; 
        }  
    }
    // Recursively search in the first child (assuming a tree structure)
    int isLeafInChildren = is_leaf(node->firstChildren, targetValue);
    
    // Recursively search in the next sibling if it exists
    int isLeafInSibling = is_leaf(node->nextSibling, targetValue);
    
    // It's a leaf if it's a leaf in children or siblings
    return isLeafInChildren || isLeafInSibling;
}

void siblings(tree_t *node, int targetValue) {
    if (node == NULL) {
        printf("\n");
        return;
    }
    // check is have node or parent is valid
    tree_t *targetNode = searchTargetNode(node, targetValue);
    if (targetNode == NULL || targetNode->parent == NULL) {
        printf("\n");
        return;
    }

    tree_t *childrenNode = targetNode->parent->firstChildren;
    // 
    while (childrenNode != NULL) {
        if (childrenNode != targetNode) {
            printf("%d ", childrenNode->value);
        }
        childrenNode = childrenNode->nextSibling;
    }
    printf("\n");
}


int depth(tree_t *node, int targetValue) {
    if (node == NULL) {
        return -1;
    }

    if (node->value == targetValue) {
        return 0; 
    }

    int deepInChild = depth(node->firstChildren, targetValue);

    if (deepInChild >= 0) {
        return 1 + deepInChild;
    }

    int depthInSibling = depth(node->nextSibling, targetValue);

    if (depthInSibling >= 0) {
        return depthInSibling;
    }
    return -1;
}

// need help to keep data using stack 
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

// Define the Stack structure
typedef struct {
    StackNode *top;
} Stack;

// Create a new stack
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        perror("Failed to create stack");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Push an integer onto the stack
void push(Stack *stack, int value) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode) {
        perror("Failed to push onto stack");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Check if the stack is empty

// Print the stack
void printStack(Stack *stack) {
    StackNode *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_path(tree_t *node, int startNode, int endNode) {
    tree_t *lastNode = searchTargetNode(node, endNode);
    Stack *stackData = createStack(); // Create a new stack
    while (lastNode->value != startNode) {
        push(stackData, lastNode->value);
        lastNode = lastNode->parent;
    }   
    if (lastNode->value == startNode) {
        push(stackData, lastNode->value);
    }
    printStack(stackData);
}

int path_length(tree_t *node, int startNode, int endNode) {
    tree_t *lastNode = searchTargetNode(node, endNode);
    Stack *stackData = createStack(); // Create a new stack
    int count = 0 ; 
    while (lastNode->value != startNode) {
        push(stackData, lastNode->value);
        lastNode = lastNode->parent;
        count++ ; 
    }   
    if (lastNode->value == startNode) {
        push(stackData, lastNode->value);
        count++ ; 
    }
    return count ; 
}

void ancestor(tree_t *node, int targetValue) {
    if (node == NULL) {
        return;
    }

    tree_t *targetNode = searchTargetNode(node, targetValue);

    if (targetNode == NULL) {
        printf("%d\n", targetValue); // Print the target value itself if not found
        return;
    }

    while (targetNode->parent != NULL) {
        targetNode = targetNode->parent;
        printf("%d ", targetNode->value);
    }
    printf("\n");
}

void descendant(tree_t *node, int targetValue) {
    // if (node == NULL) {
    //     return;
    // }
    // tree_t *targetNode = searchTargetNode(node, targetValue);
    // if (targetNode == NULL) {
    //     return;
    // }

    // print_tree(targetNode->firstChildren);
}


typedef struct QueueNode {
    tree_t *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue) {
        perror("Failed to create queue");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, tree_t *data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (!newNode) {
        perror("Failed to enqueue");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

tree_t *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    QueueNode *temp = queue->front;
    tree_t *data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

// BFS function
void bfs(tree_t *root) {
    if (root == NULL) {
        return;
    }
    Queue *queue = createQueue();
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        tree_t *current = dequeue(queue);
        printf("%d ", current->value);

        // Enqueue all children
        tree_t *child = current->firstChildren;
        while (child != NULL) {
            enqueue(queue, child);
            child = child->nextSibling;
        }
    }

    free(queue); // Free the queue when done
}

void dfs(tree_t *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value); // Print current node
    dfs(node->firstChildren); 
    dfs(node->nextSibling);   
}

int findDeepestLevelDFS(tree_t *node) {
    if (node == NULL) {
        return 0 ;
    }
    int maxChildDepth = 0;
    tree_t *child = node->firstChildren;
    while (child != NULL) {
        int childDepth = findDeepestLevelDFS(child);
        if (childDepth > maxChildDepth) {
            maxChildDepth = childDepth;
        }
        child = child->nextSibling;
    }
    return 1 + maxChildDepth;
}

void print_tree(tree_t *node) {
    if (node != NULL) {
        for (int i = 0; i < depth(node, node->value); i++) {
            printf("   ");
        }
        printf("%d\n", node->value) ;
        print_tree(node->firstChildren) ;
        print_tree(node->nextSibling);
    }
}

int main(void) {
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break ;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break ;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break ;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n",
            path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;
        }
    }
    return 0;
}