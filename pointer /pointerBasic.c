#include <stdio.h>

void onTestFunction(int *pointer){
    printf("From function \n") ;
    printf("\n : %p",pointer) ;
    *pointer = 20 ; 
    printf("\n%d : ",*pointer) ;
    return ; 
}

int main (){
    int x = 10 ; 
    int *pX = &x ;
    // pointer is only eep address of x  adding * is value at address
    // but *pointer is value of x  
    printf("%d : x ", x) ; 
    printf("\nvalue : %d",*pX ) ; 
    printf("\naddress : %p\n",pX) ; 
    onTestFunction(pX) ;   
    printf("\nvalue : \n",*pX) ; 

}