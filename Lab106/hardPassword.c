#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char c;
    struct node *next;
} node_t;
typedef node_t stack;

void push(stack **s, char c) {
    stack *tempNode = (stack *) malloc(sizeof(stack));
    tempNode->c = c;
    tempNode->next = *s;
    *s = tempNode;
}

char top(stack *s) {
    if (s != NULL)
        return s->c;
    return 0;
}

void pop(stack **s) {
    stack *tempNode = *s;
    *s = (*s)->next;
    free(tempNode);
}

int main() {
    stack *s = NULL;
    char tempC;
    
    while ((tempC = getchar()) != 'x') {
        push(&s, tempC);
    }

    int condition = 1;
    while ((tempC = getchar()) != 'y') {
        if (top(s) == tempC)
            pop(&s);
        else
            condition = 0;
    }
    printf("%d", condition);
    return 0;
}