
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 50

char stringa[SIZE];


void InserisciStringa()
{
    printf("Inserisci stringa che contiene solo lettere\n");
    scanf("%s", &stringa);
    while (1){
        for (int i = 0; stringa[i] != '\0'; i++) {
        if (stringa[i] < 65 || stringa[i] > 90 && stringa[i] < 97 || stringa[i] > 122) {
            printf("Stringa inserita non contiene SOLO lettere");
            exit(0);
            }
        }
        break;
    }
    printf("La tua stringa: %s", &stringa);
}

void Stringhe()
{
    int contPari = 0, contDispari = 0;
    char pari[SIZE];
    char dispari[SIZE];
    for (int i=0; i< stringa[i] != '\0'; i++)
    {
        if (i % 2)
        {
            pari[contPari] = stringa[i];
            contPari++;
        }
        else
        {
            dispari[contDispari] = stringa[i];
            contDispari++; 
        }
    }
    printf("Stringa con lettere pari: %s\n", &pari);
    printf("Stringa con lettere dispari: %s\n", &dispari);
}


int main() {
    InserisciStringa();
    Stringhe();
    return 0;
}
