#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char BYTE;

typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} RGBTRIPLE;

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round(
                (image[i][j].rgbtRed +
                 image[i][j].rgbtGreen +
                 image[i][j].rgbtBlue) / 3.0
            );

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepiaRed = round(
                0.393 * red + 0.769 * green + 0.189 * blue
            );

            int sepiaGreen = round(
                0.349 * red + 0.686 * green + 0.168 * blue
            );

            int sepiaBlue = round(
                0.272 * red + 0.534 * green + 0.131 * blue
            );

            image[i][j].rgbtRed =
                (sepiaRed > 255) ? 255 : sepiaRed;

            image[i][j].rgbtGreen =
                (sepiaGreen > 255) ? 255 : sepiaGreen;

            image[i][j].rgbtBlue =
                (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];

            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int row = i + di;
                    int col = j + dj;

                    if (row >= 0 && row < height &&
                        col >= 0 && col < width)
                    {
                        redSum += copy[row][col].rgbtRed;
                        greenSum += copy[row][col].rgbtGreen;
                        blueSum += copy[row][col].rgbtBlue;

                        count++;
                    }
                }
            }

            image[i][j].rgbtRed =
                round((float) redSum / count);

            image[i][j].rgbtGreen =
                round((float) greenSum / count);

            image[i][j].rgbtBlue =
                round((float) blueSum / count);
        }
    }
}

int main(void)
{
    printf("All four image filters are ready!\n");
    return 0;
}