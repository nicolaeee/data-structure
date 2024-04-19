#include <iostream>
#include <vector>

using namespace std;

// Functie de cautare binara
// Functie de cautare binara
int cautareBinară(const vector<int>& lista, int element, int inceput, int sfarsit) {
    // Cautare binara pana cand intervalul de cautare este valid
    while (inceput <= sfarsit) {
        // Calcul mijloc
        int mijloc = (inceput + sfarsit) / 2;
        // Verificare daca elementul este gasit la mijloc
        if (lista[mijloc] == element) {
            return mijloc; // Returneaza pozitia gasita
        }
        // Daca elementul este mai mare, actualizeaza inceputul intervalului
        else if (lista[mijloc] < element) {
            inceput = mijloc + 1;
        }
        // Altfel, actualizeaza sfarsitul intervalului
        else {
            sfarsit = mijloc - 1;
        }
    }
    // Returneaza pozitia la care ar trebui inserat elementul daca nu este gasit
    return inceput;
}

// Sortare prin Inserție Binară
vector<int> sortareInserțieBinară(vector<int>& lista) {
    // Lungimea listei
    int lungime = lista.size();
    // Parcurgere de la al doilea element pana la final
    for (int index = 1; index < lungime; ++index) {
        // Salveaza elementul curent pentru inserție
        int elementCurent = lista[index];
        // Cauta pozitia corecta pentru inserție folosind cautarea binara
        int pozitie = cautareBinară(lista, elementCurent, 0, index - 1);
        // Deplaseaza elementele pentru a face loc pentru elementul curent
        for (int j = index - 1; j >= pozitie; --j) {
            lista[j + 1] = lista[j];
        }
        // Insereaza elementul curent in pozitia corecta
        lista[pozitie] = elementCurent;
    }
    // Returneaza lista sortata
    return lista;
}


// Functie pentru afisarea unui vector
void afisareVector(const vector<int>& lista) {
    for (int element : lista) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // Initializare vector neordonat
    vector<int> lista = { 5, 3, 8, 1, 2, 7, 4, 6 };

    // Afisare vector initial
    cout << "Vector initial: ";
    afisareVector(lista);

    // Sortare prin Inserție Binară
    lista = sortareInserțieBinară(lista);

    // Afisare vector sortat
    cout << "Vector sortat: ";
    afisareVector(lista);

    return 0;
}

/*
Sortarea prin inserție binară este o variantă eficientă a sortării prin inserție simplă care folosește căutarea binară pentru a găsi locul corect pentru a insera un element în lista sortată.

Algoritmul:
Parcurge lista de la stânga la dreapta.
La fiecare pas, folosește căutarea binară pentru a găsi locul corect pentru a insera elementul curent în lista sortată.
Inserează elementul în poziția găsită și deplasează elementele mai mari către dreapta pentru a face loc.

Pseudocode:

function sortareInserțieBinară(lista):
    pentru fiecare index de la 1 la lungime(lista) - 1:
        element_curent = lista[index]
        poziție = căutareBinară(lista, element_curent, 0, index - 1)
        pentru j de la index - 1 până la poziție:
            lista[j + 1] = lista[j]
        lista[poziție] = element_curent
    return lista

function căutareBinară(lista, element, început, sfârșit):
    dacă sfârșit <= început:
        dacă element < lista[început]:
            return început
        altfel:
            return început + 1
    mijloc = (început + sfârșit) / 2
    dacă element == lista[mijloc]:
        return mijloc + 1
    dacă element < lista[mijloc]:
        return căutareBinară(lista, element, început, mijloc - 1)
    altfel:
        return căutareBinară(lista, element, mijloc + 1, sfârșit)

*/