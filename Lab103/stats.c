#include <stdio.h>
#include <stdlib.h>

void findStats( int *numbers , double *avg , int *max , int *min , int n ) {
    double sum = 0 ;
    *avg = 0 ;

    for (int i = 0 ; i<n ; i++){
        if (i == 0 ){
            *min = *numbers  ; 
            *max = *numbers ; 
        }
        // printf("%d\n",*(numbers + i)) ; 
        sum+= *(numbers + i ) ;

        if (*max<*(numbers + i)){
            *max = *(numbers + i) ; 
        }
        else if (*min>*(numbers + i)){
            *min = *(numbers + i) ;
        }

    }
    // printf("%d\n",sum) ; 
    *avg = sum/n ;
}

int main() {
    int n, i, maxi, mini ;
    double avg ;
    int *nums ;

    scanf("%d", &n) ; 
    nums = (int *)malloc(sizeof (int) *n);
    for (i=0; i<n; i++)
        scanf("%d", nums+i);
    
    findStats(nums , &avg , &maxi , &mini , n) ;

    printf("%.2f %d %d", avg, maxi, mini);
    return 0 ;
}