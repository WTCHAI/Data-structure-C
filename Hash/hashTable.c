#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item {
    char *text;
    struct item *next;
} item_t;

typedef struct hash {
    item_t **table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashTable(int size, int hashKey){
    hash_t *hashTable = (hash_t*)malloc(sizeof(hash_t));
    hashTable->hash_key = hashKey;
    hashTable->size = size ;
    hashTable->table = calloc(size , sizeof(item_t*));
    return hashTable;
}

item_t *createItem(char *text){
    item_t *node = (item_t*)malloc(sizeof(item_t));
    node->text = (char*)malloc(sizeof(char)*strlen(text));
    strcpy(node->text,text);
    node->next = NULL;
    return node;
}

unsigned int preHash(char *text, int hash_key){
    unsigned int hashValue = 0;
    for(int i = 0 ; i<strlen(text) ; i++){
        hashValue = hashValue*hash_key + text[i];
    }
    return hashValue;
}

unsigned int hashMap(unsigned int hashValue, int size){
    return hashValue % size;
}

void insert(hash_t *hashTable, char *text){
    //
    unsigned int hashMapping = hashMap(preHash(text,hashTable->hash_key),hashTable->size);
    item_t *data = createItem(text);

    if(hashTable->table[hashMapping] != NULL){
        data->next = hashTable->table[hashMapping];
    }
    hashTable->table[hashMapping] = data;
}

int search( hash_t *hashTable, char *text){
    unsigned int hashMapping = hashMap(preHash(text,hashTable->hash_key),hashTable->size);
    if(hashTable -> table[hashMapping] != NULL){
        item_t *temp = hashTable->table[hashMapping];
        while(temp != NULL){
            if(!strcmp( temp->text , text)){
                return hashMapping;
            }
            temp = temp->next;
        }
    }
    // if not found 
    return -1 ;
}

int main(void){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;

    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashTable(m, hash_key);
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