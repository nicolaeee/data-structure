#include <iostream>
#include <vector>

using namespace std;

int v[20]; // Vector pentru a stoca indicele curent al fiecărei mulțimi
int n[20]; // Vector pentru a stoca cardinalitatea fiecărei mulțimi
int m;     // Numărul de mulțimi

// Funcție recursivă pentru a genera elementele produsului cartezian
void pune(int k) {
    if (k == m + 1) { // Când am completat toate pozițiile
        for (int x = 1; x <= m; x++) {
            cout << v[x] << " ";
        }
        cout << endl;
    }
    else {
        for (int x = 1; x <= n[k]; x++) { // Iterăm prin toate elementele din mulțimea curentă
            v[k] = x;
            pune(k + 1); // Recursiv pentru poziția următoare
        }
    }
}

int main() {
    // Citim numărul de mulțimi
    cout << "Introdu numarul de multimi: ";
    cin >> m;

    // Citim cardinalitatea fiecărei mulțimi
    for (int i = 1; i <= m; i++) {
        cout << "Introdu cardinalul multimii " << i << ": ";
        cin >> n[i];
    }

    // Generăm elementele produsului cartezian
    pune(1);

    return 0;
}