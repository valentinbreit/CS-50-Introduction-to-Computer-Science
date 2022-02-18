#include <cs50.h>
#include <stdio.h>

int main()
{
    string name = get_string("Whats your name?\n");
    printf("Hello, %s\n", name);
}