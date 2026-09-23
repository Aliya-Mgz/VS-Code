#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    const char *name;
    int votes;
} candidate;

candidate candidates[] = {
    {"Aliya", 0},
    {"Madina", 0},
    {"Alice", 0}
};

int candidate_count = 3;

bool vote(const char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

int main(void)
{
    vote("Aliya");
    vote("Madina");
    vote("Alice");

    print_winner();

    return 0;
}