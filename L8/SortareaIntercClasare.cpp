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
