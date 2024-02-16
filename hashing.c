#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 10

struct KeyValue
{
    char key[50];
    int value;
};

typedef struct Chain
{
    struct KeyValue *data;
    int count;
} Chain;

void initializeChain(Chain *chain)
{
    chain->data = malloc(TABLESIZE * sizeof(struct KeyValue));
    chain->count = 0;
}

void insert(Chain *chains, int tableSize, const char *key, int value)
{
    int index = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        index += key[i];
    }
    index %= tableSize;

    struct KeyValue *newData = &chains[index].data[chains[index].count];
    strcpy(newData->key, key);
    newData->value = value;
    chains[index].count++;
}

void display(Chain *chains, int tableSize)
{
    printf("dictionary contents:\n");
    for (int i = 0; i < tableSize; i++)
    {
        printf("chain %d:", i);
        for (int j = 0; j < chains[i].count; j++)
        {
            printf(" (%s,%d)", chains[i].data[j].key, chains[i].data[j].value);
        }
        printf("\n");
    }
}

int main()
{
    int tableSize;
    scanf("%d", &tableSize);

    struct Chain chains[TABLESIZE];
    for (int i = 0; i < TABLESIZE; i++)
    {
        initializeChain(&chains[i]);
    }

    for (int i = 0; i < tableSize; i++)
    {
        char key[50];
        int value;
        scanf("%s %d", key, &value);
        insert(chains, TABLESIZE, key, value);
    }

    display(chains, TABLESIZE);

    for (int i = 0; i < TABLESIZE; i++)
        free(chains[i].data);

    return 0;
}