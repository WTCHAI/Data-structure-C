#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    else if (n <= 3) {
        return 1;
    }
    else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i += 6;
    }
    return 1;
}

int main(){
    int targetNumber ; 
    scanf("%d",&targetNumber) ;
    int status = is_prime(targetNumber) ;
    printf("%d", status) ; 
}

// BigO =>sqrt(n)