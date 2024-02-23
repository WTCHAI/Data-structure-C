#include <stdio.h>
#include <stdlib.h>

void displayData(int *data,int size) { 
    for (int i = 0 ; i <size ; i++){
        printf("%d ",data[i]) ; 
    }
    printf("\n") ; 
}

void *insertionSort(int size , int *data){
    for(int i = 1 ; i<size ; i++){
        int temp = data[i] ; 
        for(int j = i ; j > 0 ; j--){
            if (temp < data[j-1]){
                data[j] = data[j-1] ; 
                data[j-1] = temp ;
            }
            else {
                break ;
            }
        }
        displayData(data,size);
    }

}

int main() {
    int size, temp;
    scanf("%d", &size);

    int* data = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &temp);
        data[i] = temp;
    }

    insertionSort(size, data);
    free(data);  // Free the dynamically allocated memory

    return 0;
}
