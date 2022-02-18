#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int VerifyKey(int argc, string argv[]);


int main(int argc, string argv[])
{
    //enter and verify my key
    if (VerifyKey(argc, argv) == 0)
    {
        int x = atoi(argv[1]);
        if (x >= 0)
        {
            
            //get PlainText
            string Plain = get_string("PlainText: ");
            printf("ciphertext: ");
            for (int i = 0, N = strlen(Plain); i < N; i++)
            {
                if ((Plain[i] >= 65) && (Plain[i] <= 90))
                {
                    for (int a = 0; a < x; a++)
                    {
                        Plain[i] = Plain[i] + 1;
                        if (Plain[i] > 90)
                        {
                            Plain[i] = 65;
                        }
                    }
                    printf("%c", Plain[i]);
                }
                if ((Plain[i] >= 97) && (Plain[i] <= 122))
                {
                    for (int b = 0; b < x; b++)
                    {
                        Plain[i] = Plain[i] + 1;
                        if (Plain[i] > 122)
                        {
                            Plain[i] = 97;
                        }
                    }
                    printf("%c", Plain[i]);
                }
                if (Plain[i] < 65)
                {
                    printf("%c", Plain[i]);
                }
                else if ((Plain[i] > 90) && (Plain[i] < 97))
                {
                    printf("%c", Plain[i]);
                }
                else if (Plain[i] > 122)
                {
                    printf("%c", Plain[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./Ceaser Key\n");
        
        }
    }
    return 1;
}

int VerifyKey(int argc, string argv[])
{
    
    bool is = true;
    //me aseguro que argc siempre sean 2, el ejecutable y mi numero a utilizar
    if (argc == 2)
    {
        for (int Count = 0, n = strlen(argv[1]); Count <= n ; Count++)
        {
            //Me aseguro que si ingresan un caracter numero les de error y no puedan seguir con el programa
            if (isalpha(argv[1][Count]))
            {
                is = false;
            }
        }
    }
    else 
    {
        is = false;
    }
    if (is == false)
    {
        printf("Usage: ./Ceaser Key\n");
        return 1;
    }
    else
    {
        return 0;
    }
}