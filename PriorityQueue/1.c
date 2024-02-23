#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;

// Function prototypes
heap_t* ConfigHeap(int m){
    heap_t * node = malloc(sizeof (heap_t)) ; 
    node->data = malloc (sizeof(m)) ; 
    node->last_index = -1 ;
    return node ; 
}

void insert(heap_t *h, int targetNumber) {
    //update more index 
    h->last_index += 1;
    // 
    h->data[h->last_index] = targetNumber;

    int index = h->last_index;

    // Heapify up
    while (index > 0 && h->data[index] > h->data[(index - 1) / 2]) {
        // Swap with parent
        int tempValue = h->data[index];
        //make it equal upper one
        h->data[index] = h->data[(index - 1) / 2];
        h->data[(index - 1) / 2] = tempValue ;
        // update index 
        index = (index - 1) / 2;
    }
}

int find_max(heap_t *heap){
    if (heap->last_index >= 0 ){
        return heap->data[0] ; 
    }
    else return -1 ; 
}


void delete_max(heap_t *heap){
    // 1 remove root 2 get max to root then repeat 
    if( heap->last_index != -1){
        heap->data[0] = heap->data[heap->last_index] ;
        heap->last_index -= 1 ; 
        // 
        int index = 0 ; 
        while (1) {
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            int lasted = index;

            // Compare with left child
            if (left_child <= heap->last_index && heap->data[left_child] > heap->data[lasted])
                lasted = left_child;

            // Compare with right child
            if (right_child <= heap->last_index && heap->data[right_child] > heap->data[lasted])
                lasted = right_child;

            // If the largest is not the current index, swap and continue heapifying down
            if (lasted != index) {
                int temp = heap->data[index];
                heap->data[index] = heap->data[lasted];
                heap->data[lasted] = temp;
                index = lasted;
            } else {
                break;  // If the current node is already larger than its children, stop heapifying
            }
        }
    }
    else return ; 
}

void update_key(heap_t *heap, int old_key, int new_key){
    //find target index to replace part 
    int targetIndex ; 
    for (int i = 0 ; i<=heap->last_index ; i++){
        if (heap->data[i] == old_key){
            heap->data[i] = new_key ; 
            targetIndex = i ;
            break ;  
        }
    } 
    // change sequence in queue
    int checkIndex = targetIndex ; 
    //after replace make it to the root 
   while (checkIndex > 0 && heap->data[checkIndex] > heap->data[(checkIndex - 1) / 2]) {
        // Swap with parent
        int temp = heap->data[checkIndex];
        heap->data[checkIndex] = heap->data[(checkIndex - 1) / 2];
        heap->data[(checkIndex - 1) / 2] = temp;
        checkIndex = (checkIndex - 1) / 2;
    }

    // Heapify down
    int parent = targetIndex;
    while (1) {
        int left_child = 2 * parent + 1;
        int right_child = 2 * parent + 2;
        int largest = parent;

        // Compare with left child
        if (left_child <= heap->last_index && heap->data[left_child] > heap->data[largest])
            largest = left_child;

        // Compare with right child
        if (right_child <= heap->last_index && heap->data[right_child] > heap->data[largest])
            largest = right_child;

        // If the largest is not the current parent, swap and continue heapifying down
        if (largest != parent) {
            int temp = heap->data[parent];
            heap->data[parent] = heap->data[largest];
            heap->data[largest] = temp;
            parent = largest;
        } else {
            break;  // If the current node is already larger than its children, stop heapifying
        }
    }
}
void bfs(heap_t *heap){
    //show list of queue
    for (int i = 0 ; i<=heap->last_index ; i++){
        printf("%d ",heap->data[i]) ; 
    }
    printf("\n") ; 
}

int main(void) {
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = ConfigHeap(m);

    for (i = 0; i < n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key, new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }

    return 0;
}
