#include <stdio.h>
#include <math.h>

int onCalLastNumber(int targetNumber);

int estatePlanner (int w , int l ){
    // int onCalO ; 
    // find the most space that beable to fit with 2**n
    int lessNumber ; 
    int sizeNumber ; 
    if (w<=l){
        lessNumber = w ; 
    }
    else if (w>l){
        // another case  
        lessNumber = l ; 
    }
    sizeNumber = onCalLastNumber(lessNumber) ;

    int onSumSquare = 0 ; 
    if ( w == 0 || l == 0 ){
        onSumSquare = 0 ;  
    }
    else if (w != sizeNumber && l != sizeNumber)
    {
        onSumSquare = estatePlanner(w-sizeNumber,l) + estatePlanner(l - sizeNumber , sizeNumber) + 1 ; 
    }
    else if (w != sizeNumber)
    {
        onSumSquare = estatePlanner(w - sizeNumber, l) + 1;
    }
    else if (l != sizeNumber)
    {
        onSumSquare = estatePlanner(w, l - sizeNumber) + 1;
    }
    else
    {
        if (w < l)
        {
            onSumSquare = l / sizeNumber;
        }
        else
        {
            onSumSquare = w / sizeNumber;
        }
    }
    // onCalO+=1 ; 
    // printf("cal O :  %d\n",onCalO) ;
    return onSumSquare;
}

int onCalLastNumber(int targetNumber)
{
    int num;
    for (int i = 0; pow(2, i) <= targetNumber; i++)
    {
        num = pow(2, i);
    }
    return num;
}

int main()
{
    int w, l;
    scanf("%d %d", &w, &l);
    int result = estatePlanner(w, l);
    printf("%d\n", result);
}

// big O as can see there's recursive it be log(n)
