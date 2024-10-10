#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIBRI 50
#define MAX_CATEGORIE 10
#define MAX_LENGTH 100
#define MAX_RIGA_LEN 256

// Definizione della struttura del libro
typedef struct {
    char titolo[MAX_LENGTH];
    char autore[MAX_LENGTH];
    int anno;
    float prezzo;
} Libro;

// Definizione della struttura della categoria
typedef struct {
    char nome[MAX_LENGTH];
    Libro libri[MAX_LIBRI];
    int num_libri;
} Categoria;

// Funzione per stampare i libri di una categoria
void stampaLibriInCategoria(Categoria *categorie, int num_categorie, char *nome_categoria) {
    int i, j;
    for (i = 0; i < num_categorie; i++) {
        if (strcmp(categorie[i].nome, nome_categoria) == 0) {
            printf("Libri nella categoria '%s':\n", nome_categoria);
            for (j = 0; j < categorie[i].num_libri; j++) {
                printf("- Titolo: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n",
                       categorie[i].libri[j].titolo,
                       categorie[i].libri[j].autore,
                       categorie[i].libri[j].anno,
                       categorie[i].libri[j].prezzo);
            }
            return;
        }
    }
    printf("Nessuna categoria trovata con il nome '%s'.\n", nome_categoria);
}

// Funzione per cercare un libro per titolo
void cercaLibroPerTitolo(Categoria *categorie, int num_categorie, char *titolo) {
    int i, j;
    for (i = 0; i < num_categorie; i++) {
        for (j = 0; j < categorie[i].num_libri; j++) {
            if (strcmp(categorie[i].libri[j].titolo, titolo) == 0) {
                printf("Libro trovato:\n");
                printf("- Titolo: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n",
                       categorie[i].libri[j].titolo,
                       categorie[i].libri[j].autore,
                       categorie[i].libri[j].anno,
                       categorie[i].libri[j].prezzo);
                return;
            }
        }
    }
    printf("Nessun libro trovato con il titolo '%s'.\n", titolo);
}

// Funzione per aggiungere un libro a una categoria
void aggiungiLibroACategoria(Categoria *categorie, int *num_categorie, char *nome_categoria, Libro nuovo_libro) {
    int i;
    // Cerca se la categoria esiste già
    for (i = 0; i < *num_categorie; i++) {
        if (strcmp(categorie[i].nome, nome_categoria) == 0) {
            // Aggiungi il libro alla categoria esistente
            if (categorie[i].num_libri < MAX_LIBRI) {
                categorie[i].libri[categorie[i].num_libri++] = nuovo_libro;
            } else {
                printf("Errore: la categoria '%s' è piena.\n", nome_categoria);
                exit(0);
            }
            return;
        }
    }

    // Se la categoria non esiste, creala
    if (*num_categorie < MAX_CATEGORIE) {
        strcpy(categorie[*num_categorie].nome, nome_categoria);
        categorie[*num_categorie].libri[0] = nuovo_libro;
        categorie[*num_categorie].num_libri = 1;
        (*num_categorie)++;
    } else {
        printf("Errore: numero massimo di categorie raggiunto.\n");
        exit(0);
    }
}

void caricaLibriDaCSV(Categoria *categorie, int *num_categorie) {
    char *nome_file = "libreria_libri.csv";
    FILE *file = fopen(nome_file, "r");
    if (!file) {
        printf("Errore nell'apertura del file CSV.\n");
        exit(0);
    }

    char riga[MAX_RIGA_LEN];
    while (fgets(riga, sizeof(riga), file)) {
        Libro nuovo_libro;
        char categoria[MAX_LENGTH];
        int campo = 0;
        int lunghezza_riga = strlen(riga);
        int i, j = 0;

        char temp[MAX_RIGA_LEN] = {0};  // Buffer per i campi
        for (i = 0; i <= lunghezza_riga; i++) {
            if (riga[i] == ',' || riga[i] == '\n' || riga[i] == '\0') {
                temp[j] = '\0';  // Termina la stringa temporanea

                // Gestisci il campo corrente
                if (campo == 0) {
                    strcpy(nuovo_libro.titolo, temp);
                } else if (campo == 1) {
                    strcpy(nuovo_libro.autore, temp);
                } else if (campo == 2) {
                    nuovo_libro.anno = atoi(temp);
                } else if (campo == 3) {
                    nuovo_libro.prezzo = atof(temp);
                } else if (campo == 4) {
                    strcpy(categoria, temp);
                }
                // Resetta il buffer 
                j = 0;
                campo++;
            } else {
                temp[j++] = riga[i];
            }
        }

        // Aggiungi il libro alla categoria
        aggiungiLibroACategoria(categorie, num_categorie, categoria, nuovo_libro);
    }
    printf("Tutti i libri sono stati aggiunti");

    fclose(file);
}

int main() {
    // Definizione delle categorie
    Categoria categorie[MAX_CATEGORIE];
    int num_categorie = 0;

    // Caricamento dei libri dal file CSV
    caricaLibriDaCSV(categorie, &num_categorie);
    printf("\nInserisci titolo da cercare\n");
    char titoloCercato[50];
    scanf(" %[^\n]s", titoloCercato);
    cercaLibroPerTitolo(categorie, num_categorie, titoloCercato);
    printf("\n");
    printf("\nInserisci categoria da cercare\n");
    char categoriaCercata[50];
    scanf(" %[^\n]s", categoriaCercata); // Legge l'intera riga di input, inclusi gli spazi
    stampaLibriInCategoria(categorie, num_categorie, categoriaCercata);
    printf("\n");

    return 0;
}
