#include <iostream>
#include <vector>

using namespace std;

// Structura pentru a reprezenta un obiect cu valoare si greutate
struct Obiect {
    int valoare, greutate;
};

// Functie pentru calcularea profitului maxim utilizand backtracking
int rucsac_backtracking(int capacitate, vector<Obiect>& obiecte, int index) {
    // Daca am parcurs toate obiectele sau capacitatea este 0, returnam 0
    if (index < 0 || capacitate == 0) {
        return 0;
    }
    // Daca greutatea obiectului este mai mare decat capacitatea, il sarim
    if (obiecte[index].greutate > capacitate) {
        return rucsac_backtracking(capacitate, obiecte, index - 1);
    }
    // Verificam daca includem obiectul sau nu
    int profit_inclus = obiecte[index].valoare + rucsac_backtracking(capacitate - obiecte[index].greutate, obiecte, index - 1);
    int profit_exclus = rucsac_backtracking(capacitate, obiecte, index - 1);
    // Returnam profitul maxim dintre cele doua cazuri
    return max(profit_inclus, profit_exclus);
}

int main() {
    int numar_obiecte, capacitate;

    cout << "Introdu numarul de obiecte: ";
    cin >> numar_obiecte;

    cout << "Introdu capacitatea rucsacului: ";
    cin >> capacitate;

    vector<Obiect> obiecte(numar_obiecte);

    cout << "Introdu valorile si greutatile obiectelor:" << endl;
    for (int i = 0; i < numar_obiecte; ++i) {
        cout << "Valoare obiect " << i + 1 << ": ";
        cin >> obiecte[i].valoare;
        cout << "Greutate obiect " << i + 1 << ": ";
        cin >> obiecte[i].greutate;
    }

    // Afisam profitul maxim utilizand metoda backtracking
    cout << "Profit maxim: " << rucsac_backtracking(capacitate, obiecte, numar_obiecte - 1) << endl;

    return 0;
}
