#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TABLE_SIZE 10

int simple_hash(char *word)
{
    int sum = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += word[i];
    }

    return sum % TABLE_SIZE;
}

int better_hash(char *word)
{
    unsigned long hash = 5381;

    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = ((hash << 5) + hash) + word[i]; // hash * 33 + c
    }

    return hash % TABLE_SIZE;
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8); 
    char *words[] = {
        "listen", "silent",
        "evil", "vile",
        "stone", "tones",
        "apple", "banana",
        "orange", "grape",
        "melon", "lemon",
        "cat", "act",
        "dog", "god",
        "table", "chair",
        "school", "course"
    };

    int word_count = 20;

    int simple_collisions = 0;
    int better_collisions = 0;

    int simple_table[TABLE_SIZE] = {0};
    int better_table[TABLE_SIZE] = {0};

  
    for (int i = 0; i < word_count; i++)
    {
        int simple_index = simple_hash(words[i]);
        if (simple_table[simple_index] > 0)
        {
            simple_collisions++; 
        }
        simple_table[simple_index]++;

        // Проверка для улучшенного хэша
        int better_index = better_hash(words[i]);
        if (better_table[better_index] > 0)
        {
            better_collisions++; 
        }
        better_table[better_index]++;
    }

    printf("Коллизий при простом хэше: %i\n", simple_collisions);
    printf("Коллизий при улучшенном хэше: %i\n", better_collisions);

    return 0;
}