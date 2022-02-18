// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


//variable contadora de cantidad de palabras
int WordsCounter=0;
char Word[LENGTH + 1];

// Number of buckets in hash table
//set N=26 beacuse is the number of the letters in the alphabet
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // TODO
    bool Finded = false;
    
    //pido el valor en donde tengo que buscar
    int Index = hash(word);
    
    //si está cargada, sigo, sino dejo de ejecutar
    if (table[Index] != NULL)
    {
        //creo puntero
        node *Cursor = table[Index];
        
        
        //itero hasta llegar al final de la lista, o hasta encontrar la palabra
        while (( Cursor != NULL) && (Finded == false))
        {
            //comparo la palabra a la que apunto si es termino el loop
            if ((strcasecmp(word, word)) == 0)
            {
                Finded = true;
            }
            //si no es, paso al siguiente
            else
            {
                Cursor = Cursor->next;
            }
        }
        
        //si ya termino toda la lista, significa que debo liberar el espacio
        free(Cursor);
        
        return Finded;
        
    }
    else
    {
        return Finded;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //inicializo mi contador
    int Counter = 0;
    
    //hago un loop hasta terminar de leer la palabra
    for (int i = 0, L = (strlen(word)+1); i < L; i++)
    {
        //por cada iteracion le sumo a mi variable el valor de las palabras
        Counter += tolower(word[i]);
    }
    
    //hago un mod por la cantidad de letras de mi tabla
    return (Counter % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Abrir mi fichero
    FILE *fp = fopen(dictionary,"r");
    if (fp == NULL)
    {
        fclose(fp);
        return false;
    }
    else
    {
        //Leo mientras no se acabe
        while ((fscanf(fp, "%s", Word)) != EOF)
        {
            //sumo la cantidad de palabras totales
            WordsCounter++;
        

            //creo espacio para la palabra en memoria
            node *W = malloc(LENGTH+1);
            
            //Si no hay suficiente espacio retorno falso
            if (W == NULL)
            {
                return false;
            }
            //sino sigo
            else 
            {
                //copio a lo que apunta W como dato, la palabra leida en la iteracion
                strcpy(W->word, Word);
                
                //retorno el valor del array
                int index = hash(Word);
                
                //me fijo si mi conjunto de arrays está en null (es la primer palabra que pongo)
                if (table[index] == NULL)
                {
                    table[index] = W;
                    W->next = NULL;
                }
                //en caso de que no sea el primero, debo asegurarme de que no se me pierda el listado
                else
                {
                    W->next = table[index];
                    table[index] = W;
                }
            }
            free (W);
        }
        //cierro mi archivo
        fclose(fp);
        return true;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //retorno mi variable global que contabiliza las palabras
    return WordsCounter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //recorro todos los lugares de la tabla
    for (int i = 0; i < (N); i++)
    {
        //creo un cursor para toda la tabla
        node *Cursor = table[i];
        
        //chekeo si es nulo o no
        if (Cursor != NULL)
        {
            while (Cursor != NULL)
            {
                node *aux = Cursor;
                Cursor = Cursor->next;
                free(aux);
            }
        }
        
        free(Cursor);
    }
    return true;
}
