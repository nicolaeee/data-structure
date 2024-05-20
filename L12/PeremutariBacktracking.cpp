#include <iostream>
using namespace std;

int p[20], n;
bool folosit[20]; // vector pentru a verifica daca un element a fost folosit in permutare

// Functie pentru afisarea permutarii curente
void scrie() {
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

// Functie recursiva pentru generarea permutarilor
void permuta(int k) {
    // Daca am ajuns la permutarea completa, o afisam
    if (k == n + 1) {
        scrie();
    } else {
        // Incercam toate elementele care nu au fost folosite inca
        for (int i = 1; i <= n; i++) {
            if (!folosit[i]) { // daca elementul i nu a fost folosit
                p[k] = i;
                folosit[i] = true; // marcam elementul ca folosit
                permuta(k + 1); // apelam recursiv pentru urmatoarea pozitie
                folosit[i] = false; // revenim la starea anterioara (backtracking)
            }
        }
    }
}

int main() {
    // Citim numarul de elemente din multime
    cout << "Introduceti numarul de elemente: ";
    cin >> n;

    // Initializam vectorul folosit cu false
    for (int i = 1; i <= n; i++) {
        folosit[i] = false;
    }

    // Generam permutarile incepand de la pozitia 1
    permuta(1);

    return 0;
}
