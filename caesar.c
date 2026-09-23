#include <stdio.h>
#include <ctype.h>

int main()
{
    int num;
    char text[100];
    
    printf("Enter a positive number: ");
    while (scanf("%d", &num) != 1 || num <= 0)
{
    printf("Wrong! Enter a positive number: ");

    while (getchar() != '\n');
}

    while (getchar() != '\n');

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Encrypted: ");

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (isupper((unsigned char)c))
        {
            c = (c - 'A' + num) % 26 + 'A';
        }
        else if (islower((unsigned char)c))
        {
            c = (c - 'a' + num) % 26 + 'a';
        }

        printf("%c", c);
    }

    printf("\n");

    return 0;
}