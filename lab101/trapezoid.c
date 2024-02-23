#include <stdio.h>
int main()
{
    int a;
    int b;
    int h;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("h: ");
    scanf("%d", &h);
    float cal = 0.5*(a+b)*h;
    printf("Area is %.1f",cal) ;
    return 0 ;
}
