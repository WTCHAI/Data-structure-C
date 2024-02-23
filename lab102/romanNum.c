#include <stdio.h>

void numberToRoman(int targetNumber ){
    int romanAmount[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* romanSymbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int index = 0 ; 
    while(targetNumber > 0){
        if (targetNumber>=romanAmount[index]){
                printf("%s",romanSymbol[index]) ; 
                targetNumber -= romanAmount[index] ; 
        }else{
            index ++ ; 
        }
    }
}


int main(){
    int targetNumber , amountRound ; 
    scanf("%d",&amountRound) ; 

    for (int i = 0 ; i<amountRound ; i++){
        scanf("%d",&targetNumber) ;
        numberToRoman(targetNumber) ;  
        printf("\n") ; 
    }
    return 0 ; 
}

