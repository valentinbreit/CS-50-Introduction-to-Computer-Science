#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

float Quantity(string Paragraph);
int QuantityLetters(string Paragraph);
int QuantityWords(string Paragraph);
int QuantitySentences(string Paragraph); 

int main(void)
{
    string Paragraph = get_string("text: ");
    float Grade = Quantity(Paragraph);
    if ((round(Grade) > 1) && (round(Grade) < 16))
    {
        printf("Grade %0.f\n", round(Grade));
    }
    else if (round(Grade) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(Grade) > 16)
    {
        printf("Grade 16+\n");
    }
}


float Quantity(string Paragraph)
{
    float W = QuantityWords(Paragraph);
    float L = QuantityLetters(Paragraph);
    float S = QuantitySentences(Paragraph);
    double index = 0.0588 * (100 * (L / W)) - 0.296 * (100 * (S / W)) - 15.8; 
    return index;
}

int QuantitySentences(string Paragraph)
{
    int Sentences = 0;
    for (int b = 0, m = strlen(Paragraph) ; b < m; b++)
    {
        if ((Paragraph[b] == '.') || (Paragraph[b] == '!') || (Paragraph[b] == '?'))
        {
            Sentences = Sentences + 1.0;
        }
    }
    return Sentences;
}


int QuantityWords(string Paragraph)
{
    int Words = 1;
    for (int a = 0, n = strlen(Paragraph); a < n; a++)
    {
        if (Paragraph[a] == ' ')
        {
            Words = Words + 1.0;
        }
    }
    return Words;
}

int QuantityLetters(string Paragraph)
{
    int Letters = 0;
    for (int i = 0, N = strlen(Paragraph); i < N ; i++)
    {
        if (isalpha(Paragraph[i]))
        {
            Letters = Letters + 1.0;
        }
    }
    return Letters;
}