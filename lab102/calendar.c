#include <stdio.h>

int isLeapYear(int targetYear){
    if (targetYear%400 == 0 ){
        return 1 ; 
    }
    else if(targetYear %100 == 0 ){
        return 0 ; 
    }else if (targetYear % 4 == 0){
        return 1 ; 
    }
    return 0 ;
}

int onYearToDays(int year ,int month){
    int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayAmount = 1 ; 
    // year check is leap and cal amount of year
    for (int i = 1990 ; i<year ; i++){
        if (isLeapYear(i)){
            dayAmount+=366 ; 
        }
        else {
            dayAmount+=365 ;
        }
    }
    // printf("year %d\n", dayAmount) ; 
    // // month
    for (int i = 0 ; i<month-1 ; i++){
        if (isLeapYear(year) && i == 1){
            dayAmount += 29 ;
        }
        else if (month > 1){
            dayAmount += daysMonth[i] ; 
            }
        }
    
    return dayAmount ;

}

float onGetMonth(int year, int month){
    int amount ; 
    int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year) && month == 2 ){
        amount = 29 ; 
    }else {
        amount = daysMonth[month-1] ; 
    }
    return amount; 
}

int mathCeli(float amount ){
    int amountInt = (int)amount ;
    if (amount>amountInt){
        amountInt++ ; 
    }
    return amountInt ; 
}

void onPrintCalender(int year , int month){
    char* monthNames[] = { "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"} ;
    int dayAmount = onYearToDays(year,month) ; 
    int startDays = dayAmount%7 ; 
    float DayPerMonth = onGetMonth(year,month) ; 
    printf("====================\n") ;    
    printf("%s",monthNames[month-1]) ;
    printf(" %d\n",year) ;  
    printf("Sun Mon Tue Wed Thu Fri Sat\n") ;
    
    int weekAmount = mathCeli((startDays+DayPerMonth)/7) ;
    int dayCount = 1 ; 
    for (int i = 0 ; i<weekAmount ; i++){
        for (int j = 0 ; j<7 ; j++){
            if (startDays>0){
                if (j== 0 ){
                    printf("   ") ; 
                }else {
                    printf("    ") ;                    
                }
                startDays-- ; 
            }
            else if (dayCount<=DayPerMonth){
                if (j == 0){
                    if (dayCount<10){
                        printf("  %d",dayCount) ; 
                    }else{
                        printf(" %d",dayCount) ; 
                    }
                }else {
                    if (dayCount<10){
                        printf("   %d",dayCount) ; 
                    }else{
                        printf("  %d",dayCount) ; 
                    }
                }        
                dayCount++ ; 
            }
        }
        printf("\n") ; 
    }
}
int main(){
    int year , month ; 
    printf("Enter year: ") ; 
    scanf("%d",&year) ; 
    printf("Enter month: ") ; 
    scanf("%d",&month) ;
    onPrintCalender(year,month) ;

}