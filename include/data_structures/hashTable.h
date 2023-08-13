#ifndef HASHTABLE_H_INCLUDED

#define HASHTABLE_H_INCLUDED

#include <stdio.h>
#include <string.h>

#define HASH_TABLE_SIZE 500

typedef struct {
    const char* key;
    int value;
} Entry;

typedef struct {
    Entry entries[HASH_TABLE_SIZE];
} HashTable;

unsigned int hash(const char*);
void insert(HashTable*, const char*, int);
int lookup(const HashTable*, const char*);

#endif