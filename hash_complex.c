

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 50

// hash function
int hash(int key) { return key % 47; }

// second hash function
int second_hash(int key) { return 7 - (key % 7); }

typedef struct node
{
  int data;
  struct node *next;
} node;

struct node *separate_chaining_table[SIZE];
int linear_probing_table[SIZE];
int quadratic_probing_table[SIZE];
int double_hashing_table[SIZE];

int search_separate_chaining(int key, node *chain_array[])
{
  int pos = hash(key);
  node *start = chain_array[pos];

  while (start != NULL)
  {
    if (start->data == key)
    {
      return pos;
    }
    start = start->next;
  }
  return -1;
}

void insert_separate_chaining(int key, node *chain_array[])
{
  int pos = hash(key);

  if (search_separate_chaining(key, chain_array) != -1)
  {
    printf("elem is already present\n");
    return;
  }

  if (chain_array[pos] == NULL)
  {
    chain_array[pos] = (node *)malloc(sizeof(node));
    chain_array[pos]->data = key;
    chain_array[pos]->next = NULL;
  }
  else if (chain_array[pos]->data == key)
  {
    return;
  }
  else
  {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = key;
    temp->next = chain_array[pos];
    chain_array[pos] = temp;
  }
  printf("(linear probing)-> inserting at index %d "
         "is %d\n",
         key, pos);
}

void delete_separate_chaining(int key, node *chain_array[])
{
  int pos = hash(key);

  node *current = chain_array[pos];
  node *prev = NULL;

  while (current != NULL && current->data != key)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
  {
    printf("element not found");
    return;
  }

  if (prev == NULL)
  {
    chain_array[pos] = current->next;
    free(current);
  }
  else
  {
    prev->next = current->next;
    free(current);
  }

  printf("the element has been deleted\n");
}

int search_linear_probing(int key, int linear[])
{
  int pos = hash(key);

  while (linear[pos] != -1)
  {
    if (linear[pos] == key)
    {
      return pos;
    }
    pos = (pos + 1) % SIZE;

  }
  return -1;
}

void insert_linear_probing(int key, int linear[])
{
  int pos = hash(key);
  int probe = 1;

  if (search_linear_probing(key, linear_probing_table) != -1)
  {
    printf("the element is already present\n");
    return;
  }

  while (linear[pos] != -1 && linear[pos] != -2)
  {
    pos = (pos + 1) % SIZE;
    probe++;

  }

  linear[pos] = key;
  printf("(linear probing) the number of probes for inserting %d at index %d "
         "is %d\n",
         key, pos, probe);
}

// bring back all the keys
void delete_linear_probling(int key, int linear[])
{
  int pos = hash(key);

  if (search_linear_probing(key, linear_probing_table) == -1)
  {
    return;
  }

  while (linear[pos] != -1)
  {
    if (linear[pos] == key)
    {
      
      linear[pos] = -2;
      return;
    }
    pos = (pos + 1) % SIZE;
  }
}
int search_quadratic_probling(int key, int quadratic[])
{
  int pos = hash(key);

  int i = 1;
  while (quadratic[pos] != -1)
  {
    if (quadratic[pos] == key)
    {
      return pos;
    }
    pos = (pos + i * i) % SIZE;
    i++;
  }
  return -1;
}

void insert_quadratic_probling(int key, int quadratic[])
{
  int pos = hash(key);
  int probe = 1;

  int i = 1;
  while (quadratic[pos] != -1 && quadratic[pos] != -2)
  {
    pos = (pos + i * i) % SIZE;
    probe++;
    i++;
  }

  quadratic[pos] = key;
  printf("(quadratic probin) the number of probes for inserting %d at index %d "
         "is %d\n",
         key, pos, probe);
}

void delete_quadratic_probing(int key, int quadratic[])
{
  int pos = hash(key);

  int i = 1;
  while (quadratic[pos] != -1)
  {
    if (quadratic[pos] == key)
    {
      quadratic[pos] = -1;
      return;
    }
    pos = (pos + i * i) % SIZE;
    i++;
  }
}

int search_double_hashing(int key, int double_hash[])
{
  int pos = hash(key);
  int second = second_hash(key);
  while (double_hash[pos] != -1 && double_hash[pos] != -2)
  {
    if (double_hash[pos] == key)
    {
      return pos;
    }
    pos = (pos + second) % SIZE;
  }
  return -1;
}

void insert_double_hashing(int key, int double_hash[])
{
  int pos = hash(key);
  int probe = 1;
  int second = second_hash(key);

  while (double_hash[pos] != -1 && double_hash[pos] != -2)
  {
    pos = (pos + second) % SIZE;
    probe++;
  }

  double_hash[pos] = key;
  printf(
      "(double hash) the number of probes for inserting %d at index %d is %d\n",
      key, pos, probe);
}

void delete_double_hashing(int key, int double_hash[])
{
  int pos = hash(key);
  int second = second_hash(key);

  if (!search_double_hashing(key, double_hash))
  {
    return;
  }

  while (double_hash[pos] != -1)
  {
    if (double_hash[pos] == key)
    {
      double_hash[pos] = -2;
      return;
    }
    pos = (pos + second) % SIZE;
  }
}

int main()
{
  for (int i = 0; i < SIZE; i++)
  {
    linear_probing_table[i] = -1;
    quadratic_probing_table[i] = -1;
    double_hashing_table[i] = -1;
    separate_chaining_table[i] = NULL;
  }

  // // insert 40 random numbers
  for (int i = 0; i < 40; i++)
  {
    int n = rand() % 1000;
    insert_separate_chaining(n, separate_chaining_table);
    insert_double_hashing(n, double_hashing_table);
    insert_linear_probing(n, linear_probing_table);
    insert_quadratic_probling(n, quadratic_probing_table);
  }

  int greeting = 1;
  while (1)
  {
    if (greeting)
    {
      printf("welcome to Aarish's hashing program\n");
      greeting = 0;
    }
    printf("select one of the hashing lists you want to perform your operation "
           "in\n");
    printf(
        " Separate Chaining (1) \n Linear Probing(2) \n Quadratic Probing(3) "
        "\n Double Hashing(4) \n or Terminate your program(0)");
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
      printf("do you want to insert(1), search(2) or delete(3)\n");
      int inner_x;
      scanf("%d", &inner_x);
      if (inner_x == 1)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        insert_separate_chaining(data, separate_chaining_table);
      }
      else if (inner_x == 2)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        int ans = search_separate_chaining(data, separate_chaining_table);
        if (ans == -1)
        {
          printf("the element is not found in the list\n");
        }
        else
        {
          printf("the element is present at the %dth posititon\n", ans);
        }
      }
      else if (inner_x == 3)
      {
        printf("enter the key you want to delete\n");
        int data;
        scanf("%d", &data);
        delete_separate_chaining(data, separate_chaining_table);
      }
      else
      {
        printf("please enter a valid option\n");
        continue;
      }
    }
    else if (x == 2)
    {
      printf("do you want to insert(1), search(2) or delete(3)\n");
      int inner_x;
      scanf("%d", &inner_x);
      if (inner_x == 1)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        insert_linear_probing(data, linear_probing_table);
      }
      else if (inner_x == 2)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        int ans = search_linear_probing(data, linear_probing_table);
        if (ans == -1)
        {
          printf("the element is not found in the list\n");
        }
        else
        {
          printf("the element is present at the %dth posititon\n", ans);
        }
      }
      else if (inner_x == 3)
      {
        printf("enter the key you want to delete\n");
        int data;
        scanf("%d", &data);
        delete_linear_probling(data, linear_probing_table);
      }
      else
      {
        printf("please enter a valid option\n");
        continue;
      }
    }
    else if (x == 3)
    {
      printf("do you want to insert(1), search(2) or delete(3)\n");
      int inner_x;
      scanf("%d", &inner_x);
      if (inner_x == 1)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        insert_quadratic_probling(data, quadratic_probing_table);
      }
      else if (inner_x == 2)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        int ans = search_quadratic_probling(data, quadratic_probing_table);
        if (ans == -1)
        {
          printf("the element is not found in the list\n");
        }
        else
        {
          printf("the element is present at the %dth posititon\n", ans);
        }
      }
      else if (inner_x == 3)
      {
        printf("enter the key you want to delete\n");
        int data;
        scanf("%d", &data);
        delete_quadratic_probing(data, quadratic_probing_table);
      }
      else
      {
        printf("please enter a valid option\n");
        continue;
      }
    }
    else if (x == 4)
    {
      printf("do you want to insert(1), search(2) or delete(3)\n");
      int inner_x;
      scanf("%d", &inner_x);
      if (inner_x == 1)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        insert_double_hashing(data, double_hashing_table);
      }
      else if (inner_x == 2)
      {
        printf("please enter the data\n");
        int data;
        scanf("%d", &data);
        int ans = search_double_hashing(data, double_hashing_table);
        if (ans == -1)
        {
          printf("the element is not found in the list\n");
        }
        else
        {
          printf("the element is present at the %dth posititon\n", ans);
        }
      }
      else if (inner_x == 3)
      {
        printf("enter the key you want to delete\n");
        int data;
        scanf("%d", &data);
        delete_double_hashing(data, double_hashing_table);
      }
      else
      {
        printf("please enter a valid option\n");
        continue;
      }
    }
    else if (x == 0)
    {
      printf("The program has been successfully terminated\n");
      exit(0);
    }
    else
    {
      printf("please select a valid option\n");
      continue;
    }
  }

  return 0;
}