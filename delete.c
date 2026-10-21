#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

bool delete(char *key)
{
    int index = hash(key);
    node *current = table[index];
    node *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (previous == NULL)
            {
                table[index] = current->next; // Удаляем первый элемент цепочки
            }
            else
            {
                previous->next = current->next; // Удаляем из середины или конца
            }

            free(current);
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8); 
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }

    insert("apple", "яблоко");
    insert("banana", "банан");

    printf("Пытаемся удалить 'apple'...\n");
    if (delete("apple")) {
        printf("Элемент 'apple' успешно удален!\n");
    } else {
        printf("Элемент не найден.\n");
    }

    int idx = hash("apple");
    node *cursor = table[idx];
    int found = 0;
    while (cursor != NULL) {
        if (strcmp(cursor->key, "apple") == 0) found = 1;
        cursor = cursor->next;
    }

    if (found) {
        printf("Ошибка: 'apple' все еще в таблице.\n");
    } else {
        printf("Проверка: 'apple' действительно отсутствует в таблице.\n");
    }

    return 0;
}