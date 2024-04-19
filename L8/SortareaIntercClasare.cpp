#include <iostream>
#include <vector>

using namespace std;

// Functie pentru interclasarea a doua subliste ordonate
vector<int> interclaseaza(const vector<int>& stanga, const vector<int>& dreapta) {
    vector<int> lista_finala;
    int i = 0, j = 0;

    // Combinăm elementele din cele două subliste în ordine crescătoare
    while (i < stanga.size() && j < dreapta.size()) {
        if (stanga[i] <= dreapta[j]) {
            lista_finala.push_back(stanga[i]);
            i++;
        } else {
            lista_finala.push_back(dreapta[j]);
            j++;
        }
    }

    // Adăugăm elementele rămase din stânga (dacă există) în lista finală
    while (i < stanga.size()) {
        lista_finala.push_back(stanga[i]);
        i++;
    }

    // Adăugăm elementele rămase din dreapta (dacă există) în lista finală
    while (j < dreapta.size()) {
        lista_finala.push_back(dreapta[j]);
        j++;
    }

    return lista_finala;
}

// Functie pentru sortarea prin interclasare
vector<int> sortareInterclasare(vector<int>& lista) {
    // Dacă lista are unul sau niciun element, este deja sortată
    if (lista.size() <= 1) {
        return lista;
    }

    // Impartim lista in doua subliste aproximativ egale
    int mijloc = lista.size() / 2;
    vector<int> stanga(lista.begin(), lista.begin() + mijloc);
    vector<int> dreapta(lista.begin() + mijloc, lista.end());

    // Aplicăm recursiv sortarea prin interclasare pe subliste
    stanga = sortareInterclasare(stanga);
    dreapta = sortareInterclasare(dreapta);

    // Combina subliste ordonate in lista finala
    return interclaseaza(stanga, dreapta);
}

int main() {
    // Initializăm lista de numere
    vector<int> lista = {5, 3, 8, 1, 2, 7, 4, 6};

    // Afisam lista initiala
    cout << "Lista initiala: ";
    for (int numar : lista) {
        cout << numar << " ";
    }
    cout << endl;

    // Aplicăm sortarea prin interclasare pe lista
    lista = sortareInterclasare(lista);

    // Afisam lista sortata
    cout << "Lista sortata: ";
    for (int numar : lista) {
        cout << numar << " ";
    }
    cout << endl;

    return 0;
}

/*
Algoritmul Sortării prin Interclasare:
Diviziunea (Împărțirea): Lista inițială este împărțită în două subliste egale sau aproximativ egale.
Conducerea (Cucerirea): Se aplică recursiv algoritmul Sortării prin Interclasare pe fiecare sublistă separat, până când fiecare sublistă conține un singur element sau niciunul.
Combinarea: Sublistele sortate sunt apoi combinate într-o listă ordonată prin interclasare. Acest proces implică compararea elementelor din cele două subliste și plasarea lor în ordine crescătoare în lista finală.

Pseudocode:
SortareInterclasare(lista)
    // Daca lista are unul sau niciun element, este deja sortata
    dacă lungime(lista) ≤ 1
        return lista
    
    // Impartim lista in doua subliste aproximativ egale
    mijloc <- lungime(lista) / 2
    stanga <- Sublista(lista, 0, mijloc - 1)
    dreapta <- Sublista(lista, mijloc, lungime(lista) - 1)
    
    // Aplicam recursiv Sortarea prin Interclasare pe subliste
    stanga <- SortareInterclasare(stanga)
    dreapta <- SortareInterclasare(dreapta)
    
    // Combina subliste ordonate in lista finala
    return Interclaseaza(stanga, dreapta)

Interclaseaza(stanga, dreapta)
    lista_finala <- lista vida
    
    // Comparăm elementele din cele două subliste și le plasăm în ordine crescătoare în lista finală
    cat timp stanga nu este vida și dreapta nu este vida
        dacă primul element din stanga ≤ primul element din dreapta
            Adaugam primul element din stanga la lista_finala
            Eliminam primul element din stanga
        altfel
            Adaugam primul element din dreapta la lista_finala
            Eliminam primul element din dreapta
    
    // Adăugăm elementele rămase din stânga sau dreapta (dacă există) în lista finală
    cat timp stanga nu este vida
        Adaugam primul element din stanga la lista_finala
        Eliminam primul element din stanga
    cat timp dreapta nu este vida
        Adaugam primul element din dreapta la lista_finala
        Eliminam primul element din dreapta
    
    return lista_finala
*/