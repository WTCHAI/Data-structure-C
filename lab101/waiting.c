#include <stdio.h>
int main(){
    int x , y ; 
    scanf("%d %d",&x,&y) ; 
    if (0 <= x && x < 24 && 0 <= y && y <= 10000) {
        int sumHours = x+y ; 
        int calDays = (sumHours/24) ; 
        int calHoursLeft = sumHours%24 ; 
        printf("%d ",calDays) ; 
        printf("%d",calHoursLeft) ; 
    }

    return 0 ; 

}