#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 < score2)
    {
        printf("Player2 Wins! \n");
    }
    else if (score1 > score2)
    {
        printf("Player1 Wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}

int compute_score(string word)
{
    int MaximumPoints = 0;
    // TODO: Compute and return score for string
    for (int i = 0, N = strlen(word); i < N ; i++)
    {
        switch (toupper(word[i]))
        {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                MaximumPoints = MaximumPoints + 1;
                break;
            case 'D':
            case 'G':
                MaximumPoints = MaximumPoints + 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                MaximumPoints = MaximumPoints + 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                MaximumPoints = MaximumPoints + 4;
                break;
            case 'J':
            case 'X':
                MaximumPoints = MaximumPoints + 8;
                break;
            case 'Q':
            case 'Z':
                MaximumPoints = MaximumPoints + 10;
                break;
        }
    }
    return MaximumPoints;
}