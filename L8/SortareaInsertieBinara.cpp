#include <iostream>
#include <vector>

using namespace std;



// Sortare prin Insertie Binara
vector<int> sortareInserțieBinară(vector<int>& lista) {
    int lungime = lista.size();
    for (int index = 1; index < lungime; ++index) {
        int elementCurent = lista[index];
        int pozitie = 0;
        int inceput = 0, sfarsit = index - 1;
        while (inceput <= sfarsit) {
            int mijloc = (inceput + sfarsit) / 2;
            if (lista[mijloc] < elementCurent) {
                pozitie = mijloc + 1;
                inceput = mijloc + 1;
            }
            else {
                sfarsit = mijloc - 1;
            }
        }
        for (int j = index - 1; j >= pozitie; --j) {
            lista[j + 1] = lista[j];
        }
        lista[pozitie] = elementCurent;
    }
    return lista;
}

// Functie de afisare a vectorului
void afisareVector(const vector<int>& lista) {
    for (int element : lista) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<int> lista1 = { 5, 3, 8, 1, 2, 7, 4, 6 };
    vector<int> lista2 = { 5, 3, 8, 1, 2, 7, 4, 6 };

    cout << "Vector initial: ";
    afisareVector(lista1);

    cout << "Sortare prin Insertie Binara: ";
    lista2 = sortareInserțieBinară(lista2);
    afisareVector(lista2);

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