#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sort(char* string) {
    char* result = malloc((strlen(string)) * sizeof(char));
    strcpy(result, string);

    for(int i = 1 ; i<strlen(string) ; i++){
        char check = result[i];
        for(int j = i ; j>0 ; j--){
            if(check < result[j-1]){
                result[j] = result[j-1];
                result[j-1] = check;
            }
            else{
                break;
            }
        }
    }
    return result;
}

int IsAnagram(char *targetText , char *CheckText){
    if (strlen(targetText) == strlen(CheckText)){
        char *sortedTargetText = sort(targetText) ; 
        char *sortedCheckText = sort(CheckText) ;    
        if(!strcmp(sortedCheckText,sortedTargetText)){
            free(sortedCheckText) ; 
            free(sortedTargetText) ; 
            return 1 ; 
        }
    }
    return 0 ; 
}


int main(){
    int amount , amountC ; 
    scanf("%d %d",&amount,&amountC) ; 

    //keep data 
    char **textData = calloc(amount,sizeof(char*)) ;
    for (int i = 0  ; i < amount ; i++){
        textData[i] = malloc(51*sizeof(char)) ; 
        scanf("%50s", textData[i]);  // Corrected format specifier
    }

    char *targetText = NULL ; 
    for (int i = 0 ; i < amountC ; i++){ 
        targetText = malloc(51 * sizeof(char));  // Allocate memory for targetText
        scanf("%50s", targetText);  // Corrected format specifier
        for (int j = 0 ; j < amount ; j++){
            if(IsAnagram(targetText,textData[j])){
                printf("%s ",textData[j]); 
            }
        }
        printf("\n"); 
        free(targetText);  // Free the memory for targetText
    } 

    //free
    for(int i = 0; i < amount; i++){
        free(textData[i]);
    }
    free(textData);

    return 0;
}