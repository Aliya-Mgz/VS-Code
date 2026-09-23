#include <stdio.h>
#include <ctype.h>

int main()
{
    char word1[100];
    char word2[100];

    int points[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

    
    scanf("%s", word1);
    scanf("%s", word2);

    int score1 = 0;

    for (int i = 0; word1[i] != '\0'; i++)
    {
        score1 += points[toupper(word1[i]) - 'A']; 
    }

    int score2 = 0;

    for (int i = 0; word2[i] != '\0'; i++)
    {
        score2 += points[toupper(word2[i]) - 'A']; 
    }

    if (score1 > score2)
    {
        printf("Word 1 wins!\n");
    }
else if (score2 > score1)
{
    printf("Word 2 wins!\n");
}
else
{
    printf("Draw!\n");
}
}
