#include <stdio.h>
#include <stdlib.h>

void addingData ( int *array) {
    for (int i = 0 ; i < 5 ; i++) { 
        // *array = i+1 ; 
        // array++;
        array[i] = i+1 ; 
    }    
}

int main (){
    int array[4] = {23,54,78,90} ;
    int *arrayMalloc ; //= malloc(sizeof(int)) ;
    addingData(arrayMalloc) ; 

    for (int i = 0 ; i < 5 ; i++) { 
        printf(" value : %d\n",arrayMalloc[i]) ; 
    }

    // for (int i = 0 ; i < sizeof(array) / sizeof(array[0]) ; i++) { 
    //     printf("value : %d\n",array[i]) ; 
    // }

}