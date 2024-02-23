#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int n ;
    scanf("%d",&n) ;

    // int numbers[n] ; 
    // int numbersCnt[n][2] ;
    // // get inp part
    // for (int i = 0 ; i<n ; i++ ){
    //     int inpNumber ; 
    //     scanf("%d",&inpNumber) ;
    //     numbers[i] = inpNumber ; 
    // }
    // // initial to numberCnt 
    // for (int i = 0 ; i<n ;i++){
    //     numbersCnt[i][0] = 0 ;
    //     numbersCnt[i][1] = 0 ; 
    // }



    // // process part
    // for ( int i=0 ; i<n ; i++){
    //     int Count = 0 ;
    //     int targetNumber = numbers[i] ;
    //     int isFind = false ; 
    //     for (int j = 0 ; j<n ; j++){
    //         if (numbers[j] == targetNumber){
    //             Count++ ; 
    //         }
    //     }

    //     for (int j = 0 ; j<n ; j++){
    //         if (i != 0 ){
    //             if (targetNumber == numbersCnt[j][0]){
    //                 isFind=true ; 
    //             }
    //         }
    //     }

    //     if (!isFind){
    //         numbersCnt[i][0] = targetNumber ; 
    //         numbersCnt[i][1] = Count ;    
    //     }
    // }

    // // get amount of numbers and there same count 
    // // filter to sort data 
    // // find max count 
    // int maxcount = 0; 
    // for (int i = 0 ; i<n ; i++){
    //     if (numbersCnt[i][0]!=0){
    //         if (numbersCnt[i][1]>maxcount){
    //             maxcount = numbersCnt[i][1] ; 
    //         }
    //         printf("%d %d\n",numbersCnt[i][0],numbersCnt[i][1]) ;
    //     }
    // }

    // printf("max count : %d\n",maxcount) ; 
    // // preapare data just only have equal max value 


    // int resultData[n] ; 
    // int index = 0 ; 
    // for (int i = 0 ; i<n ; i++){
    //     if (numbersCnt[i][0] != 0 ){
    //         if (numbersCnt[i][1] == maxcount){
    //             resultData[index] = numbersCnt[i][0] ; 
    //         }
    //     }
    // }

    // for (int i = 0 ; i<n ; i++){
    //     printf("%d \n",resultData[i]) ;
    // }

    // printf("=============\n") ; 

}