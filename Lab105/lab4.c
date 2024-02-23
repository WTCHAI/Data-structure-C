#include <stdio.h>

int checkNumber(int targetNumber, int k) {
    int num = targetNumber;
    while (num != 0) {
        int digit = num % 10;
        if (digit % k == 0) {
            return 1;
        }
        num /= 10;
    }
    return 0;
}


int main (){
    int n , k ; 

    scanf("%d %d",&n,&k) ;
    int list[n] ; 
    for (int i = 0 ; i<n ; i++){
        scanf("%d",&list[i]) ; 
    }

    int survive = n  ;
    int count = 1 ; 
    int index = 0 ;
    while (survive > 1 ){
        if (list[index]>0){
            if (checkNumber(count,k)){
                list[index]-- ; 
            }
            if (list[index] == 0 ){
                survive-- ; 
                list[index] -- ; 
            }
            count++ ; 
            index++ ;
        }else {
            index++ ; 
        }
        if (index == n){
            index = 0 ;
        }

    }
    for (int i = 0 ;i < n ;i++){
        if (list[i]>0){
        // printf("list at index %d: %d\n",i,list[i]) ;
        printf("%d",i+1) ; 
        }
    }
    
}