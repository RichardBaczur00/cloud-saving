#include "data_structures/hashTable.h"

unsigned int hash(const char *key) {
    
    unsigned int hash = 0;
    
    while (*key) 
        hash = (hash * 31) + *(key++);

    return hash % HASH_TABLE_SIZE;

}

void insert(HashTable* table, const char* key, int value) {
    unsigned int index = hash(key);
    table->entries[index].key = key;
    table->entries[index].value = value;
}

int lookup(HashTable* table, const char* key) {
    unsigned int index = hash(key);
    return table->entries[index].value;
}