 #include <stdio.h>
#include <stdbool.h>
 
#define N 8 // Numărul de noduri în graf
 
// Funcție pentru a afișa soluția
void printSolution(int path[]);

// Funcție pentru a verifica dacă adăugarea nodului v la poziția pos este sigură
bool isSafe(int v, bool graph[N][N], int path[], int pos) {
    // Verificăm dacă există o muchie între ultimul nod din cale și nodul v
    if (graph[path[pos - 1]][v] == 0)
        return false;
 
    // Verificăm dacă nodul v a mai fost vizitat în cadrul aceleiași căi
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
// Funcție recursivă pentru a găsi ciclul Hamiltonian
bool hamiltonianCycleUtil(bool graph[N][N], int path[], int pos) {
    // Verificăm dacă toate nodurile au fost incluse în cale
    if (pos == N) {
        // Verificăm dacă există o muchie între ultimul nod și primul nod
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
 
    // Încercăm să adăugăm fiecare nod la poziția pos în cale
    for (int v = 1; v < N; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            // Verificăm recursiv dacă adăugarea nodului v la poziția pos conduce la un ciclu Hamiltonian
            if (hamiltonianCycleUtil(graph, path, pos + 1) == true)
                return true;
            // Dacă adăugarea nodului v nu duce la un ciclu Hamiltonian, îl eliminăm din cale
            path[pos] = -1;
        }
    }
 
    return false;
}
 
// Funcția pentru a găsi ciclul Hamiltonian într-un graf dat
void hamiltonianCycle(bool graph[N][N]) {
    int path[N];
    for (int i = 0; i < N; i++)
        path[i] = -1;
 
    // Începem cu primul nod (0) în cale
    path[0] = 0;
 
    // Apelăm funcția utilitară pentru a găsi ciclul Hamiltonian
    if (hamiltonianCycleUtil(graph, path, 1) == false) {
        printf("Nu există ciclu Hamiltonian\n");
        return;
    }
 
    // Afișăm ciclul Hamiltonian găsit
    printf("Ciclu Hamiltonian: \n");
    printSolution(path);
}
 
// Funcție pentru a afișa soluția
void printSolution(int path[]) {
    for (int i = 0; i < N; i++)
        printf("%d ", path[i]);
    printf("%d ", path[0]); // Afisam si primul nod pentru a inchide ciclul
    printf("\n");
}
 
int main() {
    // Definim graf-ul sub forma unei matrici de adiacență
    bool graph[N][N] = {
        {0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };
 
    // Apelăm funcția pentru a găsi ciclul Hamiltonian în graf
    hamiltonianCycle(graph);
    return 0;
}

/*

Algoritmul găsește un ciclu Hamiltonian într-un graf dat. Un ciclu Hamiltonian este un ciclu într-un graf neorientat care vizitează fiecare nod exact o dată și se întoarce la nodul de pornire.

Iată cum funcționează algoritmul:

Se pornește de la un nod de start și se încearcă construirea unui ciclu Hamiltonian trecând prin toate celelalte noduri.

În fiecare pas, algoritmul încearcă să adauge un nod nou în calea curentă. Se verifică dacă adăugarea acestui nod este sigură, adică dacă există o muchie între ultimul nod din cale și nodul nou și dacă nodul nu a fost deja vizitat.

Dacă adăugarea nodului este sigură, acesta este adăugat în cale și algoritmul continuă să încerce să adauge următorul nod.

Algoritmul continuă să adauge noduri și să verifice dacă calea formată constituie un ciclu Hamiltonian. Dacă se găsește un ciclu Hamiltonian, acesta este afișat; în caz contrar, se afișează un mesaj că nu există ciclu Hamiltonian în graf.

Algoritmul utilizează backtracking pentru a explora toate posibilitățile de a forma un ciclu Hamiltonian și verifică în fiecare pas dacă calea formată respectă condițiile unui ciclu Hamiltonian. Acest proces continuă până când se găsește un ciclu Hamiltonian sau toate posibilitățile sunt epuizate.

Astfel, algoritmul oferă o metodă eficientă pentru a găsi un ciclu Hamiltonian într-un graf dat, permițând astfel soluționarea unei varietăți de probleme practice, precum problema circuitului turistic sau problema circuitului de transport.









*/