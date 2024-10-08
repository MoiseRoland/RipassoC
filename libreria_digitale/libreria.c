#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 50
#define MAX_LIBRI 100
#define MAX_CATEGORIE 10
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
    Libro lib[MAX_LIBRI];
    int numeroLibri;
} Categoria;

Categoria categorie[MAX_CATEGORIE];
int contaCat = 0;

void prendiDaFile()
{
    Libro libro;
    FILE *file = fopen("libreria_libri.csv", "r");
    if (!file)
    {
        exit(0);
    }
    char line[256];
    fgets(line, sizeof(line), file);
    int conta = 0;
    while (fgets(line, sizeof(line), file))
    {
        //lettura titolo
        int i = 0;
        while (line[i] != ',' && line[i] != '\0')
        {
            libro.titolo[i] = line[i];
            i++;
        }
        libro.titolo[i]= '\0';
        i++;
        int j = 0;
        //lettura autore
        while (line[j] != ',' && line[j] != '\0')
        {
            libro.autore[j] = line[j];
            i++;
        }
        libro.autore[j]= '\0';
        j++;
        int k =0;
        while (line[k] != ',' && line[k] != '\0')
        {
            libro.prezzo[k] = line[k];
            k++;
        }
        libro.autore[k]= '\0';
        k++;
    }

    fclose(file);
}
int main()
{
    FILE *fp;
    fp = fopen("libreria.csv", "r");
    if (fp == NULL)
    {
        printf("Impossibile aprire il file");
        exit(0);
    }

    return 0;
}
