#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

typedef char *string;

static int get_int(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    int value;
    if (scanf("%d", &value) != 1)
    {
        return 0;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // consume trailing input
    }

    return value;
}

static string get_string(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return NULL;
    }

    size_t len = strlen(buffer);
    while (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r'))
    {
        buffer[--len] = '\0';
    }

    string result = malloc(len + 1);
    if (result == NULL)
    {
        return NULL;
    }

    strcpy(result, buffer);
    return result;
}

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];
typedef struct
{
    char name[100];
    int votes;
    bool eliminated;

} candidate;

candidate candidates[MAX_CANDIDATES];
int candidate_count;
int voter_count;

bool vote(int voter, int rank, char name[100]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
           string name = get_string("Rank %i: ", j + 1);
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    {
        while (true)
        {
            tabulate();

            bool won = print_winner();
            if (won)
            {
                break;
            }

            int min = find_min();
            bool tie = is_tie(min);

            if (tie)
            {
                for (int i = 0; i < candidate_count; i++)
                {
                    if (!candidates[i].eliminated)
                    {
                        printf("%s\n", candidates[i].name);
                    }
                }
                break;
            }
            eliminate(min);
            for (int i = 0; i < candidate_count; i++)
            {
                candidates[i].votes = 0;
            }
        }
        return 0;
    }
}

bool vote(int voter, int rank, char name[100])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for (int i = 0; i < candidate_count ; i++)
    {
    candidates[i].votes = 0;
    }
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            int candidate_index = preferences[voter][rank];
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
}

bool print_winner(void)
{
    int threshold = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > threshold)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;

}

int find_min(void)
{
    int min_votes = voter_count + 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}