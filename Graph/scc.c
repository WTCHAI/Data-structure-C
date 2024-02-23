#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int order;
    int isVisited;
} node_t;

typedef struct graph {
    node_t *graphData;
    int **graphLine;
    int **graphReachable;
    int size;
} graph_t;

typedef struct stack {
    node_t *vertex;
    struct stack *next;
} stack_tt;

stack_tt *push(stack_tt *s, node_t *vertex) {
    stack_tt *tempStack = (stack_tt *) malloc(sizeof(stack_tt));
    tempStack->vertex = vertex;
    tempStack->next = s;
    s = tempStack;
    return s;
}

void pop(stack_tt **s) {
    stack_tt *temp_stack = *s;
    *s = (*s)->next;
    free(temp_stack);
}

node_t *top(stack_tt *s) {
    return s->vertex;
}

int empty(stack_tt *s) {
    if (s == NULL)
        return 1;
    return 0;
}

graph_t *createGraph(int size) {
    graph_t *new_graph = (graph_t *) malloc(sizeof(graph_t));
    new_graph->graphData = (node_t *) malloc(sizeof(node_t) * size);
    new_graph->graphLine = (int **) malloc(sizeof(int *) * size);
    new_graph->graphReachable = (int **) malloc(sizeof(int *) * size);
    new_graph->size = size;
    for (int row = 0; row < size; row++) {
        new_graph->graphLine[row] = (int *) malloc(sizeof(int) * size);
        new_graph->graphReachable[row] = (int *) malloc(sizeof(int) * size);
    }

    for (int i = 0; i < size; i++) {
        (new_graph->graphData + i)->order = i;
        (new_graph->graphData + i)->isVisited = 0;
    }
    
    return new_graph;
}

void configGraphMatrix(int **table, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            table[i][j] = 0;
}   

void resetIsvisited(graph_t *nodeGraph) {
    for (int i = 0; i < nodeGraph->size; i++)
        nodeGraph->graphData[i].isVisited = 0;
}

void resetData(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

void copy_arr(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i];
}

void getReachAbleVertex(graph_t *nodeGraph, int startVertex, int *reachableVertex) {
    stack_tt *s = NULL;
    s = push(s, (nodeGraph->graphData + startVertex));

    int graph_size = nodeGraph->size;
    int reachable;
    node_t *curr_vertex, *des_vertex;
    while (!empty(s)) {
        curr_vertex = top(s);
        pop(&s);
        
        reachableVertex[curr_vertex->order] = 1;
        curr_vertex->isVisited = 1;

        for (int i = 0; i < graph_size; i++) {
            reachable = nodeGraph->graphLine[curr_vertex->order][i];
            des_vertex = (nodeGraph->graphData + i);
            if (reachable && !des_vertex->isVisited) {
                s = push(s, (nodeGraph->graphData + i));
            }
        }
    }
}

void scc(graph_t *nodeGraph, int *result) {
    int graph_size = nodeGraph->size;
    int *reachable_vertex = (int *) malloc(sizeof(int) * graph_size);
    int *temp_result = (int *) malloc(sizeof(int) * graph_size);
    int max_scc_size = 0, temp_scc_size;
    for (int curr_vertex = 0; curr_vertex < graph_size; curr_vertex++) {
        resetData(reachable_vertex, graph_size);
        resetIsvisited(nodeGraph);
        getReachAbleVertex(nodeGraph, curr_vertex, reachable_vertex);
        copy_arr(nodeGraph->graphReachable[curr_vertex], reachable_vertex, graph_size);
    }

    int reachable1, reachable2;
    for (int curr_vertex = 0; curr_vertex < graph_size; curr_vertex++) {
        resetData(temp_result, graph_size);
        temp_scc_size = 0;
        for (int des_vertex = 0; des_vertex < graph_size; des_vertex++) {
            reachable1 = nodeGraph->graphReachable[curr_vertex][des_vertex];
            reachable2 = nodeGraph->graphReachable[des_vertex][curr_vertex];
            if (reachable1 && reachable2) {
                temp_result[des_vertex] = 1;
                temp_scc_size++;
            }
        }
        if (temp_scc_size > max_scc_size) {
            copy_arr(result, temp_result, graph_size);
            max_scc_size = temp_scc_size;
        }
    }
}

int main() {
    int total_nodes, total_lines;
    scanf("%d %d", &total_nodes, &total_lines);
    int start_vertex, des_vertex;
    int *max_result_scc = (int *) malloc(sizeof(int) * total_nodes);
    resetData(max_result_scc, total_nodes);

    graph_t *nodeGraph = createGraph(total_nodes);
    configGraphMatrix(nodeGraph->graphLine, nodeGraph->size);
    configGraphMatrix(nodeGraph->graphReachable, nodeGraph->size);

    for (int i = 0; i < total_lines; i++) {
        scanf("%d %d", &start_vertex, &des_vertex);
        nodeGraph->graphLine[start_vertex][des_vertex] = 1;
    }

    scc(nodeGraph, max_result_scc);
    for (int i = 0; i < total_nodes; i++)
        if (max_result_scc[i])
            printf("%d ", i);

    return 0;
}