#include <cs50.h>
#include <stdio.h>

int main ()
{
    int n;
    do
    {
       // i ask for one number between 1 and 8
        n = get_int("Height: ");
    }
    while (!((n>0) && (n<9)));
    for (int i=0; i<n; i++)
    {
        for (int p=n-1; p>i; p--)
        {
            printf(" ");
        }
        for (int j=-1; j<i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}