#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width;j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.000);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRED = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGREEN = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBLUE = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            if (sepiaRED > 255)
            {
                sepiaRED = 255;
            }
            else if (sepiaRED < 0)
            {
                sepiaRED = 0;
            }
            else
            {
                sepiaRED += 0;
            }
            if (sepiaGREEN > 255)
            {
                sepiaGREEN = 255;
            }
            else if (sepiaGREEN < 0)
            {
                sepiaGREEN = 0;
            }
            else 
            {
                sepiaGREEN += 0;
            }
            if (sepiaBLUE > 255)
            {
                sepiaBLUE = 255;
            }
            else if (sepiaBLUE < 0)
            {
                sepiaBLUE = 0;
            }
            else 
            {
                sepiaBLUE += 0;
            }
            image[i][j].rgbtRed = sepiaRED;
            image[i][j].rgbtGreen = sepiaGREEN;
            image[i][j].rgbtBlue = sepiaBLUE;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRED = 0;
            int totalGREEN = 0;
            int totalBLUE = 0;
            float count = 0;
            
            if (i >= 0 && j >= 0)
            {
                totalRED += temp[i][j].rgbtRed;
                totalGREEN += temp[i][j].rgbtGreen;
                totalBLUE += temp[i][j].rgbtBlue;
                count += 1;
            }
            if (i >= 0 && (j - 1) >= 0)
            {
                totalRED += temp[i][j - 1].rgbtRed;
                totalGREEN += temp[i][j - 1].rgbtGreen;
                totalBLUE += temp[i][j - 1].rgbtBlue;
                count += 1;
            } 
            if ((i - 1) >= 0 && j >= 0)
            {
                totalRED += temp[i - 1][j].rgbtRed;
                totalGREEN += temp[i - 1][j].rgbtGreen;
                totalBLUE += temp[i - 1][j].rgbtBlue;
                count += 1;
            }
            if ((i - 1) >= 0 && (j - 1) >= 0)
            {
                totalRED += temp[i - 1][j - 1].rgbtRed;
                totalGREEN += temp[i - 1][j - 1].rgbtGreen;
                totalBLUE += temp[i - 1][j - 1].rgbtBlue;
                count += 1;
            }
            if ((i >= 0 && (j + 1) >= 0) && (i >= 0 && (j + 1) < width))
            {
                totalRED += temp[i][j + 1].rgbtRed;
                totalGREEN += temp[i][j + 1].rgbtGreen;
                totalBLUE += temp[i][j + 1].rgbtBlue;
                count += 1;
            }
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                totalRED += temp[i - 1][j + 1].rgbtRed;
                totalGREEN += temp[i - 1][j + 1].rgbtGreen;
                totalBLUE += temp[i - 1][j + 1].rgbtBlue;
                count += 1;
            }
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                totalRED += temp[i + 1][j].rgbtRed;
                totalGREEN += temp[i + 1][j].rgbtGreen;
                totalBLUE += temp[i + 1][j].rgbtBlue;
                count += 1;
            }
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                totalRED += temp[i + 1][j - 1].rgbtRed;
                totalGREEN += temp[i + 1][j - 1].rgbtGreen;
                totalBLUE += temp[i + 1][j - 1].rgbtBlue;
                count += 1;
            }
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                totalRED += temp[i + 1][j + 1].rgbtRed;
                totalGREEN += temp[i + 1][j + 1].rgbtGreen;
                totalBLUE += temp[i + 1][j + 1].rgbtBlue;
                count += 1;
            }
            image[i][j].rgbtRed = round(totalRED / count);
            image[i][j].rgbtGreen = round(totalGREEN / count);
            image[i][j].rgbtBlue = round(totalBLUE / count);
        }
        
    }
    return;
}
