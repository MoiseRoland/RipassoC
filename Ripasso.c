#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define NUMERI_DA_GENERARE 10000

int GeneraNumero(int *numeriCasuali)
{
    for (int i = 0; i < NUMERI_DA_GENERARE; i++)
    {
        srand(time(NULL));
        int r = rand();
        numeriCasuali[i] = (rand() % (500 - 1 + 1)) + 1;
    }
    return *numeriCasuali;
}

int main(int argc, char *argv[])
{
    int *numeriCasuali[NUMERI_DA_GENERARE];
    GeneraNumero(*numeriCasuali);



}