#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main()
{
    //todo: solicitar tamaño de inicio
    int BeginPopulation;
    do
    {
        BeginPopulation = get_int("Begin Population: \n");
    }
    while (BeginPopulation  < 9);
    //todo: solicitar tamaño final
    int EndingPopulation;
    do
    {
        EndingPopulation = get_int("Ending Population: \n");
    }
    while (EndingPopulation < BeginPopulation);
    int year = 0;
    //todo: calcula el numero de años hasta alcanzar el umbral
    for (int b = 0 ; BeginPopulation < EndingPopulation; b++)
    {
        BeginPopulation = BeginPopulation + round(BeginPopulation / 3) - round(BeginPopulation / 4);
        year = year + 1;
    }
    //todo: imprime el numero de años
    printf("Years: %i\n", year);
}