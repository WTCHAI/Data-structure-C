#include <stdio.h>
#include <stdlib.h>

int main(){
    char a , b ; 
    scanf("%c %c",&a,&b) ; 
    int asciivalueA = a ; 
    int asciivalueB = b ;
    int calDiff = abs(asciivalueA-asciivalueB) ; 
    printf("%d",calDiff); 
    // printf("A value : %d\n",a);
    // printf("B value : %d\n",b) ;
    return 0 ; 
}