#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 50
#define SECOND_HASH_CONSTANT 7

// Hash function: k mod 47
int hashFunction(int key) {
    return key % 47;
}

// Second hash function for double hashing: 7 - (k mod 7)
int secondHashFunction(int key) {
    return SECOND_HASH_CONSTANT - (key % SECOND_HASH_CONSTANT);
}

// Data structure for each hash table entry
typedef struct {
    int value;
    bool occupied;
} HashEntry;

// Hash table using separate chaining
typedef struct {
    HashEntry entries[TABLE_SIZE];
} HashTable;

// Initialize hash table entries
void initializeHashTable(HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable->entries[i].value = -1;
        hashTable->entries[i].occupied = false;
    }
}

// Insert value into the hash table using linear probing
void linearProbingInsert(HashTable *hashTable, int value) {
    int index = hashFunction(value);
    int probes = 0;
    
    while (hashTable->entries[index].occupied) {
        ++probes;
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable->entries[index].value = value;
    hashTable->entries[index].occupied = true;

    printf("Linear Probing: Inserted %d at index %d with %d probes\n", value, index, probes);
}

// Insert value into the hash table using quadratic probing
void quadraticProbingInsert(HashTable *hashTable, int value) {
    int index = hashFunction(value);
    int probes = 0;
    int i = 1;

    while (hashTable->entries[index].occupied) {
        ++probes;
        index = (index + i * i) % TABLE_SIZE;
        ++i;
    }

    hashTable->entries[index].value = value;
    hashTable->entries[index].occupied = true;

    printf("Quadratic Probing: Inserted %d at index %d with %d probes\n", value, index, probes);
}

// Insert value into the hash table using double hashing
void doubleHashingInsert(HashTable *hashTable, int value) {
    int index = hashFunction(value);
    int probes = 1;
    int step = secondHashFunction(value);

    while (hashTable->entries[index].occupied) {
        ++probes;
        index = (index + step) % TABLE_SIZE;
        
    }

    hashTable->entries[index].value = value;
    hashTable->entries[index].occupied = true;

    printf("Double Hashing: Inserted %d at index %d with %d probes\n", value, index, probes);
}

// Insert value into the hash table using separate chaining
void separateChainingInsert(HashTable *hashTable, int value) {
    int index = hashFunction(value);

    // Check if the bucket is empty
    if (!hashTable->entries[index].occupied) {
        hashTable->entries[index].value = value;
        hashTable->entries[index].occupied = true;
    } else {
        // Handle collision using separate chaining
        printf("Separate Chaining: Collision detected at index %d\n", index);
        // You can use linked lists or other data structures for chaining here
    }
}

int main() {
    HashTable hashTable;
    initializeHashTable(&hashTable);

    srand(time(NULL)); 
    // Seed the random number generator

    // Generate and insert 40 random numbers
    for (int i = 0; i < 40; ++i) {
        int value = rand() % 1000;
        
        linearProbingInsert(&hashTable, value);
        quadraticProbingInsert(&hashTable, value);
        doubleHashingInsert(&hashTable, value);
        separateChainingInsert(&hashTable, value);
        
        printf("\n");

    }

    return 0;
}
