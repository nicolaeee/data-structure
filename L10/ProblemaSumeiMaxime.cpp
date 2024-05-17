#include <iostream>
using namespace std;
 
class multime {
    int nr; // Numarul de elemente din multime
    int elemente[20]; // Vectorul de elemente
 
public:
    multime() {
        nr = 0;
    }
 
    // Metoda pentru a citi multimea
    void citire() {
        cout << "nr de elemente si elementele: ";
        cin >> nr;
        for (int i = 0; i < nr; i++) cin >> elemente[i];
    }
 
    // Metoda pentru a afisa multimea
    void afisare() {
        for (int i = 0; i < nr; i++) cout << elemente[i] << " ";
    }
 
    // Metoda pentru a calcula suma de elemente
    int suma() {
        int s = 0;
        for (int i = 0; i < nr; i++)
            s += elemente[i];
        return s;
    }
 
    // Supraincarca elementul pentru a adauga nr in multime
    multime operator + (int val) {
        multime m;
        m.nr = nr + 1;
        for (int i = 0; i < nr; i++) m.elemente[i] = elemente[i];
        m.elemente[nr] = val;
        return m;
    }
};
 
multime multimi_numere[20][20]; //Matrice de multimi si numere
int sume[20][20], n, numere[20]; // Matrice de sume si vectorul de numere de intrare
 
int main() {
    multime m;
    cout << "n="; cin >> n;
    for (int i = 0; i < n; i++) cin >> numere[i]; // Citirea vectorului de numere
 
    // Initializarea primului rand din matricea sume si multimilor cu primele numere din vector
    for (int k = 0; k < n; k++) {
        if (numere[0] % n == k) {
            sume[0][k] = numere[0];
            multimi_numere[0][k] = multimi_numere[0][k] + numere[0];
        }
        else sume[0][k] = 0;
    }
 
    // Calcularea sumelor maxime si formarea multimilor maxime
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < n; k++) {
            int max = sume[i - 1][k];
            multimi_numere[i][k] = multimi_numere[i - 1][k];
            sume[i][k] = sume[i - 1][k];
 
            // Actualizarea sumei si multimii maxime daca se gaseste un nou maxim
            if ((numere[i] % n == k) && (max < numere[i])) {
                max = numere[i];
                multimi_numere[i][k] = multimi_numere[i][k] + numere[i];
                sume[i][k] = numere[i];
            }
 
            // Verific daca adaugarea unui nou numar la o suma existenta genereaza un nou maxim
            for (int j = 0; j < n; j++) {
                if (((sume[i - 1][j] + numere[i]) % n == k) && max < (sume[i - 1][j] + numere[i])) {
                    max = sume[i - 1][j] + numere[i];
                    multimi_numere[i][k] = multimi_numere[i - 1][j] + numere[i];
                    sume[i][k] = sume[i - 1][j] + numere[i];
                }
            }
        }
    }
 
    // Afisarea
    cout << "Elementele selectate sunt: ";
    multimi_numere[n - 1][0].afisare();
    cout << "\nSuma maxima a elementelor selectate este: " << multimi_numere[n - 1][0].suma();
    return 0;
}