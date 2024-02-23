#include <stdio.h>

int onCalStrongNum (int targetNumber){
    int result = 0 ; 
    while (targetNumber > 0 ){
        int calSum = 1 ; 
        int digit = targetNumber % 10 ; 
        targetNumber/=10 ; 
        for (digit ; digit > 0 ; digit--){
            calSum *= digit ; 
        }
        result+=calSum ;
    }

    return result ;
}


int main(){
    int n ;
    scanf("%d",&n) ;
    if (n>100000){
        return 0 ; 
    }
    for ( int i = 0 ; i<n ; i++) {
        int m  ;
        scanf(" %d",&m) ;
        // ---
        if (m>1000000){
            return 0 ;
        }
        int j ; 
        int sumMax = 0 ; 
        for ( j = m; j>=1 ; j--){
            int calResult = onCalStrongNum(j) ; 
            if (calResult == j && calResult >= sumMax && calResult < m ){
                sumMax = calResult ; 
                // printf("%d\n",calResult) ;
            }
        }
        printf("%d\n", sumMax) ; 
    }    
    if (0< n || n > 1000000){
        return  0 ; 
    }
    return 0 ;
}