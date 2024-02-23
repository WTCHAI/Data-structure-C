#include <stdio.h> 

int onCeli(float value){
    int checkValue = (int)(value) ; 
    return value > checkValue ? checkValue+=1 : checkValue ; 
}

int main (){
    int x , y , z ; 
    char firstType , secondType ; 
    scanf("%d %d %d", &x, &y , &z) ;
    scanf(" %c %c",&firstType , &secondType) ; 

    float calSum = x ;
    if (firstType == 'y' || firstType == 'Y') {
        calSum += y ; 
    }
    if (secondType == 'y' || secondType == 'Y'){
        calSum = onCeli((float)(calSum/z)) ; 
    }

    printf("%0.f\n",calSum) ; 
    return 0 ;
}