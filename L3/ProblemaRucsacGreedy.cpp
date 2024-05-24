#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Obiect {
    int greutate;
    int cost;
    int index;

    bool operator<(const Obiect& altul) const {
        return static_cast<double>(cost) / greutate > static_cast<double>(altul.cost) / altul.greutate;
    }
};

vector<double> rezolvaRucsacGreedy(int greutateMaxima, vector<Obiect>& obiecte) {
    sort(obiecte.begin(), obiecte.end());

    vector<double> solutie(obiecte.size(), 0.0);
    double greutateRamasa = greutateMaxima;

    for (const Obiect& obiect : obiecte) {
        if (obiect.greutate <= greutateRamasa) {
            solutie[obiect.index] = 1.0;
            greutateRamasa -= obiect.greutate;
        }
        else {
            solutie[obiect.index] = greutateRamasa / obiect.greutate;
            break;
        }
    }

    return solutie;
}

int main() {
    int greutateMaxima = 14;
    vector<Obiect> obiecte = {
        {2, 10, 0},
        {5, 20, 1},
        {9, 30, 2},
        {3, 5, 3}
        
    };

    vector<double> solutie = rezolvaRucsacGreedy(greutateMaxima, obiecte);

    cout << "Fractia din fiecare obiect luata:\n";
    for (size_t i = 0; i < solutie.size(); ++i) {
        cout << "Obiectul " << i << ": " << solutie[i] << "\n";
    }

    return 0;
}

/*
Acest program implementează o abordare greedy pentru problema rucsacului. Scopul este de a selecta o combinație de obiecte care să maximizeze valoarea totală a obiectelor, având în vedere o greutate maximă admisibilă pentru rucsac.

Structura Obiect reprezintă fiecare obiect cu greutatea sa (greutate), costul său (cost) și un index pentru identificare.
Operatorul < este suprascris pentru a permite sortarea obiectelor în ordinea descrescătoare a raportului cost/greutate. Acest lucru este crucial în abordarea greedy a problemei rucsacului.
Funcția rezolvaRucsacGreedy primește greutatea maximă a rucsacului și un vector de obiecte. Mai întâi, obiectele sunt sortate utilizând operatorul definit anterior. Apoi, se parcurg obiectele în ordinea sortată și se adaugă în rucsac atât timp cât greutatea rămasă permite.
În funcția main, se definește greutatea maximă a rucsacului (greutateMaxima) și un vector de obiecte (obiecte). Pentru fiecare obiect, sunt specificate greutatea, costul și un index.
Se apelează funcția rezolvaRucsacGreedy pentru a obține o soluție. Aceasta returnează o listă de fracții care indică cât din fiecare obiect a fost ales.
Se afișează rezultatul, indicând fracția din fiecare obiect luată. Aceasta indică procentul din obiectul respectiv care a fost inclus în rucsac, în cazul în care nu întreaga greutate a fost luată.

*/
