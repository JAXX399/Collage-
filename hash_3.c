#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 50

int hashTable[TABLE_SIZE];

struct Node
{
    int key;
    struct Node *next;
};

struct Node *hashTable2[TABLE_SIZE];

void initializeHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

void initializeHashTable2()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable2[i] = NULL;
    }
}

int hash(int key)
{
    return key % 47;
}

int hash2(int key)
{
    return 7 - (key % 7);
}

// LINEAR PROBING
void insertLinearProbing(int key)
{
    int index = hash(key);
    int probes = 1;
    int i = 0;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return;
        }

        index = (index + i) % TABLE_SIZE;
        probes++;
        i++;
    }

    hashTable[index] = key;
    printf("Linear Probing: Inserted %d at location %d and no of probes %d\n", key, index, probes);
}

int searchLinearProbing(int key)
{
    int index = hash(key);
    int i = 0;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return index;
        }
        index = (index + i) % TABLE_SIZE;
        i++;

        // Linear probing
    }

    return -1;
}

int deleteLinearProbing(int key)
{
    int index = hash(key);
    int i = 0;
    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            hashTable[index] = -1;
            return index;
        }
        index = (index + i) % TABLE_SIZE; // Linear probing
        i++;
    }
    return -1;
}

// QUADRATIC PROBING
void insertQudraticProbing(int key)
{
    int index = hash(key);
    int i = 1;
    int probes = 0;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return;
        }
        index = (index + (i * i)) % TABLE_SIZE;
        i++;
    }

    hashTable[index] = key;
    printf("Qudratic Probing: Inserted %d at location %d and no of probes %d\n", key, index, probes);
}

int searchQudraticProbing(int key)
{
    int index = hash(key);
    int i = 1;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return index;
        }
        index = (index + (i * i)) % TABLE_SIZE;
        i++;
    }

    return -1;
}

int deleteQuadraticProbing(int key)
{
    int index = hash(key);
    int i = 1;
    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            hashTable[index] = -1;
            return index;
        }
        index = (index + (i * i)) % TABLE_SIZE;
        i++;
    }
    return -1;
}

// DOUBLE HASHING
void insertDoubleHashing(int key)
{
    int index = hash(key);
    int index2 = hash2(key);
    int probes = 0;
    int i = 0;
    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return;
        }
        index = (index + i * index2) % TABLE_SIZE;
        i++;
        probes++;
    }

    hashTable[index] = key;
    printf("Double Hashing: Inserted %d at location %d and no of probes %d\n", key, index, probes);
}

int searchDoubleHashing(int key)
{
    int index = hash(key);
    int step = hash2(key);

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return index;
        }
        index = (index + step) % TABLE_SIZE;
    }

    return -1;
}

int deleteDoubleHashing(int key)
{
    int index = hash(key);
    int step = hash2(key);

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            hashTable[index] = -1;
            return index;
        }
        index = (index + step) % TABLE_SIZE;
    }
    return -1;
}

// SEPARATE CHAINING
void insertSeparateChaining(int key)
{
    int index = hash(key);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    if (hashTable2[index] == NULL)
    {
        hashTable2[index] = newNode;
    }
    else
    {
        hashTable2[index]->next = newNode;
        newNode->next = NULL;
    }

    printf("Separate chaining: %d inserted at %d\n", key, index);
}

int searchSeparateChaining(int key)
{
    int index = hash(key);

    struct Node *current = hashTable2[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return index;
        }
        current = current->next;
    }

    return -1;
}

int deleteSeparateChaining(int key)
{

    int index = hash(key);

    if (hashTable2[index] == NULL)
    {
        return -1;
    }

    if (hashTable2[index]->key == key)
    {
        struct Node *temp = hashTable2[index];
        hashTable2[index] = hashTable2[index]->next;
        free(temp);
        return index;
    }

    // Search for the key to be deleted in the linked list
    struct Node *current = hashTable2[index];
    while (current->next != NULL)
    {
        if (current->next->key == key)
        {
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return index;
        }
        current = current->next;
    }

    return -1;
}

// OPTIONS
int search(int option, int key)
{
    int index = -1;
    if (option == 1)
    {
        index = searchLinearProbing(key);
    }
    else if (option == 2)
    {
        index = searchQudraticProbing(key);
    }
    else if (option == 3)
    {
        index = searchDoubleHashing(key);
    }
    else if (option == 4)
    {
        index = searchSeparateChaining(key);
    }

    if (index != -1)
    {
        printf("%d found at location %d\n.", key, index);
    }
    else
    {
        printf("%d not present in table\n.", key);
    }

    return index;
}

void insert(int option)
{
    for (int i = 0; i < 40; i++)
    {
        int num = rand() % 1000;
        if (option == 1)
        {
            insertLinearProbing(num);
        }
        else if (option == 2)
        {
            insertQudraticProbing(num);
        }
        else if (option == 3)
        {
            insertDoubleHashing(num);
        }
        else if (option == 4)
        {
            insertSeparateChaining(num);
        }
        else
        {
            printf("WRONG OPTION CHOSEN");
        }
    }
}

void insertByOption(int key, int option)
{
    int index = search(option, key);
    if (index == -1)
    {
        if (option == 1)
        {
            insertLinearProbing(key);
        }
        else if (option == 2)
        {
            insertQudraticProbing(key);
        }
        else if (option == 3)
        {
            insertDoubleHashing(key);
        }
        else if (option == 4)
        {
            insertSeparateChaining(key);
        }
    }
}

void delete(int option, int key)
{
    int index = -1;
    if (option == 1)
    {
        index = deleteLinearProbing(key);
    }
    else if (option == 2)
    {
        index = deleteQuadraticProbing(key);
    }
    else if (option == 3)
    {
        index = deleteDoubleHashing(key);
    }
    else if (option == 4)
    {
        index = deleteSeparateChaining(key);
    }
    else
    {
        printf("WRONG OPTION CHOSEN");
    }

    if (index != -1)
    {
        printf("%d deleted from location %d.", key, index);
    }
    else
    {
        printf("%d Not present in table.", key);
    }
}

int main()
{
    initializeHashTable();

    int option;
    printf("Please choose option for insertion: \n1)Linear Probing \t2)Quadratic Probing \t3)Double Hashing \t4)Separate Chaining\n");
    scanf("%d", &option);
    insert(option);

    int operation;
    printf("Please choose operation: \n1)Search \t2)Insert \t3)Delete \n");
    scanf("%d", &operation);

    int num;
    printf("Please enter no for opertaion: ");
    scanf("%d", &num);
    if (operation == 1)
    {
        search(option, num);
    }
    else if (operation == 2)
    {
        insertByOption(num, option);
    }
    else
    {
        delete (option, num);
    }

    return 0;
}
