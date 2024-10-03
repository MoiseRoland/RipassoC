#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 50

typedef struct
{
  char titolo[MAX_LENGTH];
  char autore[MAX_LENGTH];
  int annoPubblicazione;
  float prezzo;
} Libro;

typedef struct
{
    char nome[MAX_LENGTH];
    Libro lib;
    int numeroLibri;
    
} Categoria;

    
int main() {
    FILE* fp;
    fp=fopen("libreria.csv", "r");
    if (fp == NULL)
    {
     printf("Impossibile aprire il file");
     exit(0);
    }
    
    
    
    
    return 0;
}tamente la libreria.