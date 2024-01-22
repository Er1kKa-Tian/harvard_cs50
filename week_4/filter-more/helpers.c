#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // average of RGB, round to the nearest int, and convert to int
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int temp_int = (int) (0.5 + ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float) 3));
            image[i][j].rgbtBlue = temp_int;
            image[i][j].rgbtGreen = temp_int;
            image[i][j].rgbtRed = temp_int;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image
    RGBTRIPLE image_temp[height][width];
    // use 2 nested loops in order to copy values, not pointers
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_temp[i][j] = image[i][j];
        }
    }
    // reflection
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_temp[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image
    RGBTRIPLE image_temp[height][width];
    // use 2 nested loops in order to copy values, not pointers
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_temp[i][j] = image[i][j];
        }
    }
    // blur
    // loop over inner image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int tempBlue = 0;
            int tempGreen = 0;
            int tempRed = 0;
            for (int n_x = -1; n_x <= 1; n_x++)
            {
                for (int n_y = -1; n_y <= 1; n_y++)
                {
                    if (i + n_x < 0 || i + n_x >= height || j + n_y < 0 || j + n_y >= width)
                    {
                        continue;
                    }
                    else
                    {
                        tempBlue += image_temp[i + n_x][j + n_y].rgbtBlue;
                        tempGreen += image_temp[i + n_x][j + n_y].rgbtGreen;
                        tempRed += image_temp[i + n_x][j + n_y].rgbtRed;
                        counter++;
                    }
                }
            }
            image[i][j].rgbtBlue = (int) (0.5 + (tempBlue / (float) counter));
            image[i][j].rgbtGreen = (int) (0.5 + (tempGreen / (float) counter));
            image[i][j].rgbtRed = (int) (0.5 + (tempRed / (float) counter));
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image and extend with boundaries
    RGBTRIPLE image_temp[height + 2][width + 2];
    // use 2 nested loops in order to copy values, not pointers, assign 0 to boundaries
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || i == height + 1 || j == 0 || j == width + 1)
            {
                image_temp[i][j].rgbtBlue = 0;
                image_temp[i][j].rgbtGreen = 0;
                image_temp[i][j].rgbtRed = 0;
            }
            else
            {
                image_temp[i][j] = image[i - 1][j - 1];
            }
        }
    }
    // calculation
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            // Gx
            float gxBlue;
            float gxGreen;
            float gxRed;
            gxBlue = image_temp[i - 1][j - 1].rgbtBlue * (-1) + image_temp[i - 1][j + 1].rgbtBlue * 1 + image_temp[i][j - 1].rgbtBlue * (-2) + image_temp[i][j + 1].rgbtBlue * 2 + image_temp[i + 1][j - 1].rgbtBlue * (-1) + image_temp[i + 1][j + 1].rgbtBlue * 1; // no rounding up
            gxGreen = image_temp[i - 1][j - 1].rgbtGreen * (-1) + image_temp[i - 1][j + 1].rgbtGreen * 1 + image_temp[i][j - 1].rgbtGreen * (-2) + image_temp[i][j + 1].rgbtGreen * 2 + image_temp[i + 1][j - 1].rgbtGreen * (-1) + image_temp[i + 1][j + 1].rgbtGreen * 1; // no rounding up
            gxRed = image_temp[i - 1][j - 1].rgbtRed * (-1) + image_temp[i - 1][j + 1].rgbtRed * 1 + image_temp[i][j - 1].rgbtRed * (-2) + image_temp[i][j + 1].rgbtRed * 2 + image_temp[i + 1][j - 1].rgbtRed * (-1) + image_temp[i + 1][j + 1].rgbtRed * 1; // no rounding up
            // Gy
            float gyBlue;
            float gyGreen;
            float gyRed;
            gyBlue = image_temp[i - 1][j - 1].rgbtBlue * (-1) + image_temp[i - 1][j].rgbtBlue * (-2) + image_temp[i - 1][j + 1].rgbtBlue * (-1) + image_temp[i + 1][j - 1].rgbtBlue * 1 + image_temp[i + 1][j].rgbtBlue * 2 + image_temp[i + 1][j + 1].rgbtBlue * 1; // no rounding up
            gyGreen = image_temp[i - 1][j - 1].rgbtGreen * (-1) + image_temp[i - 1][j].rgbtGreen * (-2) + image_temp[i - 1][j + 1].rgbtGreen * (-1) + image_temp[i + 1][j - 1].rgbtGreen * 1 + image_temp[i + 1][j].rgbtGreen * 2 + image_temp[i + 1][j + 1].rgbtGreen * 1; // no rounding up
            gyRed = image_temp[i - 1][j - 1].rgbtRed * (-1) + image_temp[i - 1][j].rgbtRed * (-2) + image_temp[i - 1][j + 1].rgbtRed * (-1) + image_temp[i + 1][j - 1].rgbtRed * 1 + image_temp[i + 1][j].rgbtRed * 2 + image_temp[i + 1][j + 1].rgbtRed * 1; // no rounding up
            // Aggregation
            int aggBlue;
            int aggGreen;
            int aggRed;
            aggBlue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            aggGreen = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            aggRed = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            if (aggBlue > 255)
            {
                image[i - 1][j - 1].rgbtBlue = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtBlue = aggBlue;
            }
            if (aggGreen > 255)
            {
                image[i - 1][j - 1].rgbtGreen = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtGreen = aggGreen;
            }
            if (aggRed > 255)
            {
                image[i - 1][j - 1].rgbtRed = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtRed = aggRed;
            }
        }
    }
    return;
}
