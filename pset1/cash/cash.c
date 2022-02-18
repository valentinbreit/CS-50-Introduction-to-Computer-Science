#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float Dollars;
    do
    {
        //user enters change
        Dollars = get_float("Change: $");
    }
    while (Dollars < 0);
    //change from decimal to integer to make the necessary substraction easier
    int Cents = round(Dollars * 100);
    //initialize my variable to zero
    int NumberOfCoins = 0;

    for (int i = 25;Cents >= i; i = 25)
    {
        NumberOfCoins = NumberOfCoins + 1;
        Cents = Cents - 25;
    }
    for (int n = 10; Cents >= n; n = 10)
    {
        NumberOfCoins = NumberOfCoins + 1;
        Cents = Cents - 10;
    }
    for (float j = 5; Cents >= j; j = 5)
    {
        NumberOfCoins = NumberOfCoins + 1;
        Cents = Cents - 5;
    }
    for (float a = 1; Cents >= a; a = 1)
    {
        NumberOfCoins = NumberOfCoins + 1;
        Cents = Cents - 1;
    }

    printf("The Number of Coins used: %i\n", NumberOfCoins);
}