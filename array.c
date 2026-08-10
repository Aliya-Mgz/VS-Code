#include <stdio.h>

int main() {
    int highscore[5];
    highscore[0] = 100;
    highscore[1] = 200;
    highscore[2] = 300;
    highscore[3] = 400;
    highscore[4] = 500;

for (int i = 0; i < 5; i++)

{
    printf("High score %d: %d\n", i + 1, highscore[i]);
}
return 0;
}