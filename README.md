File Ripasso C
//
Creare un programma in C che genera una sequenza di 10.000
numeri casuali e li memorizza in un array; i numeri generati devono appartenere
all’intervallo 1-500.
Nel programma il processo padre genera due figli e la
suddivisione dei compiti deve essere come segue:
-         Il padre genera i 10.000 numeri casuali.
-         Il padre salva tutti i numeri casuali in un file con il formato indice_array : valore
-         Il padre ricerca all’interno dei primi 2000 numeri dell’array un numero X inserito dall’utente a linea di comando e stampa a video la coppia indice_array : valore per tutte le coppie trovate; la stampa di ogni coppia deve essere preceduta dal pid del processo.
-         I due figli svolgono lo stesso compito del punto precedente dividendosi il lavoro a metà (4000 ricerche ciascuno).
