#include <stdio.h>
int main(){
    long int time_taget ; 
    scanf("%ld",&time_taget) ;
    if (0<=time_taget<=4e9){
        int secLeft ; 
        int calDays = (int)(time_taget/(60*60*24));
        secLeft = time_taget%(60*60*24) ;
        int calHours = (int)(secLeft/(60*60)) ;
        secLeft = time_taget%(60*60) ; 
        int calMin = (int)(secLeft/(60)) ;
        secLeft = secLeft%(60) ; 
        printf("%d\n",calDays) ; 
        printf("%d\n",calHours) ;
        printf("%d\n",calMin) ; 
        printf("%d\n",secLeft) ; 


    }
    return 0 ; 
}