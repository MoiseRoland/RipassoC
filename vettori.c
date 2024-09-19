#include <stdio.h>
int array[] = {25, 50, 75, 100}; 



void visualizzaNumeri(){
    for (int i=0; i<sizeof(array); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void menu()
{
    printf("[1] Visualizza gli elementi\n");
    printf("[2] Visualizza l'array invertito\n");
    printf("[3] Visualizza la somma e la media\n");
    printf("[4] Visualizza numeri pari\n");
    printf("[5] Visualizza numeri dispari\n");
    printf("[6] Cerca un numero\n");
    printf("[7] Elimina un numero\n");
    printf("[8] Alterna due numeri\n");
    printf("[9] Ordina l'array\n");
    printf("[10] Esci\n");
}

void scelta(int risp){
    switch(risp)
    {
        case 1:
        visualizzaNumeri();
        break;
    }
}

int main()
{
    int risp;
    while (1)
    {
        menu();
        scanf("%d", &risp);
        if (risp == 10)
        return 0;
        else
        scelta(risp);
    }
    return 0;
}
