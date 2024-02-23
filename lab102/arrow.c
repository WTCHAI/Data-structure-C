#include <stdio.h>

int main(){
    char type ; 
    int size ; 
    scanf("%c %d",&type, &size) ;
    if (size>100){
        return 0 ;
    }
    if (type == 'N'){
        // upper part
        for (int i = 0 ; i<=size ; i++ ){
            for (int j = 0 ; j<size-i ; j++){
                printf(" ") ;   
            }
            for (int k = 0 ;k<2*i+1 ; k++){
                printf("#") ; 
            }
        printf("\n") ;
        }

    // lower part 
        for(int i = 0 ; i <=size ; i++){
            printf(" ") ; 
            for (int j = 0 ; j<2*size-1 ;j++){
                printf("#") ; 
            }
            printf("\n") ; 
        }
    }
    else if (type == 'W'){
    // upper part 
        for ( int i = 0 ; i<size+1 ; i++){
            for ( int j = size ; j > i ; j--){
                printf (" ") ;
            }

            for (int k = 0 ; k<2+size+i ; k++){
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
        for ( int i = size ; i>0 ; i--){
            for ( int j = 0 ; j <size-i+1 ; j++){
                printf (" ") ;

            }
            for (int k = 1+size+i ; k>0 ; k--){
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
    else if (type == 'S'){
        // upper part
        for(int i = 0 ; i <=size ; i++){
            printf(" ") ; 
            for (int j = 0 ; j<2*size-1 ;j++){
                printf("#") ; 
            }
            printf("\n") ;
        }
        for(int j = 0 ; j<2*size+1 ; j++){
            printf("#") ; 
        }
        printf("\n") ; 

        // lower part 
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= i ; j++) {
                printf(" ");
            }
            for (int k = 1; k <= 2 * (size - i) + 1; k++) {
                printf("#");
            }
            printf("\n");
        }
    }
    else if (type == 'E'){
                // upper loop 
        for (int i = 0 ; i<=size ; i++){
            if (i == 0 ){
                for (int j = 0 ; j<size+1 ; j++){
                    printf(" ") ; 
                }
                printf("#\n") ; 
            }else {
                for (int j = 0 ; j<size+2+i ; j++){
                    printf("#") ; 
                }
                printf("\n") ; 
            }
        }
        // lower part 
        for (int i = size ; i > 0 ; i--){
            if (i == 1 ){
                for (int j = 0 ; j<size+1 ; j++){
                    printf(" ") ; 
                }
                printf("#\n") ; 
            }
            else {
                for (int j = 0 ;  j <size+1+i ; j++){
                    printf("#") ; 
                }
                printf("\n") ;         
            }
        }
    }
    return 0 ; 
}

