#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <cs50.h>


//constantes
typedef uint8_t byte;


//funciones
bool ItIs(byte *Buffer);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage only 1 command line argument.\n");
        return 1;
    }
    
    //abro mi memory card
    FILE *memory = fopen(argv[1], "r");
    if (memory == NULL)
    {
        printf("Can not open the file.\n");
        return 1;
    }
    
    //abro mi archivo para la nueva imagen
    FILE *NewImage;
    
    //variables necesarias para el loopeo
    bool Image = false;
    int amountBuffer;
    int amountImages = 0;
    
    byte Buffer[512];
    
    
    //leer toda mi memoria viendo si encontre o no una jpg
    while (fread(Buffer, sizeof(Buffer), 1, memory) == 1) 
    {
        if (ItIs(Buffer))
        {
            char file[8];
            sprintf(file, "%03.3i.jpg", amountImages);
            if (Image == true)
            {
                fclose(NewImage);
            }
            else
            {
                Image = true;
            }
            
            NewImage = fopen(file, "w");
            fwrite(Buffer, sizeof(Buffer), 1, NewImage);
            
            amountImages += 1;
        }
        else
        {
            if (Image == true)
            {
                fwrite(Buffer, sizeof(Buffer), 1, NewImage);
            }
        }
    }
    
    //cierro mis ficheros
    fclose(memory);
    fclose(NewImage);
}

bool ItIs(byte *Buffer)
{
    //chekeo los primeros 3 bytes que siempre van a ser fijos y el ultimo que varia
    if (Buffer[0] == 0xff && Buffer[1] == 0xd8 && Buffer[2] == 0xff && (Buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}
