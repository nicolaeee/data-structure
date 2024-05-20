#include <iostream>
using namespace std;

int p[20], n;

// Functie pentru afisarea permutarii curente
void scrie() {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
}

// Functie recursiva pentru generarea permutarilor
void permuta(int k) {
    int aux;
    // Daca am ajuns la permutarea completa, o afisam
    if (k == n + 1) {
        scrie();
    }
    else {
        // Parcurgem toate pozitiile de la k la 1
        for (int i = k; i >= 1; i--) {
            // Interschimbam elementele pentru a genera o noua permutare
            aux = p[i];
            p[i] = p[k];
            p[k] = aux;

            // Apelam recursiv pentru a genera permutarile urmatoare
            permuta(k + 1);

            // Restauram ordinea initiala pentru urmatoarea iteratie
            aux = p[i];
            p[i] = p[k];
            p[k] = aux;
        }
    }
}

int main() {
    // Citim numarul de elemente din multime
    cout << "Introduceti numarul de elemente: ";
    cin >> n;

    // Initializam vectorul p cu valorile 1, 2, ..., n
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    // Generam permutarile incepand de la pozitia 1
    permuta(1);

    return 0;
}