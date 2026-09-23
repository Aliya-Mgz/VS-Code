#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[1000];
    fgets(text, 1000, stdin);

    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    words++;

    printf("Letters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentences);

    return 0;
}
