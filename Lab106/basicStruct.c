#include  <stdio.h>
#include <stdlib.h>
typedef struct temptempNode {
    int x ; 
    int y ; 

} tempstack ;  

int main (){
    int a = 5  ; 
    int *b = &a ;
    *b = 7  ; 
    printf("%d\n",*b) ; 
    int c = 12 ; 
    b = &c ;
    // s -> = temp ;  
    printf("%d\n",*b) ; 

    printf("%d\n", a ) ; 
    return 0 ; 
}