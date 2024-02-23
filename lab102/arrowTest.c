#include <stdio.h>

int main() {


    // //Half top
    int size = 3 ; 
    int i , j , k ; 
    // upper part 
    for ( i = 0 ; i<size+1 ; i++){
        for ( j = size ; j > i ; j--){
            printf (" ") ;
        }

        for (k = 0 ; k<2+size+i ; k++){
            if ( i == 0 ){ 
                printf("#") ;
                break ;
            }
            else {
                printf("#") ; 
            }
        }    
        printf ("\n")  ; 
    }
    // lower part 
    for ( i = size ; i>0 ; i--){
        for ( j = 0 ; j <size-i+1 ; j++){
            printf (" ") ;

        }
        for (k = 1+size+i ; k>0 ; k--){
            if( i == 1 ){
                printf("#") ; 
                break ; 
            }else {
                printf("#") ;
            }

        }
        printf("\n") ; 
    }

}