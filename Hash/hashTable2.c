#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
    item_t *table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashtable(int size, int hashKey){
    hash_t *hashTable = (hash_t*)malloc(sizeof(hash_t));
    hashTable->hash_key = hashKey;
    hashTable->size = size;
    hashTable->table = calloc(size, sizeof(item_t));
    return hashTable;
}

unsigned int preHash(char *text, int hashKey){
    unsigned int hashValue = 0;
    for(int i = 0 ; i<strlen(text) ; i++){
        hashValue = hashValue*hashKey + text[i];
    }
    return hashValue;
}

unsigned int hashMap(unsigned int hashValue, int size){
    return hashValue % size;
}

void insert(hash_t *hashTable, char *text){
    char *data = (char*)malloc(sizeof(char)*strlen(text));
    strcpy(data, text);
    unsigned int hashInit = hashMap(preHash(text,hashTable->hash_key),hashTable->size);
    unsigned int i = 0, hashIndex;
    //if case 
    do{
        hashIndex = (hashInit + (i+i*i)/2) % hashTable->size;
        i++;
    } while (hashTable->table[hashIndex] != NULL);
    hashTable->table[hashIndex] = data;
}

int search(hash_t *hashtable, char *text){
    unsigned int hashInit = hashMap(preHash(text,hashtable->hash_key),hashtable->size);
    unsigned int i = 0, hashIndex;

    do{
        hashIndex = (hashInit + (i+i*i)/2) % hashtable->size;
        if(hashtable->table[hashIndex] != NULL && !strcmp(hashtable->table[hashIndex],text)){
            return hashIndex;
        }
        i++;
    } while (hashtable->table[hashIndex] != NULL);

    return -1;
}

int main(void) {
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;
    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char)*TEXTSIZE);
    for (i=0; i<n; i++) {
        scanf("%d %s", &command, text);
        switch (command) {
            case 1:
                insert(hashtable, text);
                break;
            case 2:
                printf("%d\n",search(hashtable, text));
                break;
        }
    }
    return 0;
}