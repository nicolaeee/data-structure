#include <iostream>
#include <vector>

using namespace std;

// Algoritmul Roy-Warshall
vector<vector<int>> royWarshall(vector<vector<int>>& matrice_adiacenta) {
    int numar_noduri = matrice_adiacenta.size();

    // Iterăm prin toate nodurile intermediare posibile
    for (int k = 0; k < numar_noduri; ++k) {
        // Iterăm prin nodurile de plecare
        for (int i = 0; i < numar_noduri; ++i) {
            // Iterăm prin nodurile destinație
            for (int j = 0; j < numar_noduri; ++j) {
                // Actualizăm distanța minimă între nodurile i și j prin nodul intermediar k
                matrice_adiacenta[i][j] = min(matrice_adiacenta[i][j], matrice_adiacenta[i][k] + matrice_adiacenta[k][j]);
            }
        }
    }

    return matrice_adiacenta;
}

int main() {
    // Exemplu pentru algoritmul Roy-Warshall
    vector<vector<int>> matrice_adiacenta = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}
    };

    // Aplicăm algoritmul Roy-Warshall pe matricea de adiacență
    matrice_adiacenta = royWarshall(matrice_adiacenta);

    // Afișăm matricea de adiacență rezultată cu distanțele minime între noduri
    cout << "Matricea de adiacenta cu distantele minime intre noduri:\n";
    for (const auto& linie : matrice_adiacenta) {
        for (int distanta : linie) {
            if (distanta == INT_MAX) {
                cout << "INF ";
            } else {
                cout << distanta << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


/*

Algoritmul Roy-Warshall:
Explicație:
Inițializare: Inițializăm o matrice de adiacență cu distanțe între noduri și infinit pentru nodurile care nu sunt conectate direct.
Actualizare: Pentru fiecare pereche de noduri (i, j), verificăm dacă există un nod intermediar k astfel încât distanța de la i la j să fie mai mică decât distanța actuală de la i la j prin nodul k.
Iterație: Parcurgem toate nodurile ca nod intermediar și actualizăm matricea distanțelor.
Pseudocod:

RoyWarshall(matrice_adiacenta)
    pentru k de la 1 la numar_noduri
        pentru i de la 1 la numar_noduri
            pentru j de la 1 la numar_noduri
                matrice_adiacenta[i][j] <- min(matrice_adiacenta[i][j], matrice_adiacenta[i][k] + matrice_adiacenta[k][j])
    return matrice_adiacenta
*/