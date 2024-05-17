#include <iostream>  // Biblioteca pentru intrare si iesire
#include <vector>    // Biblioteca pentru vectori
#include <queue>     // Biblioteca pentru cozi
#include <algorithm> // Biblioteca pentru functii de algoritmi

using namespace std; // Folosim spatiul de nume standard

// Structura pentru a reprezenta un obiect cu valoare, greutate si raport valoare/greutate
struct Obiect {
    int valoare, greutate;
    double valoare_pe_greutate;
};

// Structura pentru a reprezenta un nod in arborele de cautare
struct Nod {
    int nivel, profit, greutate;
    double limita_superioara;
};

// Functie de comparare pentru sortarea obiectelor dupa raportul valoare/greutate
bool compara(Obiect a, Obiect b) {
    return a.valoare_pe_greutate > b.valoare_pe_greutate;
}

// Functie pentru calcularea limitei superioare (UB = T - N)
double calculeaza_limita(Nod nod, int n, int capacitate, const vector<Obiect>& obiecte) {
    // Daca greutatea nodului depaseste capacitatea, limita este 0
    if (nod.greutate >= capacitate) {
        return 0;
    }

    // Calculam suma valorilor tuturor obiectelor (T)
    int T = 0;
    for (const auto& obiect : obiecte) {
        T += obiect.valoare;
    }

    // Calculam suma valorilor obiectelor care nu au fost luate (N)
    int N = 0;
    int greutate_acumulata = nod.greutate;
    for (int i = nod.nivel; i < n; ++i) {
        if (greutate_acumulata + obiecte[i].greutate <= capacitate) {
            greutate_acumulata += obiecte[i].greutate;
        } else {
            N += obiecte[i].valoare;
        }
    }

    // Limita superioara (UB) este T - N
    double UB = T - N;
    return UB;
}

// Functie pentru rezolvarea problemei rucsacului folosind Branch and Bound
int rucsac_branch_and_bound(vector<int> valori, vector<int> greutati, int capacitate) {
    int n = valori.size(); // Numarul de obiecte
    vector<Obiect> obiecte(n);

    // Cream vectorul de obiecte cu valorile si greutatile date
    for (int i = 0; i < n; ++i) {
        obiecte[i] = { valori[i], greutati[i], (double)valori[i] / greutati[i] };
    }

    // Sortam obiectele dupa raportul valoare/greutate
    sort(obiecte.begin(), obiecte.end(), compara);

    // Coada pentru nodurile din arborele de cautare
    queue<Nod> coada;
    Nod radacina = { 0, 0, 0, 0.0 };
    radacina.limita_superioara = calculeaza_limita(radacina, n, capacitate, obiecte);
    coada.push(radacina);

    int profit_maxim = 0;

    // Cautarea in arbore folosind Branch and Bound
    while (!coada.empty()) {
        Nod nod = coada.front();
        coada.pop();

        if (nod.nivel < n) {
            // Nod cu obiectul inclus
            Nod cu_obiect = { nod.nivel + 1, nod.profit + obiecte[nod.nivel].valoare,
                             nod.greutate + obiecte[nod.nivel].greutate, 0.0 };

            if (cu_obiect.greutate <= capacitate && cu_obiect.profit > profit_maxim) {
                profit_maxim = cu_obiect.profit;
            }

            cu_obiect.limita_superioara = calculeaza_limita(cu_obiect, n, capacitate, obiecte);
            if (cu_obiect.limita_superioara > profit_maxim) {
                coada.push(cu_obiect);
            }

            // Nod fara obiectul inclus
            Nod fara_obiect = { nod.nivel + 1, nod.profit, nod.greutate, 0.0 };
            fara_obiect.limita_superioara = calculeaza_limita(fara_obiect, n, capacitate, obiecte);
            if (fara_obiect.limita_superioara > profit_maxim) {
                coada.push(fara_obiect);
            }
        }
    }

    return profit_maxim; // Returnam profitul maxim obtinut
}

int main() {
    int numar_obiecte, capacitate;

    // Cerem utilizatorului sa introduca numarul de obiecte
    cout << "Introdu numarul de obiecte: ";
    cin >> numar_obiecte;

    // Cerem utilizatorului sa introduca capacitatea rucsacului
    cout << "Introdu capacitatea rucsacului: ";
    cin >> capacitate;

    vector<int> valori(numar_obiecte);
    vector<int> greutati(numar_obiecte);

    // Cerem utilizatorului sa introduca valorile si greutatile obiectelor
    cout << "Introdu valorile si greutatile obiectelor:" << endl;
    for (int i = 0; i < numar_obiecte; ++i) {
        cout << "Valoare obiect " << i + 1 << ": ";
        cin >> valori[i];
        cout << "Greutate obiect " << i + 1 << ": ";
        cin >> greutati[i];
    }

    // Calculam si afisam profitul maxim folosind Branch and Bound
    cout << "Profit maxim: " << rucsac_branch_and_bound(valori, greutati, capacitate) << endl;
    return 0;
}

