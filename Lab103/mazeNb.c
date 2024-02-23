#include <stdio.h>
#include <stdlib.h>

void makeInitialArray(int size, int** numbers) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            numbers[i][j] = 0;
        }
    }
}

void pattern1(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", (i + 1) + j * size);
        }
        printf("\n");
    }
}

void pattern2(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j % 2 == 0) {
                printf("%d ", (i + 1) + j * size);
            } else {
                printf("%d ", (size * 2 - i) + (j - 1) * size);
            }
        }
        printf("\n");
    }
}

void pattern3(int size, int **numbers) {
    int start = 1 , row = 0  , col = size-1 ; 

    makeInitialArray(size, numbers);
    // half upper index
    for (int i = 1 ; i<=size ; i++){
        for (int j = 0 ; j <i ; j++){
            // is overwrite
            if (col == -1 ){
                col = 0 ; 
            }
            if (row == -1 ){
                row = 0 ;
            }
            if ( col >=size){
                col = size-1 ; 
            }
            if ( row >=size ){
                row = size-1 ; 
            }
            // precess part 
            if (i%2 == 0 ){
                numbers[col][row] = start;
                col++; 
                row++ ; 
            }
            else {
                numbers[col][row] = start ;
                col-- ; 
                row-- ;
            }
            start++ ; 
        }
    }
    // half lower part 
    col = 1 ,row = 0 ; 
    for (int i = 1 ; i<size; i++){
        // printf("%d %d\n",col,row) ; 
        for (int j = size-i ; j > 0 ; j--){
            // is overwrite check 
            if (col <= -1 ){
                col = 0 ; 
            }
            if (row <= -1 ){
                row = 0 ;
            }
            if ( col >= size){
                col = size-1 ; 
            }
            if ( row >=size ){
                row = size-1 ; 
            }

            if (i%2 == 0 ){
                    // printf("%d%d ",col,row) ;
                    numbers[row][col] = start ;
                    if (j == 1){
                        row-- ; 
                        col++; 
                    }else {
                        col--; 
                        row-- ;                         
                    }     
                }
            else {
                    // printf("%d%d ",col,row) ; 
                    numbers[row][col] = start; 
                    if (j == 1 ){
                        row-- ; 
                    }
                    else {
                        col++ ; 
                        row++ ;                        
                    }
            }       
            start++ ;  
        }
    }


    // printf output check 
    for (int i = 0 ; i < size ; i ++){
        for (int j = 0 ; j < size ; j++){
            printf("%d ",numbers[i][j]) ; 
        }
        printf("\n") ; 
    }
}


void pattern4(int size, int **numbers) {
    makeInitialArray(size, numbers); 
    int round = (size / 2) + (size % 2);
    int num = 1;

    for (int i = 0; i < round; i++) {
        for (int j = 0; j < size - (2 * i); j++) {
            if (!numbers[i + j][i]) {
                numbers[i + j][i] = num++;
            }
        }
        for (int j = 0; j < size - (2 * i); j++) {
            if (!numbers[size - i - 1][i + j]) {
                numbers[size - i - 1][i + j] = num++;
            }
        }
        for (int j = 0; j < size - (2 * i); j++) {
            if (!numbers[size - i - 1 - j][size - i - 1]) {
                numbers[size - i - 1 - j][size - i - 1] = num++;
            }
        }
        for (int j = 0; j < size - (2 * i); j++) {
            if (!numbers[i][size - i - 1 - j]) {
                numbers[i][size - i - 1 - j] = num++;
            }
        }
    }

    // Print the array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int pattern, size;

    scanf("%d %d", &size , &pattern);
    int** numbers = (int**)malloc(sizeof(int*) * size);
    if (pattern == 1) {
        pattern1(size);
    }
    else if (pattern == 2) {
        pattern2(size);
    }
    else if (pattern == 3) {
        for (int i = 0; i < size; i++) {
            numbers[i] = (int*)malloc(sizeof(int) * size);
        }
        pattern3(size, numbers);
    }
    else if (pattern == 4) {
        for (int i = 0; i < size; i++) {
            numbers[i] = (int*)malloc(sizeof(int) * size);
        }
        pattern4(size, numbers);
    }

    for (int i = 0; i < size; i++) {
        free(numbers[i]);
    }
    free(numbers);
    return 0;
}
