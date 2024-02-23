#include <stdio.h>


int main(){
    int n ;
    scanf("%d",&n) ;
    int size = 101 ; 
    int numbers[101] ;
    // make initial state = 0  
    for (int i = 0 ; i < 101 ; i++){
        numbers[i] = 0  ; 
    }

    // get input then bring into numbers and record count at any number 0-101
    for (int i = 0 ; i<n ; i++){
        int targetNumber ; 
        scanf("%d",&targetNumber) ;
        numbers[targetNumber]++ ;
    }
    int maxCount = 0 ; 
    for (int i = 0 ; i<size ; i++){
        if (numbers[i] != 0 ){
            if (numbers[i]>maxCount){
                maxCount = numbers[i] ; 
            }
            // printf("index : %d value : %d\n",i,numbers[i]) ; 
        }
    }
    // printf("%d\n",maxCount) ;
    // prepare data for sort output 
    for (int i = 0  ; i<size  ; i++){
        if (numbers[i] == maxCount) {
            printf("%d ",i) ; 
        }
    }
}
