#include <iostream>
#include <vector>

using namespace std;

// Sortare prin Inserție Simpla
vector<int> sortareInserțieSimpla(vector<int>& lista) {
    int lungime = lista.size();
    for (int index = 1; index < lungime; ++index) {
        int elementCurent = lista[index];
        int pozitie = index - 1;
        while (pozitie >= 0 && lista[pozitie] > elementCurent) {
            lista[pozitie + 1] = lista[pozitie];
            pozitie = pozitie - 1;
        }
        lista[pozitie + 1] = elementCurent;
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

    cout << "Sortare prin Insertie Simpla: ";
    lista1 = sortareInserțieSimpla(lista1);
    afisareVector(lista1);


    return 0;
}

/*
Sortarea prin inserție simplă este un algoritm de sortare care construiește o listă sortată un element la un moment dat. La fiecare pas, un element este luat din lista nesortată și este inserat în locul său corect în lista sortată.

Algoritmul:
Parcurge lista de la stânga la dreapta.
Pentru fiecare element, începând cu al doilea, compara-l cu elementele din partea sa stângă.
Mută elementul către stânga până când găsești locul potrivit pentru a-l insera, astfel încât lista să rămână sortată.

Pseudocod:

function sortareInserțieSimplă(lista):
    pentru fiecare index de la 1 la lungime(lista) - 1:
        element_curent = lista[index]
        poziție = index - 1
        while poziție >= 0 și lista[poziție] > element_curent:
            lista[poziție + 1] = lista[poziție]
            poziție = poziție - 1
        lista[poziție + 1] = element_curent
    return lista

*/