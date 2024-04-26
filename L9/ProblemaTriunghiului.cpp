#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 100;
 
int main() {
    int n;
    int T[MAX_N][MAX_N], C[MAX_N][MAX_N], drum[MAX_N][MAX_N];
 
    // Citirea valorilor triunghiului
    cout << "Introduceti numarul de linii: ";
    cin >> n;
    cout << "Introduceti elementele triunghiului:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> T[i][j];
        }
    }
 
    // Initializarea matricei auxiliare cu ultima linie a triunghiului
    for (int j = 0; j <= n; ++j) {
        C[n - 1][j] = T[n - 1][j];
    }
 
    // Calculul sumei maxime
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            if (C[i + 1][j] < C[i + 1][j + 1]) {
                C[i][j] = T[i][j] + C[i + 1][j + 1];
                drum[i][j] = j + 1;
            }
            else {
                C[i][j] = T[i][j] + C[i + 1][j];
                drum[i][j] = j;
            }
        }
    }
 
    // Afișarea sumei maxime și a elementelor care o alcătuiesc
    cout << "Suma maxima care se poate forma: " << C[0][0] << endl;
    cout << "Numerele care o alcătuiesc: ";
    int i = 0, j = 0;
    while (i < n) {
        cout << T[i][j] << " ";
        j = drum[i][j];
        ++i;
    }
 
    return 0;
}