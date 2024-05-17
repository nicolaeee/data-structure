#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Obiectul reprezentat prin structura
struct Obiect {
    int greutate;
    int profit;
};
 
// Structura pentru a returna profitul maxim și obiectele selectate
struct RezultatRucsac {
    int profitMaxim;
    vector<int> obiecteSelectate;
};
 
// Functie rucsac
RezultatRucsac rucsac(int capacitate, vector<Obiect>& obiecte) {
    int n = obiecte.size();
    // Matrice pentru a stoca profitul maxim pentru subprobleme
    vector<vector<int>> dp(n + 1, vector<int>(capacitate + 1, 0));
 
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacitate; ++w) {
            if (obiecte[i - 1].greutate <= w) {
                // Alege maximul pentru a adauga sau nu obiectul
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - obiecte[i - 1].greutate] + obiecte[i - 1].profit);
            }
            else {
                // Profitul ramane același daca obiectul nu este adăugat
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
 
    // Construieste lista obiectelor selectate
    vector<int> obiecteSelectate;
    int w = capacitate;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            obiecteSelectate.push_back(i - 1);
            w -= obiecte[i - 1].greutate;
        }
    }
 
    // Returnează profitul maxim si obiectele selectate
    return { dp[n][capacitate], obiecteSelectate };
}
 
int main() {
    int capacitate, numarObiecte;
    cout << "Introdu capacitatea rucsacului: ";
    cin >> capacitate;
    cout << "Introdu numarul de obiecte: ";
    cin >> numarObiecte;
 
    vector<Obiect> obiecte(numarObiecte);
    cout << "Introdu greutatea si profitul pentru fiecare obiect:" << endl;
    for (int i = 0; i < numarObiecte; ++i) {
        cout << "Obiect " << i + 1 << ":" << endl;
        cout << "Greutate: ";
        cin >> obiecte[i].greutate;
        cout << "Profit: ";
        cin >> obiecte[i].profit;
    }
 
    // Calcularea profitului maxim si obiecte selectate
    RezultatRucsac rezultat = rucsac(capacitate, obiecte);
 
    cout << "Profitul maxim: " << rezultat.profitMaxim << endl;
    cout << "Obiectele selectate sunt: ";
    for (int idx : rezultat.obiecteSelectate) {
        cout << idx + 1 << " ";
    }
    cout << endl;
 
    return 0;
}