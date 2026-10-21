#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TABLE_SIZE 10

typedef struct node
{
    char key[50];
    char value[100];
    struct node *next;
} node;

node *table[TABLE_SIZE];

int hash(char *word)
{
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += word[i];
    }
    return sum % TABLE_SIZE;
}

void insert(char *key, char *value)
{
    int index = hash(key);
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return;

    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = table[index];
    table[index] = new_node;
}


void free_table(void)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        node *current = table[i];

        while (current != NULL)
        {
            node *next = current->next; 
            free(current);             
            current = next;            
        }

        table[i] = NULL; 
    }
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8); 
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }

    insert("cat", "кошка");
    insert("dog", "собака");
    insert("mouse", "мышь");

    printf("Данные успешно добавлены в хэш-таблицу.\n");

    free_table();

    printf("Вся динамическая память хэш-таблицы успешно очищена!\n");

    return 0;
}