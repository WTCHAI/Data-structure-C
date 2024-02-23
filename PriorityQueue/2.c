#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int freq ; 
    char *text ;
    struct node *left ;
    struct node *right ; 
} node_t; 
typedef node_t tree ; 

typedef struct heap {
    tree **data;
    int last_index;
} heap_t; 

tree *createTree(char *word,int freq){
    tree *node = (tree*)malloc(sizeof(tree_t));
    node->freq = freq;
    node->word = word;
    node->left = NULL;
    node->right = NULL;
    return node;
}

heap_t *configHeap(int size ){
    heap_t *node = (heap_t*)malloc(sizeof(heap_t));
    node->data = (tree**)malloc(sizeof(tree*)*size);
    node->last_index = -1;
    return node;
}

char *configText(char targetText){
    if (targetText == NULL)
        return NULL;
    
    int word_length = strlen(targetText);
    char *text = (char *) malloc(sizeof(char) * word_length + 1);
    strcpy(text, targetText);
    return text;
}

void insert(heap_t *heap, tree *data){
    heap->last_index += 1;
    heap->data[heap->last_index] = data;
    
    int parent = (heap->last_index % 2)? heap->last_index/2 : (heap->last_index-1)/2;
    int child = heap->last_index;
    tree *temp = NULL;
    while(heap->data[parent]->freq > heap->data[child]->freq){
        temp = heap->data[parent];
        heap->data[parent] = heap->data[child];
        heap->data[child] = temp;
        child = parent;
        parent = (parent % 2)? parent/2 : (parent-1)/2;
    }
}


//transaltor
void huffmanEncoder(){

}

int main (){
    int n ;
    scanf("%d", &n);
    heap_t *encode = configHeap(n);

    // get input 
    int freq[n] ; 
    char dataText[n] ;

    //create heap structure 
    heap_t *heap_data = configHeap(n) ; 

    //get text  string 
    for (int i = 0; i < n; ++i) {
        scanf("%s %u", dataText[i], &freq[i]);
        insert(encode,createTreeNode(dataText[i],freq[i])) ;
    }

    while(encode->last_index != 0){
        Encoder(encode);
    }

    int seq = 0;
    sequence(encode->data[0], wordList, &seq);
    for(int i = 0 ; i<size ; i++){
        Stack *s = (Stack*)malloc(sizeof(Stack));
        printf("%s: ", wordList[i]);
        printCode(encode->data[0], &s, wordList[i], 't');

        Stack *temp = s;
        while(temp!=NULL){
            printf("%c", temp->data);
            temp = temp->next;
            free(s);
            s = temp;
        }
        printf("\n");
    }

    return 0;
}
